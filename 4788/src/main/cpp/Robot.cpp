#include "Robot.h"

using namespace frc;
using namespace wml;

double currentTimeStamp;
double lastTimeStamp;
double dt;

// Robot Logiccd
void Robot::RobotInit() {
  ControlMap::InitsmartControllerGroup(robotMap.contGroup);

//   // Magazine
  magazine = new Magazine(robotMap.magazineSystem.magMotor1, robotMap.magazineSystem.magMotor2);
  magazine->SetDefault(std::make_shared<MagazineManualStrategy>("Magazine Manual", *magazine, robotMap.contGroup));


  // Drivebase Stuff

	//Create wml drivetrain
	drivetrain = new Drivetrain(robotMap.driveSystem.drivetrainConfig, robotMap.driveSystem.gainsVelocity);

	//Zero Encoders
	robotMap.driveSystem.drivetrain.GetConfig().leftDrive.encoder->ZeroEncoder();
	robotMap.driveSystem.drivetrain.GetConfig().rightDrive.encoder->ZeroEncoder();

	//Strategy controllers (Set default strategy for drivetrain to be Manual)
	drivetrain->SetDefault(std::make_shared<DrivetrainManual>("Drivetrain Manual", *drivetrain, robotMap.contGroup));
	drivetrain->StartLoop(100);

	//Inverts one side of our drivetrain
	drivetrain->GetConfig().rightDrive.transmission->SetInverted(true);
	drivetrain->GetConfig().leftDrive.transmission->SetInverted(false);


	// Climber
	climber = new Climber(robotMap.climber.climberMotor);
	climber->SetDefault(std::make_shared<ClimberManualStrategy>("Climber Manual", *climber, robotMap.contGroup));


	//Register our systems to be called via strategy
	StrategyController::Register(drivetrain);
	StrategyController::Register(magazine);
	StrategyController::Register(climber);

	// Nt Provider register
	NTProvider::Register(drivetrain);

	//turret
	turret = new Turret(robotMap.turretSystem.turretRot, robotMap.turretSystem.turretVert, robotMap.turretSystem.turretWheel, robotMap.turretSystem.RotLimit, robotMap.turretSystem.VertLimit);
	turret->SetDefault(std::make_shared<TurretManualStrategy>("Turret Manual", *turret, robotMap.contGroup));
		StrategyController::Register(turret);
	turret->StartLoop(100);
}


void Robot::RobotPeriodic() {
  currentTimeStamp = frc::Timer::GetFPGATimestamp();
  dt = currentTimeStamp - lastTimeStamp;

	StrategyController::Update(dt);
	
	NTProvider::Update();
	
	climber->update(dt);
  magazine->update(dt);

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
  Schedule(magazine->GetDefaultStrategy(), true);
	Schedule(drivetrain->GetDefaultStrategy(), true); // Use manual strategy
	Schedule(climber->GetDefaultStrategy(), true);
	Schedule(turret->GetDefaultStrategy(), true);
}
void Robot::TeleopPeriodic() {}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}