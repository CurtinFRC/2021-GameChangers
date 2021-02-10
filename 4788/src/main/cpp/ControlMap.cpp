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

// Right Drive
const int ControlMap::FRport = 10;
const int ControlMap::BRport = 11;

// Drivetrain speed
const double ControlMap::MaxDrivetrainSpeed = 0.8;

// Robot Values
const double ControlMap::TrackWidth = 0.56;
const double ControlMap::TrackDepth = 0.60;
const double ControlMap::WheelRadius = 0.0762; // In meters
const double ControlMap::Mass = 50; // KG's

// Turret
const int ControlMap::TurretRotPort = 99;
const int ControlMap::TurretVertPort = 99;
const int ControlMap::TurretFlyPort = 99;
const int ControlMap::RotLimitPort = 99;
const int ControlMap::VertLimitPort = 99;
const bool ControlMap::RotLimitInvert = false;
const bool ControlMap::VertLimitInvert = false;

const double ControlMap::VerticalAxisMin = 0;
const double ControlMap::VerticalAxisMax = 1;
const double ControlMap::VerticalAxisP = 0;
const double ControlMap::VerticalAxisI = 0;
const double ControlMap::VerticalAxisD = 0;
const double ControlMap::RotationalAxisMin = 0;
const double ControlMap::RotationalAxisMax = 300;
const double ControlMap::RotationalAxisP = 0;
const double ControlMap::RotationalAxisI = 0;
const double ControlMap::RotationalAxisD = 0;
const double ControlMap::RotationalAxisDeg = 300;
const double ControlMap::FlywheelP = 0;
const double ControlMap::FlywheelI = 0;
const double ControlMap::FlywheelD = 0;
const double ControlMap::FlywheelMin = -1;
const double ControlMap::FlywheelMax = 1;
const double ControlMap::VoltageMin = -12;
const double ControlMap::VoltageMax = 12;

// ------------------ Values ------------------
const tAxis ControlMap::DrivetrainLeft{ Driver, XboxController::kLeftYAxis };
const tAxis ControlMap::DrivetrainRight{ Driver, XboxController::kRightYAxis };

const tAxis ControlMap::VertStick{ CoDriver, XboxController::kLeftYAxis };
const tAxis ControlMap::RotStick{ CoDriver, XboxController::kRightXAxis };
const tAxis ControlMap::ShootTrig{ CoDriver, XboxController::kRightThrottle };