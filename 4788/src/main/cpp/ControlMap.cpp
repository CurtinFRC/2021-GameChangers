#include "ControlMap.h"

using namespace wml;
using namespace wml::controllers;

void ControlMap::InitsmartControllerGroup(SmartControllerGroup &contGroup) {
	// Remap Here (map POV buttons to names etc)
  // contGroup.GetController(ControlMap::TurretAutoAimAxis.cont).Map(ControlMap::TurretAutoAimAxis, ControlMap::TurretAutoAim, ControlMap::triggerDeadzone);

  contGroup.GetController(ControlMap::ShiftMagazinePOV.cont).Map(ControlMap::ShiftMagazinePOV, {
    { Controller::POVPos::kLeft, ControlMap::MagLeft },
    { Controller::POVPos::kRight, ControlMap::MagRight }
  });
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
const int ControlMap::BLport = 99; // not using 

// Magazine
const int ControlMap::MagMotorPort1 = 1;
const int ControlMap::MagMotorPort2 = 8;
const bool ControlMap::MagOutakeToggle = false;
const bool ControlMap::MagReverseToggle = false;
// const double ControlMap::MagEncoderSafeZone = 5;

// Right Drive
const int ControlMap::FRport = 6;
const int ControlMap::BRport = 99; // not using

// Drivetrain speed
const double ControlMap::MaxDrivetrainSpeed = 0.8;

// Robot Values
const double ControlMap::TrackWidth = 0.56;
const double ControlMap::TrackDepth = 0.60;
const double ControlMap::WheelRadius = 0.0762; // In meters
const double ControlMap::Mass = 50; // KG's

// ------------------ Control ------------------
const tAxis ControlMap::DrivetrainLeft{ Driver, XboxController::kLeftYAxis };
const tAxis ControlMap::DrivetrainRight{ Driver, XboxController::kRightYAxis };

// Washing Machine Magazine
// const tAxis ControlMap::Outake{ CoDriver, XboxController::kRightThrottle };
const tPOV ControlMap::ShiftMagazinePOV{ CoDriver, 0 };
const tButton ControlMap::MagLeft{ CoDriver, __LINE__ + 30 };
const tButton ControlMap::MagRight{ CoDriver, __LINE__ + 30 };
// const tPOV ControlMap::MagReverse{ CoDriver, XboxController::kLeft };
// const tPOV ControlMap::Outake{ CoDriver, XboxController::kRight };

