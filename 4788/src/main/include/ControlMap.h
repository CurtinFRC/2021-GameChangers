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
	static const int Driver = 0;
	static const int CoDriver = 1;

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
  static const int MagMotorPort1;
  static const int MagMotorPort2;

	// Climber System
	static const int ClimberPort;
	static const int ClimberEncoderTicks;
	static const double ClimberSpeed;
	static const double ClimberAdjustSpeed;
	static const int ClimberJamTolerance;
	// Turret
	static const int TurretRotPort, TurretVertPort, TurretFlyPort, RotLimitPort, VertLimitPort;
	static const bool RotLimitInvert, VertLimitInvert;
	static const double VerticalAxisMin, VerticalAxisMax, VerticalAxisP, VerticalAxisI, VerticalAxisD, RotationalAxisMin, RotationalAxisMax, RotationalAxisP, RotationalAxisI, RotationalAxisD, RotationalAxisDeg, FlywheelP, FlywheelI, FlywheelD, FlywheelMin, FlywheelMax, VoltageMin, VoltageMax, ZeroValt;


	// ------------------ Controls ------------------
	
	// Drivetrain
	static const wml::controllers::tAxis DrivetrainLeft, DrivetrainRight;

	// Magazine
	// static const wml::controllers::tPOV MagReverse;
	// static const wml::controllers::tPOV Outake;
	static const wml::controllers::tPOV ShiftMagazinePOV;
	static const wml::controllers::tButton MagLeft;
	static const wml::controllers::tButton MagRight;

	// Climber
	static const wml::controllers::tButton ClimberActivate, ClimberDeactivate;
	static const wml::controllers::tAxis ClimberAdjust;
	static const wml::controllers::tButton ClimberUp, ClimberDown;
	// Turret
	static const wml::controllers::tAxis VertStick, RotStick, ShootTrig;
};