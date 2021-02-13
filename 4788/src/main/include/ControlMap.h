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
	static const int Lport, Rport;
	static const double MaxDrivetrainSpeed;
	static const double TrackWidth, TrackDepth, WheelRadius, Mass;


	// ------------------ Controls ------------------
	
	// Drivetrain
	static const wml::controllers::tAxis DrivetrainLeft, DrivetrainRight;
};