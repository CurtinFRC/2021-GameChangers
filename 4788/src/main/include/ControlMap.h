#pragma once

#include <vector>
#include "controllers/Controllers.h"

/**
 * CAN Port System
 * 0-9 (Control System, pneumatics, PDP)
 * 10-19 (SparkMax/Brushless Motors)
 * 20- (Brushed)
 */

struct ControlMap {
	static void InitsmartControllerGroup(wml::controllers::SmartControllerGroup &contGroup);


	// ------------------ Values ------------------


	// Controllers
	static const int Xbox1Port, Xbox2Port;

	// USB port numbers
	static const int Driver = 1;
	static const int CoDriver = 2;

	// Deadzones
	static const double XboxDeadzone;
	static const double TriggerDeadzone;

	// Drive System
	static const int FLport, FRport, BLport, BRport;
	static const double MaxDrivetrainSpeed;
	static const double TrackWidth, TrackDepth, WheelRadius, Mass;

	//Intake
	static const int IntakePort;

	//Mag
	static const int MagMotorPort;
	static const double MagMaxSpeed;

	//shooter 
	static const int FWPort, FPort;
	static const double FireSpeed, ReverseFireSpeed;
	static double FlyWheelMaxSpeed;

	//mag
	static const int MagPort;
	static bool MagToggle;
	static const double MagSpeed;

	// ------------------ Controls ------------------
	// Drivetrain
	static const wml::controllers::tAxis DrivetrainLeft, DrivetrainRight;

	//Intake 
	static const wml::controllers::tAxis Intake;

	//shooter
	static const wml::controllers::tAxis FlywheelSpinUp;
	static const wml::controllers::tButton FireShooter;

	//mag 
	static const wml::controllers::tButton MagSpin;
};