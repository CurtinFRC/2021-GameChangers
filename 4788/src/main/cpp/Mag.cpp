#include "Mag.h"

Mag::Mag(wml::TalonSrx &magMotor) : _magMotor(magMotor) {}

void Mag::setMag(const MagState st, double power) {
	_magState = st;
	_power = power;
}

void Mag::updateMag(double dt) {

}

void Mag::update(double dt) {
	updateMag(dt);
}