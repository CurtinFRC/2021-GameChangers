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

	//intake
	static const int IntakePort, intakeSolenoidPort1, intakeSolenoidPort2;
	static const double IntakeSpeed;


	//mag
	static const int MagPort, FirePort;
	static const double MagBackSpeed;

	//shooter
	static const int ShooterPort;

	//climber 
	static const int WinchPort, ClimberSolenoidPort1, ClimberSolenoidPort2, ClimberPort;
	static const double WinchDownPower, ClimberUpSpeed, climberAdjustSpeed;


	// ------------------ Controls ------------------
	
	// Drivetrain
	static const wml::controllers::tAxis DrivetrainLeft, DrivetrainRight;

	//intake 
	static const wml::controllers::tButton Intake, Outake, Down;

	//mag
	static const wml::controllers::tPOV MagBackwards;
	static const wml::controllers::tAxis MagForwards;

	//shooter

	//climber 
	static const wml::controllers::tButton ClimberTop, ClimberUp, ClimberDown;
	static const wml::controllers::tPOV ClimberBottom, WinchDown;
	static const wml::controllers::tAxis WinchUp;

	
};