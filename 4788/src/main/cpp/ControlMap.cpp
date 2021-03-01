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
const int ControlMap::Lport = 2;
const int ControlMap::Rport = 4;

// Drivetrain speed
const double ControlMap::MaxDrivetrainSpeed = 1;

// Robot Values
const double ControlMap::TrackWidth = 0.56;
const double ControlMap::TrackDepth = 0.60;
const double ControlMap::WheelRadius = 0.0762; // In meters
const double ControlMap::Mass = 50; // KG's

//intake 
const int ControlMap::IntakePort = 99;
const int ControlMap::IntakeSolenoidPort1 = 99;
const int ControlMap::IntakeSolenoidPort2 = 99;

//mag
const int ControlMap::MagMotorPort = 99;
bool ControlMap::MagToggle = false;

const double ControlMap::MagSpeed = 1;
const double ControlMap::ReverseMagSpeed = -0.5;

// ------------------ Values ------------------
const tAxis ControlMap::DrivetrainLeft{ Driver, XboxController::kLeftYAxis };
const tAxis ControlMap::DrivetrainRight{ Driver, XboxController::kRightYAxis };

//intake
const tButton ControlMap::IntakeActuation{ CoDriver, XboxController::kY };
const tAxis ControlMap::Intake{ CoDriver, XboxController::kLeftThrottle };
const tPOV ControlMap::Outake{CoDriver, XboxController::kLeft};

//Mag
const tButton ControlMap::MagToggleButton{ CoDriver, XboxController::kA };
const tPOV ControlMap::MagReverse{ CoDriver, XboxController::kBottom };

//turret

//shooter 