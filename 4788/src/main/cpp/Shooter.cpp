#include "Shooter.h"

Shooter::Shooter(wml::VictorSpx &shooterMotor, wml::VictorSpx &fireMotor) : _shooterMotor(shooterMotor), _fireMotor(fireMotor) {}

void Shooter::setShooter(const ShooterState st, double power) {
	_shooterState = st;
	_power = power;
}

void Shooter::setFire(const ShooterState st, double power) {
	_firePower = power;
}

void Shooter::updateShooter(double dt) {
	setPower = _power;
	firePower = _firePower;

	_fireMotor.Set(firePower);
	_shooterMotor.Set(setPower);
}

void Shooter::update(double dt) {
	updateShooter(dt);
}