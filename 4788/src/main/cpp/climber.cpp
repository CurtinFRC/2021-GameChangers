#include "Climber.h"
#include <iostream>

using namespace wml;
using namespace wml::controllers;

Climber::Climber(SmartControllerGroup &contGroup,
								TalonSrx &ClimberMotor) :

								_contGroup(contGroup),
								_ClimberMotor(ClimberMotor) {
}

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