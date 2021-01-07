#include "Robot.h"

using namespace frc;
using namespace wml;

using hand  = frc::XboxController::JoystickHand;

double currentTimeStamp;
double lastTimeStamp;
double dt;

double motorSpeed[2] {0,0};
double constexpr deadzone = 0.1;

// Robot Logiccd
void Robot::RobotInit() {

	controller = new frc::XboxController(0);

	_victor = new wml::VictorSpx[2] {wml::VictorSpx(8) , wml::VictorSpx(9)};

	_talon = new wml::TalonSrx[2] {wml::TalonSrx(1) , wml::TalonSrx(2)};

	_talon[0].SetInverted(true);
	_victor[0].SetInverted(true);
	_talon[1].SetInverted(false);
	_victor[1].SetInverted(false);

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

	// Register our systems to be called via strategy
	StrategyController::Register(drivetrain);
	NTProvider::Register(drivetrain);
}

void Robot::RobotPeriodic() {}

// Dissabled Robot Logic
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

// Auto Robot Logic
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

// Manual Robot Logic
void Robot::TeleopInit() {
	Schedule(drivetrain->GetDefaultStrategy(), true); // Use manual strategy
}
void Robot::TeleopPeriodic() {
	currentTimeStamp = Timer::GetFPGATimestamp();
	dt = currentTimeStamp - lastTimeStamp;


	motorSpeed[0] = controller->GetY(hand::kLeftHand);
	if (abs(motorSpeed[0]) <= deadzone) {
		motorSpeed[0] = 0;
	}

	motorSpeed[1] = controller->GetY(hand::kRightHand);
	if (abs(motorSpeed[1]) <= deadzone) {
		motorSpeed[1] = 0;
	}

	// Motor sets 
	
	_talon[0].Set(motorSpeed[0]);
	_victor[0].Set(motorSpeed[0]);

	_talon[1].Set(motorSpeed[1]);
	_victor[1].Set(motorSpeed[1]);

	StrategyController::Update(dt);
	NTProvider::Update();

	lastTimeStamp = currentTimeStamp;
}

// Test Logic4
void Robot::TestInit() {}
void Robot::TestPeriodic() {}