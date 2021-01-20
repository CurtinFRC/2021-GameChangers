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
const int ControlMap::FLport = 12;
const int ControlMap::BLport = 13;

// Magazine
const int ControlMap::MagLoaderMotorPort = 99;
const int ControlMap::MagLoaderFunnelMotorPortLeft = 99;
const int ControlMap::MagLoaderFunnelMotorPortRight = 99;
const int ControlMap::StartMagLimitPort = 99;
const int ControlMap::Position1LimitPort = 99;
const int ControlMap::Position5LimitPort = 99;
const double ControlMap::MagazineBallThreshStart = 650;
const double ControlMap::MagazineBallThreshFinal = 1000; 
const double ControlMap::MagazineBallThreshIndex = 2000;

// Right Drive
const int ControlMap::FRport = 10;
const int ControlMap::BRport = 11;

// Drivetrain speed
const double ControlMap::MaxDrivetrainSpeed = 0.8;

// Intake
const int ControlMap::IntakeMotorPort = 24;
const int ControlMap::IntakeDownPort1 = 6;
const int ControlMap::IntakeDownPort2 = 7;

// Robot Values
const double ControlMap::TrackWidth = 0.56;
const double ControlMap::TrackDepth = 0.60;
const double ControlMap::WheelRadius = 0.0762; // In meters
const double ControlMap::Mass = 50; // KG's

// ------------------ Control ------------------
const tAxis ControlMap::DrivetrainLeft{ Driver, XboxController::kLeftYAxis };
const tAxis ControlMap::DrivetrainRight{ Driver, XboxController::kRightYAxis };

// Intake
const tButton ControlMap::DownIntake{ Driver, XboxController::kA };
const double ControlMap::PannelActuationTime = 1;
const tAxis ControlMap::IntakeIn{ Driver, XboxController::kLeftThrottle };
