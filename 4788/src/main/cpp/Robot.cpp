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

	auto camera = CameraServer::GetInstance()->StartAutomaticCapture(0);
	camera.SetFPS(30);
	camera.SetResolution(160, 120);

	// Create wml drivetrain
	drivetrain = new Drivetrain(robotMap.driveSystem.drivetrainConfig, robotMap.driveSystem.gainsVelocity);
	// wayFinder = new WayFinder::WayFinder(robotMap.driveSystem.wfdConfig);

	// Zero Encoders
	robotMap.driveSystem.drivetrain.GetConfig().leftDrive.encoder->ZeroEncoder();
	robotMap.driveSystem.drivetrain.GetConfig().rightDrive.encoder->ZeroEncoder();

	// Strategy controllers (Set default strategy for drivetrain to be Manual)
	drivetrain->SetDefault(std::make_shared<DrivetrainManual>("Drivetrain Manual", *drivetrain, robotMap.contGroup));
	drivetrain->StartLoop(100);

	// Inverts one side of our drivetrain
	drivetrain->GetConfig().rightDrive.transmission->SetInverted(true);
	drivetrain->GetConfig().leftDrive.transmission->SetInverted(false);

	// Register our systems to be called via strategy
	StrategyController::Register(drivetrain);
	NTProvider::Register(drivetrain);

	intake = new Intake(robotMap.intakeSystem.intakeMotor, robotMap.intakeSystem.intakeDown);
	intake->SetDefault(std::make_shared<IntakeActuation>("Intake Manual", *intake, robotMap.contGroup));
	StrategyController::Register(intake);

	mag = new Mag(robotMap.magSystem.magMotor, robotMap.contGroup);
	mag->SetDefault(std::make_shared<MagStrategy>("Mag teleop strategy", *mag, robotMap.contGroup));
	StrategyController::Register(mag);

	climber = new Climber(robotMap.climberSystem.winch, robotMap.climberSystem.climberMotor, robotMap.climberSystem.climberSolenoid);
	climber->SetDefault(std::make_shared<ClimberStrategy>("climber manual strategy", *climber, robotMap.contGroup));
	StrategyController::Register(climber); 

	// path = wayFinder->buildPath(spline1);

	// Schedule(std::make_shared<DrivetrainAuto>("drive auto", *drivetrain, *wayFinder));

}

void Robot::RobotPeriodic() {
	currentTimeStamp = Timer::GetFPGATimestamp();
	dt = currentTimeStamp - lastTimeStamp;

	StrategyController::Update(dt);
	intake->update(dt);
	mag->update(dt);
	climber->update(dt);
	NTProvider::Update();

	lastTimeStamp = currentTimeStamp;
}

// Dissabled Robot Logic
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

// Auto Robot Logic
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {
	
	// std::cout << wayfinder.getCurrentLocation(robotMap.driveAuto.wfdConfig, true);
}

// Manual Robot Logic
void Robot::TeleopInit() {
	Schedule(drivetrain->GetDefaultStrategy(), true); // Use manual strategy
	Schedule(intake->GetDefaultStrategy(), true);
	Schedule(mag->GetDefaultStrategy(), true);
	Schedule(climber->GetDefaultStrategy(), true);
}
void Robot::TeleopPeriodic() {}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}