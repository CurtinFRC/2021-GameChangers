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
	if(_contGroup.Get(ControlMap::ClimberUp, Controller::ONFALL)) {
		_ClimberMotor.set(0.7);
	} else if (_contGroup.Get(ControlMap::ClimberDown, Controller::ONFALL)) {
		_ClimberMotor.set(-0.7);
	} else {
		_ClimberMotor.set(0);
	}
}