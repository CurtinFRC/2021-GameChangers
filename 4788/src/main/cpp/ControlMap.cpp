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

// Left Drive
const int ControlMap::FLport = 2;
const int ControlMap::BLport = 99;

// Right Drive
const int ControlMap::FRport = 5;
const int ControlMap::BRport = 99;

// Drivetrain speed
const double ControlMap::MaxDrivetrainSpeed = 0.8;

// Robot Values
const double ControlMap::TrackWidth = 0.56;
const double ControlMap::TrackDepth = 0.60;
const double ControlMap::WheelRadius = 0.0762; // In meters
const double ControlMap::Mass = 50; // KG's

// Intake
const int ControlMap::intakePort = 3;

// Climber
const int ControlMap::climberPort = 6;
bool ControlMap::ClimberToggle = true;

//shooter
const int ControlMap::shooterPort = 4;
const int ControlMap::firePort = 8;
const double ControlMap::fireSpeed = 1; 





// ------------------ Controls ------------------

//climber
const tAxis ControlMap::ClimberUp{ CoDriver, XboxController::kRightThrottle };
const tAxis ControlMap::ClimberDown{ CoDriver, XboxController::kLeftThrottle };
const tButton ControlMap::DeployClimber{ CoDriver, XboxController::kA};

//intake 
const tAxis ControlMap::Intake{ CoDriver, XboxController::kLeftThrottle};
const tButton ControlMap::Outake{ CoDriver, XboxController::kB};

//drive
const tAxis ControlMap::DrivetrainLeft{ Driver, XboxController::kLeftYAxis };
const tAxis ControlMap::DrivetrainRight{ Driver, XboxController::kRightYAxis };

//shooter 
const tAxis ControlMap::FlywheelSpinUp{ CoDriver, XboxController::kRightThrottle };
const tButton ControlMap::FireShooter{ CoDriver, XboxController::kY };