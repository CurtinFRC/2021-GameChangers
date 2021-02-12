#pragma once

// Standard Includes
#include <string>
#include <stdint.h>

// FRC
#include <frc/Timer.h>
#include <frc/TimedRobot.h>
#include <frc/DoubleSolenoid.h>
#include <frc/GenericHID.h>

#include <frc/SpeedControllerGroup.h>
#include <frc/Spark.h>
#include <frc/PowerDistributionPanel.h>
#include <frc/PWMSparkMax.h>
#include <frc/Servo.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/AnalogInput.h>
#include <networktables/NetworkTableInstance.h>

#include <frc/Filesystem.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <networktables/NetworkTableInstance.h>
#include <wpi/Path.h>
#include <wpi/SmallString.h>

// REV
#include "rev/CANSparkMax.h"
#include "WMLRev.h"

// WML
#include "WMLCtre.h"
#include "controllers/Controllers.h"
#include "actuators/BinaryServo.h"
#include "actuators/Compressor.h"
#include "NTProvider.h"
#include "actuators/DoubleSolenoid.h"
#include "actuators/VoltageController.h"
#include "Drivetrain.h"
#include "sensors/Encoder.h"
#include "sensors/LimitSwitch.h"
#include "sensors/NavX.h"
#include "sensors/PressureSensor.h"
#include "control/PIDController.h"
#include "MotionProfiling.h"
#include "Toggle.h"

#include "devices/StateDevice.h"
#include "strategy/StrategyController.h"
#include "strategy/MPStrategy.h"
#include "control/MotorFilters.h"
#include "Gearbox.h"
#include "strategy/Strategy.h"
#include "sensors/BinarySensor.h"

// WML SIM
#include "Usage.h"

// WayFinder Auto
#include "WayFinder.h"

// Local Files
#include "ControlMap.h"

// #include "strategies/DriveSystem.h"

struct RobotMap {

	// Controllers
	wml::controllers::XboxController xbox1{ ControlMap::Xbox1Port };
	wml::controllers::XboxController xbox2{ ControlMap::Xbox2Port };
	wml::controllers::SmartControllerGroup contGroup{ xbox1, xbox2};

	struct DriveSystem {

		// Drive motors {port, encoderTicks}
		wml::TalonSrx FL{ControlMap::FLport, 2048}, FR{ControlMap::FRport, 2048}, BL{ControlMap::BLport}, BR{ControlMap::BRport};

		// Motor Grouping
		wml::actuators::MotorVoltageController leftMotors = wml::actuators::MotorVoltageController::Group(FL, BL);
		wml::actuators::MotorVoltageController rightMotors = wml::actuators::MotorVoltageController::Group(FR, BR);

		// Gearboxes
		wml::Gearbox LGearbox{&leftMotors, &FL};
		wml::Gearbox RGearbox{&rightMotors, &FR};

		wml::sensors::NavX navx{};
		wml::sensors::NavXGyro gyro{navx.Angular(wml::sensors::AngularAxis::YAW)};

		wml::DrivetrainConfig drivetrainConfig{LGearbox, RGearbox, &gyro, ControlMap::TrackWidth, ControlMap::TrackDepth, ControlMap::WheelRadius, ControlMap::Mass};
		wml::control::PIDGains gainsVelocity{"Drivetrain Velocity", 1};
		wml::Drivetrain drivetrain{drivetrainConfig, gainsVelocity};

		// wayfinder::RobotControl::Config wfdConfig {
		// 	&drivetrain,
		// 	true,
		// 	false, 

		// 	//make these all controlmap variables later
		// 	0.3, //P 
		// 	0.001, //I  
		// 	0.024, //D

		// 	8.24, //gearbox reduction, eg. 8.24 rotations = 1 wheel rotation
		// 	0.1524, //whel diameter in meters 
		// 	0.5, // max speed of the robot 
		// 	0.3, //max speed of the robot when turning 
		// };

	}; DriveSystem driveSystem;

	// struct DriveAutoSystem {


	// }; DriveAutoSystem driveAutosystem;

	struct IntakeSystem {
		// Motors
		// wml::TalonSrx motor {ControlMap::IntakePort, 2048};
		// wml::actuators::MotorVoltageController motorGroup = wml::actuators::MotorVoltageController::Group(motor);

		// wml::Gearbox intakeGearbox{ &motorGroup, &motor };


		wml::VictorSpx intakeMotor{ControlMap::IntakePort};
		// solenoids
		wml::actuators::DoubleSolenoid intakeDown{ ControlMap::PCModule, ControlMap::intakeSolenoidPort1, ControlMap::intakeSolenoidPort2, 0.1 };
	}; IntakeSystem intakeSystem;

	struct MagSystem {
		wml::TalonSrx magMotor{ControlMap::MagPort, 2048};

	}; MagSystem magSystem;

	struct ShooterSystem {
		wml::TalonSrx shooterMotor { ControlMap::ShooterPort, 2048};
		wml::VictorSpx fireMotor{ ControlMap::FirePort};
		wml::TalonSrx turretMotor{ 99, 2048};
		wml::TalonSrx hoodMotor{ 99, 2048};

	}; ShooterSystem shooterSystem;

	struct ClimberSystem {
		wml::VictorSpx winch{ ControlMap::WinchPort};
		wml::TalonSrx climberMotor{ControlMap::ClimberPort};
		wml::actuators::DoubleSolenoid climberSolenoid{ControlMap::PCModule, ControlMap::ClimberSolenoidPort1, ControlMap::ClimberSolenoidPort2, 0.1};

	}; ClimberSystem climberSystem;
};