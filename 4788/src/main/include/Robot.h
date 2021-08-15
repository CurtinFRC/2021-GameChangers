#pragma once

/**
 * Local Files
 */
#include "RobotMap.h"

// Subsystems
#include "strategies/ClimberStrategies.h"
#include "strategies/IntakeStrategies.h"
#include "strategies/ShooterStategies.h"
#include "strategies/DriveSystem.h"
<<<<<<< HEAD
#include "strategies/IntakeStrategy.h"
#include "strategies/MagStrategy.h"
#include "strategies/ShooterStrategy.h"
#include "strategies/ClimberStrategy.h"
=======
#include "strategies/MagStrategies.h"
>>>>>>> 7a319f36c2adba576e52e65f7b02fbb0931601ba


class Robot : public frc::TimedRobot, protected wml::StrategyController, protected wml::NTProvider {
 public:
	void RobotInit() override;
	void RobotPeriodic() override;

	void DisabledInit() override;
	void DisabledPeriodic() override;

	void AutonomousInit() override;
	void AutonomousPeriodic() override;

	void TeleopInit() override;
	void TeleopPeriodic() override;

	void TestInit() override;
	void TestPeriodic() override;

 private:
	// Instances
	RobotMap robotMap;
	wml::Drivetrain *drivetrain; // WML drivetrain (Not local)
	Intake *intake;
	Mag *mag;
	Shooter *shooter;
<<<<<<< HEAD
	Climber *climber;
=======
	Mag *mag;
>>>>>>> 7a319f36c2adba576e52e65f7b02fbb0931601ba
};