#include <iostream>

#include "Turret.h"

using namespace frc;
using namespace wml;

Turret::Turret(Gearbox &Rotation, Gearbox &VerticalAxis,  Gearbox &FlyWheel, sensors::BinarySensor &RotLimit, sensors::BinarySensor &VertLimit) :
_verticalAxis{VerticalAxis}, 
_vertLimit{VertLimit}, 
_rotationalAxis{Rotation}, 
_rotLimit{RotLimit}, 
_flyWheel{FlyWheel}, 
_verticalState{ SubState::ZEROING }, 
_rotationState{ SubState::ZEROING }, 
_flyWheelState{ SubState::ZEROING } {}

void Turret::onStatePeriodic(double dt) {
	switch(_state) {
		case TurretState::IDLE:
			_rotationState = SubState::IDLE;
			_verticalState = SubState::IDLE;
			_flyWheelState = SubState::IDLE;
			break;
		case TurretState::ARMING:
			if(isReady()) {
				_state = TurretState::READY;
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
				_state = TurretState::IDLE;
			} else {
				_state = TurretState::ZEROING;
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
			double output = pid(_inputV, _verticalGoal, -12, 12, 0, 0, 0, _sumV, _previousErrorV, dt);
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
			double output = pid(_inputR, _rotationGoal*_gearRatio, -12, 12, 0, 0, 0, _sumR, _previousErrorR, dt);
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
			double output = pid(_inputF, _flyWheelGoal, -12, 12, 0, 0, 0, _sumF, _previousErrorF, dt);
			_flyWheel.transmission->SetVoltage(output);
			break;
	}
}

void Turret::flywheel(double goal) {
	goal = mathClamp(-1,1,goal);
	_flyWheelGoal = goal;
	_state = TurretState::ARMING;
}

void Turret::rotate(double goal) {
	goal = mathClamp(0,360,goal);
	goal /= 360;
	_rotationGoal = goal;
	_state = TurretState::ARMING;
}

void Turret::vertical(double goal) {
	goal = mathClamp(0,1,goal);
	_verticalGoal = goal;
	_state = TurretState::ARMING;
}

void Turret::setShooting() {
	_state = TurretState::ARMING;
}

bool Turret::isReady() {
	if(_state == TurretState::READY) {
		return true;
	} else {
		return false;
	}
}
double Turret::pid(double input, double goal, double min, double max, double kP, double kI, double kD, double &sum, double &previousError, double dt) {
  double error = goal - input;
  double derror = (error - previousError) / dt;
  sum = sum + error * dt;

  double output = kP * error + kI * sum + kD * derror;

  previousError = error;

  if(output < min) {
    output = min;
  } else if(output > max) {
    output = max;
  }

  return output;
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
	if(_verticalState == SubState::IDLE && _rotationState == SubState::IDLE && _flyWheelState == SubState::IDLE) {
		return true;
	}
	return false;
}

bool Turret::isPidReady() {
	movingAve(_movingAveV, _aveV, _inputV);
	movingAve(_movingAveR, _aveR, _inputR);
	movingAve(_movingAveF, _aveF, _inputF);
	if(abs(_verticalGoal - _aveV) <= _toleranceV && abs(_rotationGoal - _aveR) <= _toleranceR && abs(_flyWheelGoal - _aveF) <= _toleranceF){
		return true;
	} else {
		return false;
	}
}
void Turret::movingAve(std::array<double, ARRAYSIZE> &aveArray, double &ave, double current) {
	ave -= aveArray[0]/aveArray.size();
	ave += current/aveArray.size();
	for(std::size_t i = 0; i < aveArray.size() - 1; i++) {
		aveArray[i] = aveArray[i+1];
	}
	aveArray[aveArray.size() - 1] = current;
}

/*
void Turret::shooter(double dt, double goal) {
	goal = mathClamp(-1,1,goal);
  double output = pid(_flyWheel.encoder->GetEncoderAngularVelocity(), goal, -12, 12, 0, 0, 0, _sumF, _previousErrorF, dt);
  _flyWheel.transmission->SetVoltage(output);
}

void Turret::rotate(double dt, double goal) {
	goal = mathClamp(-1,1,goal);
  goal *= _gearRatio;
	double rots = _rotationalAxis.encoder->GetEncoderRotations();
  double output = pid(rots, goal, -12, 12, 0, 0, 0, _sumR, _previousErrorR, dt);
	if (rots < 0 || rots > _gearRatio) {
		_rotationalAxis.transmission->SetVoltage(0);
	} else {
		_rotationalAxis.transmission->SetVoltage(output);
	}
}

void Turret::vertical(double dt, double goal) {
	goal = mathClamp(-1,1,goal);
	double rots = _verticalAxis.encoder->GetEncoderRotations();
  double output = pid(rots, goal, -12, 12, 0, 0, 0, _sumV, _previousErrorV, dt);
	if (rots < 0 || rots > 0 ) {
		_verticalAxis.transmission->SetVoltage(0);
	} else {
		_verticalAxis.transmission->SetVoltage(output);
	}
}
*/
