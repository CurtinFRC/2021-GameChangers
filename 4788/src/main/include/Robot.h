#pragma once

/**
 * Local Files
 */
#include "RobotMap.h"

// Subsystems
#include "strategies/IntakeStrategies.h"
#include "strategies/ShooterStategies.h"
#include "strategies/DriveSystem.h"
#include "strategies/MagStrategies.h"


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
};