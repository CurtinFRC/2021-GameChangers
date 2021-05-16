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

// Left Drive
const int ControlMap::FLport = 1;
const int ControlMap::BLport = 2;

//Right drive 
const int ControlMap::FRport = 3;
const int ControlMap::BRport = 4;

// Drivetrain speed
const double ControlMap::MaxDrivetrainSpeed = 1;

// Robot Values
const double ControlMap::TrackWidth = 0.56;
const double ControlMap::TrackDepth = 0.60;
const double ControlMap::WheelRadius = 0.0762; // In meters
const double ControlMap::Mass = 50; // KG's

//intake 
const int ControlMap::IntakePort = 5;

//mag
const int ControlMap::MagMotorPort = 6;

const double ControlMap::MagMaxSpeed = 0.7;

//shooter
const int ControlMap::FWPort = 8; //flywheel
const int ControlMap::FPort = 7; //fire 

double ControlMap::FlyWheelMaxSpeed = 1;
const double ControlMap::FireSpeed = 0.5;
const double ControlMap::ReverseFireSpeed = -0.5;

const int ControlMap::ClimberPort = 9;



// ------------------ Values ------------------
const tAxis ControlMap::DrivetrainLeft{ Driver, XboxController::kLeftYAxis };
const tAxis ControlMap::DrivetrainRight{ Driver, XboxController::kRightYAxis };

//intake
const tAxis ControlMap::Intake{ CoDriver, XboxController::kLeftThrottle };
const tButton ControlMap::Outake{CoDriver, XboxController::kX };

//Mag
const tAxis ControlMap::MagTurn{ CoDriver, XboxController::kRightXAxis};

//shooter 
const tButton ControlMap::FireButton{ CoDriver, XboxController::kBumperRight };
const tButton ControlMap::ReverseFire{ CoDriver, XboxController::kY };

const tAxis ControlMap::SpinUp{ CoDriver, XboxController::kRightThrottle }; //flywheel spinup

//climber
const tAxis ControlMap::ClimberPower{ CoDriver, XboxController::kLeftYAxis};
const tButton ControlMap::ClimberActuation{ CoDriver, XboxController::kB};