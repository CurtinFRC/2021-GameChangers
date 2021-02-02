#include <iostream>

#include "Turret.h"

using namespace frc;
using namespace wml;

//if these are private variables that are only used in the turret.cpp reeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
Turret::Turret(Gearbox &Rotation, Gearbox &VerticalAxis,  Gearbox &FlyWheel, sensors::BinarySensor &RotLimit, sensors::BinarySensor &VertLimit) :
_RotationalAxis{Rotation}, _VerticalAxis{VerticalAxis}, _FlyWheel{FlyWheel}, _rotLimit{RotLimit}, _vertLimit{VertLimit}, _previousErrorS{0},
_previousErrorR{0}, _previousErrorV{0}, _sumS{0}, _sumR{0}, _sumV{0}, _init{true}, _gearRatio{196}, _initState{TurretInit::ROT}, _state{TurretState::ZEROING} {
	
	//why is this in your constructor reeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
	// while (_init) {
	// 	switch (_initState) {
	// 	case TurretInit::ROT:
	// 		if (_rotLimit.Get() == true) {
	// 			_RotationalAxis.transmission->SetVoltage(0);
	// 			_RotationalAxis.encoder->ZeroEncoder();
	// 			_initState = TurretInit::VERT;
	// 		} else {
	// 			_RotationalAxis.transmission->SetVoltage(2);
	// 		}
	// 		break;
		
	// 	case TurretInit::VERT:
	// 		if (_vertLimit.Get() == true) {
	// 			_VerticalAxis.transmission->SetVoltage(0);
	// 			_VerticalAxis.encoder->ZeroEncoder();
	// 			_init = false;
	// 		} else {
	// 			_VerticalAxis.transmission->SetVoltage(2);
	// 		}
	// 		break;
	// 	}
	// }
}

/* In a strategy 
Turret::SetShooting( );
if (Turret::Ready())
	Magazine::Feed();

void Turret::OnStatePeriodic(...) {
	switch(state) {
		// Manual
		case TurretState::IDLE:
			// _RotationalAxis.transmission->SetVoltage(0);
			_rotationState = IDLE;
			_hoodState = IDLE;
			_flyWheel = IDLE;
			break;
		case TurretState::SHOOT:
			if ( all PIDS done )
				SetState(TurretState::READY);
		case TurretState::READY:
			_rotationState = PID;
			_hoodState = PID;
			_flywheelState = PID;
			break;
		case TurretState::ZEROING:
			_rotationState = ZEROING;
			_hoodState = ZEROING;
			if ( all states IDLE )
				SetState(IDLE);
			break;
	}
	HoodPeriodic(dt);
	FlywheelPeriodic(dt);
	RotationPeriodic(dt);
}

void Turret::HoodPeriodic(double dt) {
	switch(_hoodState) {
		case IDLE:
			break;
		case ZEROING:
			break;
		case PID:

			break;
	}
}
*/

/*
void Turret::SetShooting(double hood, double flywheelSpeed, double rotation) {
	---
}
*/

void Turret::shooter(double dt, double goal) {
	goal = mathClamp(-1,1,goal);
  double output = pid(_FlyWheel.encoder->GetEncoderAngularVelocity(), goal, -12, 12, 0, 0, 0, _sumS, _previousErrorS, dt);
  _FlyWheel.transmission->SetVoltage(output);
}

/*
void Turret::rotate(double goal) {
	_setpoint = goal;
	SetState(TurretState::PID);
}
*/

void Turret::rotate(double dt, double goal) {
	goal = mathClamp(-1,1,goal);
  goal *= _gearRatio;
	double rots = _RotationalAxis.encoder->GetEncoderRotations();
  double output = pid(rots, goal, -12, 12, 0, 0, 0, _sumR, _previousErrorR, dt);
	if (rots < 0 || rots > _gearRatio) {
		_RotationalAxis.transmission->SetVoltage(0);
	} else {
		_RotationalAxis.transmission->SetVoltage(output);
	}
}

void Turret::vertical(double dt, double goal) {
	goal = mathClamp(-1,1,goal);
	double rots = _VerticalAxis.encoder->GetEncoderRotations();
  double output = pid(rots, goal, -12, 12, 0, 0, 0, _sumV, _previousErrorV, dt);
	if (rots < 0 || rots > 0 /*tmp*/) {
		_VerticalAxis.transmission->SetVoltage(0);
	} else {
		_VerticalAxis.transmission->SetVoltage(output);
	}
}

double Turret::pid(double input, double goal, double min, double max, double kP, double kI, double kD, double &sum, double &previousError, double dt){
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
	} else if(input > max){
		return max;
	} else {
		return input;
	}
}