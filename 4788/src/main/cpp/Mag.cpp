#include "Mag.h"

Mag::Mag(wml::TalonSrx &magMotor) : _magMotor(magMotor) {}

void Mag::setMag(const MagStates st) {
	_magState = st;
}

void Mag::updateMag(double dt) {
	double setPower = 0;

	switch (_magState) {
		case MagStates::OFF:
			setPower = 0;
			break;
		case MagStates::ON:
			setPower = ControlMap::MagSpeed;
			break;
		case MagStates::REVERSE:
			setPower = ControlMap::ReverseMagSpeed;
			break;
	}

	_magMotor.Set(setPower);
}

void Mag::update(double dt) {
	updateMag(dt);
}