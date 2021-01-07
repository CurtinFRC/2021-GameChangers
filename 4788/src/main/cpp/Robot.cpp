#include "Robot.h"

using namespace frc;
using namespace wml;

using Hand = frc::XboxController::JoystickHand;

const double deadzone = 0.1;

void Robot::RobotInit()
{
	controller = new frc::XboxController(0);
	victors = new wml::VictorSpx[2] {wml::VictorSpx(9), wml::VictorSpx(8)};
	talons = new wml::TalonSrx[2] {wml::TalonSrx(2), wml::TalonSrx(1)};

	victors[1].SetInverted(true);
	talons[1].SetInverted(true);

}

void Robot::RobotPeriodic()
{
}

void Robot::DisabledInit()
{
}

void Robot::DisabledPeriodic()
{
}

void Robot::AutonomousInit()
{
}

void Robot::AutonomousPeriodic()
{
}

void Robot::TeleopInit()
{
}

void Robot::TeleopPeriodic()
{
	if (std::abs(left_power) >= deadzone) {
		left_power = controller->GetY(Hand::kLeftHand);
	} 
	else {
		left_power = 0;
	}
	if (std::abs(right_power) >= deadzone) {
		right_power = controller->GetY(Hand::kRightHand);
	} 
	else {
		right_power = 0;
	}

	motors(right_power, left_power);
}

void Robot::TestInit()
{
}

void Robot::TestPeriodic()
{
}

// motors: set the motors from right power and left power
void Robot::motors(const double right_power, const double left_power)
{
	talons[0].Set(right_power);
	victors[0].Set(right_power);
	talons[1].Set(left_power);
	victors[1].Set(left_power);
}

// longitudinal: translate the robot longitudinally for a distance
void Robot::longitudinal(const Meter& distance)
{
	motors(0, 0);

	talons[0].ZeroEncoder();
	talons[1].ZeroEncoder();

	double rotations = (distance / wheel_circumference);

	// while not at destination translate
	if (distance > 0) {
		while (((talons[0].GetEncoderRotations() + talons[1].GetEncoderRotations()) / 2) < rotations) {
			motors(0.5, 0.5);
		}
	}
	if (distance < 0) {
		while (((talons[0].GetEncoderRotations() + talons[1].GetEncoderRotations()) / 2) < rotations) {
			motors(-0.5, -0.5);
		}
	}

	motors(0, 0);
}
