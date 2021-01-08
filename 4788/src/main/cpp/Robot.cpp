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

void Robot::RobotInit() {
	driver = new frc::XboxController(0);
	coDriver = new frc::XboxController(0);
	_victors = new wml::VictorSpx[6] {wml::VictorSpx(99), wml::VictorSpx(99), wml::VictorSpx(99), wml::VictorSpx(99), wml::VictorSpx(99), wml::VictorSpx(99),};

}

void Robot::RobotPeriodic() {
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

void Robot::DisabledInit() {
}

void Robot::DisabledPeriodic() {
}
	controller = new frc::XboxController(0);
	_victor = new wml::VictorSpx(8);
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
}

void Robot::AutonomousPeriodic() {
}

void Robot::TeleopInit() {
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

void Robot::TeleopPeriodic() {
	_leftPower = driver->GetY(Hand::kLeftHand);
	_rightPower = driver->GetY(Hand::kRightHand);

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
	// Intake System
	SpeedIntake = coDriver->GetTriggerAxis(hand::kRightHand);
	if (SpeedIntake >= deadzone) {
		_victorIntake->Set(SpeedIntake);
	} else {
		_victorIntake->Set(0);
	}

	lastTimeStamp = currentTime;
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
