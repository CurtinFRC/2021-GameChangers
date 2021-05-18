#include "Robot.h"

using namespace frc;
using namespace wml;

double currentTimeStamp;
double lastTimeStamp;
double dt;

// Robot Logic
void Robot::RobotInit() {
	// Init the controllers
	ControlMap::InitsmartControllerGroup(robotMap.contGroup);

	drivetrain = new Drivetrain(robotMap.driveSystem.drivetrainConfig, robotMap.driveSystem.gainsVelocity);
	
	// Zero Encoders
	robotMap.driveSystem.drivetrain.GetConfig().leftDrive.encoder->ZeroEncoder();
	robotMap.driveSystem.drivetrain.GetConfig().rightDrive.encoder->ZeroEncoder();

	// Strategy controllers (Set default strategy for drivetrain to be Manual)
	drivetrain->SetDefault(std::make_shared<DrivetrainManual>("Drivetrain Manual", *drivetrain, robotMap.contGroup));
	drivetrain->StartLoop(100);

	// Inverts one side of our drivetrain
	drivetrain->GetConfig().rightDrive.transmission->SetInverted(false);
	drivetrain->GetConfig().leftDrive.transmission->SetInverted(true);
	robotMap.driveSystem.FR.SetInverted(true);

	intake = new Intake(robotMap.intakeSystem.intakeMotor);
	intake->SetDefault(std::make_shared<IntakeManualStrategy>("Intake Manual strat", *intake, robotMap.contGroup));
	StrategyController::Register(intake);

	mag = new Mag(robotMap.magSystem.magMotor);
	mag->SetDefault(std::make_shared<MagManualStrategy>("Mag Manual Strategy", *mag, robotMap.contGroup));
	StrategyController::Register(mag);

	shooter = new Shooter(robotMap.shooterSystem.flyWheelMotor, robotMap.shooterSystem.fireMotor);
	shooter->SetDefault(std::make_shared<ShooterManualStrategy>("Shooter Manual strat", *shooter, robotMap.contGroup));
	StrategyController::Register(shooter);

	climber = new Climber(robotMap.climberSystem.climberMotor);
	climber->SetDefault(std::make_shared<ClimberManualStrategy>("Climber Manual Strategy", *climber, robotMap.contGroup));
	StrategyController::Register(climber);

	// Register our systems to be called via strategy
	StrategyController::Register(drivetrain);
	NTProvider::Register(drivetrain);

	climber = new Climber(robotMap.climberSystem.climberMotor);
	climber->SetDefault(std::make_shared<ClimberStrategy>("Climber Manual", *climber, robotMap.contGroup));
	StrategyController::Register(climber);

	intake = new Intake(robotMap.intakeSystem.intakeMotor);
	intake->SetDefault(std::make_shared<IntakeStrategy>("Intake manual", *intake, robotMap.contGroup));
	StrategyController::Register(intake);

	shooter = new Shooter(robotMap.shooterSystem.shooterMotor, robotMap.shooterSystem.fireMotor);
	shooter->SetDefault(std::make_shared<ShooterStrategy>("shooter manual", *shooter, robotMap.contGroup));
	StrategyController::Register(shooter);
}

void Robot::RobotPeriodic() {
	currentTimeStamp = Timer::GetFPGATimestamp();
	dt = currentTimeStamp - lastTimeStamp;

	// Update our controllers and strategy
	StrategyController::Update(dt);
	intake->update(dt);
	mag->update(dt);
	shooter->update(dt);
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
	Schedule(intake->GetDefaultStrategy(), true);
	Schedule(mag->GetDefaultStrategy(), true);
	Schedule(shooter->GetDefaultStrategy(), true);
	Schedule(climber->GetDefaultStrategy(), true);
}
void Robot::TeleopPeriodic() {}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}