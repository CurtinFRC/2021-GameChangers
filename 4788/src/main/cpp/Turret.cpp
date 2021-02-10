#include <iostream>

#include "Turret.h"

#include "Usage.h"

using namespace frc;
using namespace wml;

Turret::Turret(Gearbox &Rotation, Gearbox &VerticalAxis,  Gearbox &FlyWheel, sensors::BinarySensor &RotLimit, sensors::BinarySensor &VertLimit) :
StateDevice("<Turret>"),
_verticalAxis{VerticalAxis}, 
_vertLimit{VertLimit}, 
_rotationalAxis{Rotation}, 
_rotLimit{RotLimit}, 
_flyWheel{FlyWheel}, 
_verticalState{ SubState::ZEROING }, 
_rotationState{ SubState::ZEROING }, 
_flyWheelState{ SubState::ZEROING }{}

void Turret::OnStatePeriodic(TurretState state, double dt) {
	switch(GetState()) {
		case TurretState::IDLE:
			_rotationState = SubState::IDLE;
			_verticalState = SubState::IDLE;
			_flyWheelState = SubState::IDLE;
			break;
		case TurretState::ARMING:
			if(isReady()) {
				SetState(TurretState::READY);
			}
		case TurretState::READY:
			_rotationState = SubState::PID;
			_verticalState = SubState::PID;
			_flyWheelState = SubState::PID;
			break;
		case TurretState::ZERO:
			_rotationState = SubState::ZEROING;
			_verticalState = SubState::ZEROING;
			_flyWheelState = SubState::ZEROING;
		case TurretState::ZEROING:
			if (allIdle()) {
				SetState(TurretState::IDLE);
			} else {
				SetState(TurretState::ZEROING);
			}
			break;
	}
	verticalPeriodic(dt);
	rotationPeriodic(dt);
	flywheelPeriodic(dt);
}

void Turret::verticalPeriodic(double dt) {
	switch(_verticalState) {
		case SubState::IDLE:
			_verticalAxis.transmission->SetVoltage(0);
			break;
		case SubState::ZEROING:
			if(_vertLimit.Get() == false) {
				_verticalAxis.transmission->SetVoltage(2);
			} else {
				_verticalAxis.transmission->SetVoltage(0);
				_verticalAxis.encoder->ZeroEncoder();
				_verticalState = SubState::IDLE;
			}
			break;
		case SubState::PID:
			_inputV = _verticalAxis.encoder->GetEncoderRotations();
			double output = PIDcont::Calc(_inputV, _verticalGoal, ControlMap::VoltageMin, ControlMap::VoltageMax, ControlMap::VerticalAxisP, ControlMap::VerticalAxisI, ControlMap::VerticalAxisD, _sumV, _previousErrorV, dt);
			_verticalAxis.transmission->SetVoltage(output);
			break;
	}
}

void Turret::rotationPeriodic(double dt) {
	switch(_rotationState) {
		case SubState::IDLE:
			_rotationalAxis.transmission->SetVoltage(0);
			break;
		case SubState::ZEROING:
			if(_rotLimit.Get() == false) {
				_rotationalAxis.transmission->SetVoltage(2);
			} else {
				_rotationalAxis.transmission->SetVoltage(0);
				_rotationalAxis.encoder->ZeroEncoder();
				_rotationState = SubState::IDLE;
			}
			break;
		case SubState::PID:
			_inputR = _rotationalAxis.encoder->GetEncoderRotations();
			double output = PIDcont::Calc(_inputR, _rotationGoal, ControlMap::VoltageMin, ControlMap::VoltageMax, ControlMap::RotationalAxisP, ControlMap::RotationalAxisI, ControlMap::RotationalAxisD, _sumR, _previousErrorR, dt);
			_rotationalAxis.transmission->SetVoltage(output);
			break;
	}
}

void Turret::flywheelPeriodic(double dt) {
	switch(_flyWheelState) {
		case SubState::IDLE:
			_flyWheel.transmission->SetVoltage(0);
			break;
		case SubState::ZEROING:
			_flyWheelState = SubState::IDLE;
			break;
		case SubState::PID:
			_inputF = _flyWheel.encoder->GetEncoderAngularVelocity();
			double output = PIDcont::Calc(_inputF, _flyWheelGoal, ControlMap::VoltageMin, ControlMap::VoltageMax, ControlMap::FlywheelP, ControlMap::FlywheelI, ControlMap::FlywheelD, _sumF, _previousErrorF, dt);
			_flyWheel.transmission->SetVoltage(output);
			break;
	}
}

void Turret::flywheel(double goal) {
	goal = mathClamp(ControlMap::FlywheelMin, ControlMap::FlywheelMax, goal);
	_flyWheelGoal = goal;
	SetState(TurretState::ARMING);
}

void Turret::rotate(double goal) {
	goal = mathClamp(ControlMap::RotationalAxisMin, ControlMap::RotationalAxisMax, goal);
	goal /= ControlMap::RotationalAxisDeg;
	_rotationGoal = goal;
	SetState(TurretState::ARMING);
}

void Turret::vertical(double goal) {
	goal = mathClamp(ControlMap::VerticalAxisMin, ControlMap::VerticalAxisMin, goal);
	_verticalGoal = goal;
	SetState(TurretState::ARMING);
}

void Turret::setShooting() {
	SetState(TurretState::ARMING);
}

bool Turret::isReady() {
	return GetState() == TurretState::READY;
}

std::string Turret::GetStateString() {
	switch (GetState()) {
		case TurretState::ZERO:
		return "Zero";

		case TurretState::ZEROING:
		return "Zeroing";

		case TurretState::ARMING:
		return "Arming";
    
		case TurretState::READY:
		return "Ready";
    
		case TurretState::IDLE:
		return "Idle";
	}
  return "<state error>";
}

double Turret::mathClamp(const double min, const double max, const double input) {
	if(input < min){
		return min;
	} else if(input > max) {
		return max;
	} else {
		return input;
	}
}

bool Turret::allIdle() {
	return (_verticalState == SubState::IDLE && _rotationState == SubState::IDLE && _flyWheelState == SubState::IDLE);
}

bool Turret::isPidReady() {
	MovingAv::Calc(_movingAveV, _aveV, _inputV);
	MovingAv::Calc(_movingAveR, _aveR, _inputR);
	MovingAv::Calc(_movingAveF, _aveF, _inputF);
	return(abs(_verticalGoal - _aveV) <= _toleranceV && abs(_rotationGoal - _aveR) <= _toleranceR && abs(_flyWheelGoal - _aveF) <= _toleranceF);
}