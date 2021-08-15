#include "Mag.h"

Mag::Mag(wml::TalonSrx &magMotor) : _magMotor(magMotor) {}

void Mag::setMag(const MagStates st, double power) {
	_magState = st;
	_power = power;
}

void Mag::updateMag(double dt) {
	double setPower = 0;

	switch (_magState) {
		case MagStates::OFF:
			setPower = 0;
			break;
		case MagStates::ON:
			_power *= ControlMap::MagMaxSpeed;
			setPower = _power;
			break;
		case MagStates::REVERSE:
			setPower = 0;
			break;
	}
	_magMotor.Set(setPower);
}

void Mag::update(double dt) {
	updateMag(dt);
}