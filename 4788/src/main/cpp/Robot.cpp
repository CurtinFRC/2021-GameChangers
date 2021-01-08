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
}

void Robot::RobotPeriodic() {}

// Dissabled Robot Logic
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

// Auto Robot Logic
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

// Manual Robot Logic
void Robot::TeleopInit() {}
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

	lastTimeStamp = currentTimeStamp;
}

// Test Logic4
void Robot::TestInit() {}
void Robot::TestPeriodic() {}