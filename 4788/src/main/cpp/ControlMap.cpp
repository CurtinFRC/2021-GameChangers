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
const int ControlMap::FLport = 99;
const int ControlMap::BLport = 2;

// Right Drive
const int ControlMap::FRport = 99;
const int ControlMap::BRport = 5;

// Drivetrain speed
const double ControlMap::MaxDrivetrainSpeed = 0.6;

// Robot Values
const double ControlMap::TrackWidth = 0.56;
const double ControlMap::TrackDepth = 0.60;
const double ControlMap::WheelRadius = 0.0762; // In meters
const double ControlMap::Mass = 50; // KG's

//intake 
const int ControlMap::IntakePort = 99;
const double ControlMap::IntakeSpeed = 0.5; //speed of the intake, both in and out

// ------------------ Values ------------------
const tAxis ControlMap::DrivetrainLeft{ Driver, XboxController::kLeftYAxis };
const tAxis ControlMap::DrivetrainRight{ Driver, XboxController::kRightYAxis };

//intake
const tButton ControlMap::Intake{ CoDriver, XboxController::kX };
const tButton ControlMap::Outake{ CoDriver, XboxController::kB };