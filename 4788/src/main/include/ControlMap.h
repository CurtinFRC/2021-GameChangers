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

	//Magazine 
  static const int MagLoaderMotorPort;
  static const int MagLoaderFunnelMotorPortLeft;
  static const int MagLoaderFunnelMotorPortRight;
  static const int StartMagLimitPort, Position1LimitPort, Position5LimitPort;
	static const double MagazineBallThreshStart;
  static const double MagazineBallThreshFinal;
  static const double MagazineBallThreshIndex;

	//Intake
  static const int IntakeMotorPort;
  static const int IntakeDownPort1, IntakeDownPort2;
  static const double PannelActuationTime;

	// ------------------ Controls ------------------
	
	// Drivetrain
	static const wml::controllers::tAxis DrivetrainLeft, DrivetrainRight;

	// Magazine
	//static const wml::controllers::

	//Intake
	// static const wml::controllers::tAxis Intakes;
	// static const wml::controllers::tAxis Outake;
	static const wml::controllers::tButton DownIntake;
	static const wml::controllers::tAxis IntakeIn;
};