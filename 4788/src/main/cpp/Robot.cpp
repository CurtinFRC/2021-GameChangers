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

	// Create wml drivetrain
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

	intake = new Intake(robotMap.intakeSystem.intakeMotor, robotMap.intakeSystem.intakeDown);
	intake->SetDefault(std::make_shared<IntakeManualStrategy>("Intake Manual strat", *intake, robotMap.contGroup));
	StrategyController::Register(intake);

	mag = new Mag(robotMap.magSystem.magMotor);
	mag->SetDefault(std::make_shared<MagManualStrategy>("Mag Manual Strategy", *mag, robotMap.contGroup));
	StrategyController::Register(mag);

	shooter = new Shooter(robotMap.shooterSystem.flyWheelMotor, robotMap.shooterSystem.hoodMotor, robotMap.shooterSystem.turretMotor, robotMap.shooterSystem.fireMotor);
	shooter->SetDefault(std::make_shared<ShooterManualStrategy>("Shooter Manual strat", *shooter, robotMap.contGroup));
	StrategyController::Register(shooter);

	robotMap.controlSystem.compressor.SetTarget(wml::actuators::BinaryActuatorState::kForward);
	robotMap.controlSystem.compressor.Update(dt);

	// Register our systems to be called via strategy
	StrategyController::Register(drivetrain);
	NTProvider::Register(drivetrain);
}

void Robot::RobotPeriodic() {
	currentTimeStamp = Timer::GetFPGATimestamp();
	dt = currentTimeStamp - lastTimeStamp;

	StrategyController::Update(dt);
	intake->update(dt);
	mag->update(dt);
	shooter->update(dt);
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
}
void Robot::TeleopPeriodic() {}

// Test Logic4
void Robot::TestInit() {}
void Robot::TestPeriodic() {}