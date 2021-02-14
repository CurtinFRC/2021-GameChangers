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

	// PCM1
	static const int PCModule;

	// Drive System
	static const int FLport, FRport, BLport, BRport;
	static const double MaxDrivetrainSpeed;
	static const double TrackWidth, TrackDepth, WheelRadius, Mass;

	//climber
	static const int climberPort;
	static bool ClimberToggle;

	//intake
	static const int intakePort;

	//shooter 
	static const int shooterPort, firePort;
	static const double fireSpeed;

	// ------------------ Controls ------------------

	//climber 
	static const wml::controllers::tAxis ClimberUp;
	static const wml::controllers::tAxis ClimberDown;
	static const wml::controllers::tButton DeployClimber;

	//intake 
	static const wml::controllers::tAxis Intake;
	static const wml::controllers::tButton Outake;

	// Drivetrain
	static const wml::controllers::tAxis DrivetrainLeft, DrivetrainRight;

	//shooter
	static const wml::controllers::tAxis FlywheelSpinUp;
	static const wml::controllers::tButton FireShooter;
};