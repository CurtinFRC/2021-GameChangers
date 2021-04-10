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
const int ControlMap::PCModule = 9;
const int ControlMap::PressureSensorPort = 0;
const int ControlMap::CompressorPort = 0;

// Left Drive
const int ControlMap::Lport = 1;
const int ControlMap::Rport = 2;

// Drivetrain speed
const double ControlMap::MaxDrivetrainSpeed = 0.8;

// Robot Values
const double ControlMap::TrackWidth = 0.56;
const double ControlMap::TrackDepth = 0.60;
const double ControlMap::WheelRadius = 0.0762; // In meters
const double ControlMap::Mass = 50; // KG's

//intake 
const int ControlMap::IntakePort = 5;
const int ControlMap::IntakeSolenoidPort1 = 0;
const int ControlMap::IntakeSolenoidPort2 = 1;
bool ControlMap::IntakeToggle = false;
bool ControlMap::ReverseIntakeToggle = false;

//mag
const int ControlMap::MagMotorPort = 4;
bool ControlMap::MagToggle = true;
bool ControlMap::ReverseMagToggle = true;

const double ControlMap::MagSpeed = 0.2;
const double ControlMap::ReverseMagSpeed = -0.2;

//shooter
const int ControlMap::FWPort = 8;
const int ControlMap::TPort = 6;
const int ControlMap::FPort = 3;
const int ControlMap::HPort = 7;

const double ControlMap::TurretMaxSpeed = 0.2;
const double ControlMap::HoodMaxSpeed = 1;
double ControlMap::FlyWheelMaxSpeed = 1;  //remember this is a falcon
const double ControlMap::FireSpeed = 0.5;
const double ControlMap::ReverseFireSpeed = -0.5;

// ------------------ Values ------------------
const tAxis ControlMap::DrivetrainLeft{ Driver, XboxController::kLeftYAxis };
const tAxis ControlMap::DrivetrainRight{ Driver, XboxController::kRightYAxis };

//intake
const tButton ControlMap::IntakeActuation{ CoDriver, XboxController::kY };
const tAxis ControlMap::Intake{ CoDriver, XboxController::kLeftThrottle };
const tButton ControlMap::Outake{CoDriver, XboxController::kBumperLeft };

//Mag
const tButton ControlMap::MagToggleButton{ CoDriver, XboxController::kA };
const tButton ControlMap::MagReverse{ CoDriver, XboxController::kB };

//shooter 
const tButton ControlMap::FireButton{ CoDriver, XboxController::kBumperRight };
const tPOV ControlMap::ReverseFire{ CoDriver, XboxController::kBottom };
const tAxis ControlMap::HoodLM{ CoDriver, XboxController::kRightYAxis }; //stands for hood linear motion 
const tAxis ControlMap::TurretTurn{ CoDriver, XboxController::kLeftXAxis };
const tAxis ControlMap::SpinUp{ CoDriver, XboxController::kRightThrottle }; //flywheel spinup
const tButton ControlMap::Speed{ Driver, XboxController::kX };