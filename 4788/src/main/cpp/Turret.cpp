#include <iostream>

#include "Turret.h"

using namespace frc;
using namespace wml;

Turret::Turret(Gearbox &Rotation, Gearbox &VerticalAxis,  Gearbox &FlyWheel, sensors::BinarySensor &RotLimit, sensors::BinarySensor &VertLimit) :
_rotationalAxis{Rotation}, 
_verticalAxis{VerticalAxis}, 
_flyWheel{FlyWheel}, 
_rotLimit{RotLimit}, 
_vertLimit{VertLimit}, 
_previousErrorS{0}, 
_previousErrorR{0}, 
_previousErrorV{0}, 
_sumS{0}, 
_sumR{0}, 
_sumV{0}, 
_flyWheelGoal{0}, 
_rotationGoal{0}, 
_verticalGoal{0}, 
_rotationState{ SubState::ZEROING }, 
_verticalState{ SubState::ZEROING }, 
_flyWheelState{ SubState::ZEROING }, 
_gearRatio{196}, 
_state{TurretState::ZERO}, 
_arraySize{4}, 
//_movingAveV[4]{0,0,0,0}, 
//_movingAveR[4]{0,0,0,0}, 
//_movingAveS[4]{0,0,0,0}, 
_aveV{0}, 
_aveR{0}, 
_aveS{0}, 
_inputV{0}, 
_inputR{0}, 
_inputS{0} {}

void Turret::init(){
	/*
	for (int i = 0; i < _arraySize; i++)
	{
		_movingAveV[i] = 0;
		_movingAveR[i] = 0;
		_movingAveS[i] = 0;
	}
	*/
}

void Turret::onStatePeriodic(double dt) {
	switch(_state) {
		case TurretState::IDLE:
			//_rotationState{ SubState::IDLE };
			//_verticalState{ SubState::IDLE };
			//_flyWheelState{ SubState::IDLE };
			break;
		case TurretState::SHOOT:
			if(isReady()) {
				//_state{ TurretState::READY };
			}
		case TurretState::READY:
			//_rotationState{ SubState::PID };
			//_verticalState{ SubState::PID };
			//_flyWheelState{ SubState::PID };
			break;
		case TurretState::ZERO:
			//_rotationState{ SubState::ZEROING };
			//_verticalState{ SubState::ZEROING };
			//_flyWheelState{ SubState::ZEROING };
		case TurretState::ZEROING:
			if (allIdle()) {
				//_state{ TurretState::IDLE };
			} else {
				//_state{ TurretState::ZEROING };
			}
			break;
	}
	//verticalPeriodic(dt);
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
				//_verticalState{ SubState::IDLE };
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
				//_rotationState{ SubState::IDLE };
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
			//_flyWheelState{ SubState::IDLE };
			break;
		case SubState::PID:
			_inputS = _flyWheel.encoder->GetEncoderAngularVelocity();
			double output = pid(_inputS, _flyWheelGoal, -12, 12, 0, 0, 0, _sumS, _previousErrorS, dt);
			_flyWheel.transmission->SetVoltage(output);
			break;
	}
}

void Turret::flywheel(double goal) {
	goal = mathClamp(-1,1,goal);
	_flyWheelGoal = goal;
	//_state{ TurretState::SHOOT };
}

void Turret::rotate(double goal) {
	goal = mathClamp(0,360,goal);
	goal /= 360;
	_rotationGoal = goal;
	//_state{ TurretState::SHOOT };
}

void Turret::vertical(double goal) {
	goal = mathClamp(0,1,goal);
	_verticalGoal = goal;
	//_state{ TurretState::SHOOT };
}

void Turret::setShooting() {
	//_state{ TurretState::SHOOT };
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
	if(_verticalState == SubState::IDLE || _rotationState == SubState::IDLE || _flyWheelState == SubState::IDLE) {
		return true;
	}
	return false;
}

bool Turret::isPidReady() {
	return false;
}

void Turret::movingAve(double &aveArray[], double &ave, double current) {
	ave -= aveArray[0]/4;
	ave += current/4;
}


/*
void Turret::shooter(double dt, double goal) {
	goal = mathClamp(-1,1,goal);
  double output = pid(_flyWheel.encoder->GetEncoderAngularVelocity(), goal, -12, 12, 0, 0, 0, _sumS, _previousErrorS, dt);
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
