#include "Robot.h"

using namespace frc;
using namespace wml;

using hand  = frc::XboxController::JoystickHand;

double currentTimeStamp;
double lastTimeStamp;
double dt;
double tTaken = 0;
double tNeeded = 0;
bool isSpinning = false;
double maxSpeed = 0.8;
double motorSpeed = 0;
double constexpr deadzone = 0.1;

// Robot Logiccd
void Robot::RobotInit() {
	controller = new frc::XboxController(0);
	_victor = new wml::VictorSpx(8);
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
	tTaken += dt;
	motorSpeed = pow(controller->GetTriggerAxis(hand::kLeftHand),3);
	motorSpeed *= maxSpeed;
	if (motorSpeed <= deadzone) {
		motorSpeed = 0;
	}

	if (controller->GetYButton()) {
		motorSpeed = -0.2;
	}

	if (controller->GetXButtonPressed()) {
		tNeeded = tTaken + 2;
		isSpinning = true;
	}
	
	if (isSpinning) {
		if (tTaken >= tNeeded) {
			isSpinning = false;
			motorSpeed = 0;
		} else {
			motorSpeed = 0.8;
		}
	}
	_victor->Set(motorSpeed);
	lastTimeStamp = currentTimeStamp;
}

// Test Logic4
void Robot::TestInit() {}
void Robot::TestPeriodic() {}