#pragma once

#include <string>
#include <stdint.h>

#include "devices/StateDevice.h"
#include "control/PIDController.h"
#include "strategy/StrategySystem.h"
#include "control/MotorFilters.h"
#include "Gearbox.h"
#include "strategy/Strategy.h"
#include "controllers/Controllers.h"
#include "sensors/BinarySensor.h"

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

#include <frc/smartdashboard/SmartDashboard.h>
#include <networktables/NetworkTableInstance.h>

#include <frc/Filesystem.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <wpi/Path.h>
#include <wpi/SmallString.h>

// REV/WMLRev
#include "rev/CANSparkMax.h"
#include "WMLRev.h"

// WML
#include "WMLCtre.h"
#include "controllers/Controllers.h"
#include "actuators/BinaryServo.h"
#include "actuators/Compressor.h"
#include "actuators/DoubleSolenoid.h"
#include "actuators/VoltageController.h"
#include "Drivetrain.h"
#include "sensors/Encoder.h"
#include "sensors/LimitSwitch.h"
#include "sensors/NavX.h"
#include "sensors/PressureSensor.h"
#include <networktables/NetworkTableInstance.h>
#include "control/PIDController.h"
#include "MotionProfiling.h"
#include "Toggle.h"
#include "strategy/StrategyController.h"
#include "strategy/MPStrategy.h"
#include "NTProvider.h"
#include "Gearbox.h"
#include "sensors/PressureSensor.h"

// SIM
#include "Usage.h"

struct RobotMap {
	struct DriveSystem {};
};