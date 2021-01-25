#include "Robot.h"

using namespace frc;
using namespace wml;

double currentTimeStamp;
double lastTimeStamp;
double dt;

// Robot Logiccd
void Robot::RobotInit() {
	// Init the controllers
	ControlMap::InitsmartControllerGroup(robotMap.contGroup);

	// Create wml drivetrain
	drivetrain = new Drivetrain(robotMap.driveSystem.drivetrainConfig, robotMap.driveSystem.gainsVelocity);

	
	// Zero Encoders
	robotMap.driveSystem.drivetrain.GetConfig().leftDrive.encoder->ZeroEncoder();
	robotMap.driveSystem.drivetrain.GetConfig().rightDrive.encoder->ZeroEncoder();

	// Strategy controllers (Set default strategy for drivetrain to be Manual)
	drivetrain->SetDefault(std::make_shared<DrivetrainManual>("Drivetrain Manual", *drivetrain, robotMap.contGroup));
	drivetrain->StartLoop(100);

	// Inverts one side of our drivetrain
	drivetrain->GetConfig().rightDrive.transmission->SetInverted(true);
	drivetrain->GetConfig().leftDrive.transmission->SetInverted(false);

	// Climber
	climber = new Climber(robotMap.climber.climberMotor);

	climber->SetDefault(std::make_shared<ClimberManualStrategy>("Climber Manual", *climber, robotMap.contGroup));

	// Register our systems to be called via strategy
	StrategyController::Register(drivetrain);
	StrategyController::Register(climber);
	NTProvider::Register(drivetrain);
}

void Robot::RobotPeriodic() {
	currentTimeStamp = Timer::GetFPGATimestamp();
	dt = currentTimeStamp - lastTimeStamp;

	StrategyController::Update(dt);
	climber->update(dt);
	NTProvider::Update();

	lastTimeStamp = currentTimeStamp;
}

// Dissabled Robot Logic
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

// Auto Robot Logic
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

// Manual Robot Logic
void Robot::TeleopInit() {
	Schedule(drivetrain->GetDefaultStrategy(), true); // Use manual strategy
	Schedule(climber->GetDefaultStrategy(), true);
}
void Robot::TeleopPeriodic() {}

// Test Logic4
void Robot::TestInit() {}
void Robot::TestPeriodic() {}