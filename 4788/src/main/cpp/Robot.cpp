#include "Robot.h"

using namespace frc;
using namespace wml;

using Hand = frc::XboxController::JoystickHand;

const double deadzone = 0.1;

void Robot::RobotInit() {
	driver = new frc::XboxController(0);
	coDriver = new frc::XboxController(0);
	_victors = new wml::VictorSpx[6] {wml::VictorSpx(99), wml::VictorSpx(99), wml::VictorSpx(99), wml::VictorSpx(99), wml::VictorSpx(99), wml::VictorSpx(99),};

}

void Robot::RobotPeriodic() {
}

void Robot::DisabledInit() {
}

void Robot::DisabledPeriodic() {
}

void Robot::AutonomousInit() {
}

void Robot::AutonomousPeriodic() {
}

void Robot::TeleopInit() {
}

void Robot::TeleopPeriodic() {
	if (std::abs(_leftPower) >= deadzone) {
		_leftPower = driver->GetY(Hand::kLeftHand);
	} else {
		_leftPower = 0;
	}
	if (std::abs(_rightPower) >= deadzone) {
		_rightPower = driver->GetY(Hand::kRightHand);
	} else {
		_rightPower = 0;
	}

	motors(_rightPower, _leftPower);
}

void Robot::TestInit() {
}

void Robot::TestPeriodic() {
}

// motors: set the motors from right power and left power
void Robot::motors(const double rightPower, const double leftPower) {
	_victors[0].Set(rightPower);
	_victors[1].Set(rightPower);
	_victors[2].Set(rightPower);
	_victors[3].Set(leftPower);
	_victors[4].Set(leftPower);
	_victors[5].Set(leftPower);
}
