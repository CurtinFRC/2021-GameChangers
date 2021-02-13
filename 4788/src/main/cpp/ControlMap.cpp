#include "ControlMap.h"

using namespace wml;
using namespace wml::controllers;

void ControlMap::InitsmartControllerGroup(SmartControllerGroup &contGroup) {
	// Remap Here (map POV buttons to names etc)
}


// ------------------ Values ------------------


// Controller Ports
const int ControlMap::Xbox1Port = 0;
const int ControlMap::Xbox2Port = 1;

// Deadzones
const double ControlMap::XboxDeadzone = 0.1;
const double ControlMap::TriggerDeadzone = 0.15;

// PCMs
const int ControlMap::PCModule = 1;

// Intake
const int ControlMap::intakePort = 3;

// Climber
const int ControlMap::climberPort = 6;
bool ControlMap::ClimberToggle = true;

// Falcon
const int ControlMap::falconPort = 99;



// ------------------ Controls ------------------

//climber
const tAxis ControlMap::ClimberUp{ CoDriver, XboxController::kRightThrottle };
const tAxis ControlMap::ClimberDown{ CoDriver, XboxController::kLeftThrottle };
const tButton ControlMap::DeployClimber{ CoDriver, XboxController::kA};

//intake 
const tAxis ControlMap::Intake{ CoDriver, XboxController::kLeftThrottle};
const tButton ControlMap::Outake{ CoDriver, XboxController::kB};