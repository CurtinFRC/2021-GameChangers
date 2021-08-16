#include "Shooter.h"

Shooter::Shooter(wml::VictorSpx &flyWheelMotor, wml::VictorSpx &fireMotor) : _flyWheelMotor(flyWheelMotor), _fireMotor(fireMotor) {}

void Shooter::setFlywheel(double power) {
	_flywheelPower = power;
}

void Shooter::setFire(double power) {
	_firePower = power;
}

void Shooter::updateShooter(double dt) {
	double setFlyPower = 0;
	double setFirePower = 0;

	setFlyPower = _flywheelPower;
	setFirePower = _firePower;

	_flyWheelMotor.Set(setFlyPower);
	_fireMotor.Set(setFirePower);
}

void Shooter::update(double dt) {
	updateShooter(dt);
}