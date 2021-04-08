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
	static const int PressureSensorPort, CompressorPort;

	// Drive System
	static const int Lport, Rport;
	static const double MaxDrivetrainSpeed;
	static const double TrackWidth, TrackDepth, WheelRadius, Mass;

	//Intake
	static const int IntakePort;
	static const int IntakeSolenoidPort1, IntakeSolenoidPort2;
	static bool IntakeToggle, ReverseIntakeToggle;

	//Mag
	static const int MagMotorPort;
	static bool MagToggle, ReverseMagToggle;
	static const double MagSpeed, ReverseMagSpeed;

	//shooter 
	static const int FWPort, TPort, FPort, HPort;
	static const double TurretMaxSpeed, HoodMaxSpeed, FireSpeed, ReverseFireSpeed;
	static double FlyWheelMaxSpeed;

	// ------------------ Controls ------------------
	
	// Drivetrain
	static const wml::controllers::tAxis DrivetrainLeft, DrivetrainRight;

	//Intake 
	static const wml::controllers::tAxis Intake;
	static const wml::controllers::tButton IntakeActuation;
	static const wml::controllers::tButton Outake;

	//Mag 
	static const wml::controllers::tButton MagToggleButton;
	static const wml::controllers::tButton MagReverse;

	//shooter
	static const wml::controllers::tButton FireButton;
	static const wml::controllers::tPOV ReverseFire;
	static const wml::controllers::tAxis HoodLM, TurretTurn, SpinUp;
	static const wml::controllers::tButton Speed;
};