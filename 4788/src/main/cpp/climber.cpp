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
}