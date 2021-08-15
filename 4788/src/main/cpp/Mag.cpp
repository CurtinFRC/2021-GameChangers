#include "Mag.h"

Mag::Mag(wml::TalonSrx &magMotor) : _magMotor(magMotor) {}

<<<<<<< HEAD
void Mag::setMag(const MagStates st, double power) {
=======
void Mag::setMag(const MagState st, double power) {
>>>>>>> 7a319f36c2adba576e52e65f7b02fbb0931601ba
	_magState = st;
	_power = power;
}

void Mag::updateMag(double dt) {
<<<<<<< HEAD
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
=======
	setPower = _power;
>>>>>>> 7a319f36c2adba576e52e65f7b02fbb0931601ba

	_magMotor.Set(setPower);
}

void Mag::update(double dt) {
	updateMag(dt);
}