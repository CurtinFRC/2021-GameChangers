#include "Climber.h"

Climber::Climber(wml::TalonSrx &climberMotor) : _climberMotor(climberMotor) {}

void Climber::setClimber(const ClimberState st, double power) {
	_climberState = st;
	_power = power;
}

void Climber::updateClimber(double dt) {
	setPower = _power;
	_climberMotor.Set(setPower);
}

void Climber::update(double dt) {
	updateClimber(dt);
}