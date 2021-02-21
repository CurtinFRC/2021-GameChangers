#include "Climber.h"
#include <iostream>

using namespace wml;
using namespace wml::controllers;

Climber::Climber(TalonSrx &ClimberMotor) : _climberMotor(ClimberMotor) {}

int Climber::climberEncoderValue() {
	return(_climberMotor.GetEncoderTicks());
}


void Climber::setClimber(const ClimberState st, double power) {
	_climberState = st;
	_power = power;
}

void Climber::updateClimber (double dt) {
	double speed = 0;

	switch (_climberState) {
		case ClimberState::ENABLED:
			speed = _power;
			break;
		case ClimberState::DISABLED:
			speed = 0;
			break;
		case ClimberState::EXTENDING:
			speed = 0.5;
			break;
		case ClimberState::JAMMED:
			speed = 0;
			break;
	}

	_climberMotor.Set(speed);
}

void Climber::update (double dt) {
	updateClimber(dt);
}


/*
void Climber::TeleopOnUpdate(double dt) {

	// If button is pressed pull on the string to raise climber
	if(_contGroup.Get(ControlMap::ClimberUp, Controller::ONRISE)) {
		_ClimberMotor.Set(ControlMap::ClimberSpeed);

	// If button is pressed release the string to lower climber
	} else if (_contGroup.Get(ControlMap::ClimberDown, Controller::ONRISE)) {
		_ClimberMotor.Set(-ControlMap::ClimberSpeed);

	// If no button is pressed stop
	} else {
		_ClimberMotor.Set(0);
	}
}
*/