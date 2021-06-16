#include "Climber.h"

Climber::Climber(wml::VictorSpx &climberMotor) : _climberMotor(climberMotor) {}

void Climber::setClimber(const ClimberStates cs, double power) {
	_climberStates = cs;
	_power = power;
}

void Climber::updateClimber(double dt) {

	double setPower = 0;

	switch (_climberStates) {
			case ClimberStates::DOWN:
				setPower = 0;
				break;
			case ClimberStates::UP:
				setPower = _power;
				break;
	}

	_climberMotor.Set(setPower);
}

void Climber::update(double dt) {
	updateClimber(dt);
}