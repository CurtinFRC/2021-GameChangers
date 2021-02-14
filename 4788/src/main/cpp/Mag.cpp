#include "Mag.h"

Mag::Mag(wml::TalonSrx &magMotor) : _magMotor(magMotor) {}

void Mag::setMag(const MagState st, double power) {
	_magState = st;
	_power = power;
}

void Mag::updateMag(double dt) {
	setPower = _power;

	_magMotor.Set(setPower);
}

void Mag::update(double dt) {
	updateMag(dt);
}