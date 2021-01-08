#include "Robot.h"

using namespace frc;
using namespace wml;

using hand = frc::XboxController::JoystickHand;

double currentTime;
double lastTimeStamp;
double dt; //stands for delta time 

double constexpr deadzone = 0.1;
double SpeedIntake;

// Robot Logic
void Robot::RobotInit() {
	//init controllers 
	driver = new frc::XboxController(0);
	coDriver = new frc::XboxController(1);

	//Motors
	_victorIntake = new wml::VictorSpx(4);

	_victorIntake->SetInverted(true);
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
	currentTime = Timer::GetFPGATimestamp();
	dt = currentTime - lastTimeStamp;

	// Intake System
	SpeedIntake = coDriver->GetTriggerAxis(hand::kRightHand);
	if (SpeedIntake >= deadzone) {
		_victorIntake->Set(SpeedIntake);
	} else {
		_victorIntake->Set(0);
	}

	lastTimeStamp = currentTime;
}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}
