#include "Robot.h"

using namespace frc;
using namespace wml;

using hand = frc::XboxController::JoystickHand;

double currentTime;
double lastTimeStamp;
double dt; //stands for delta time 

//add other variables here
double sparkSpeed;
double leftSpeed;
double rightSpeed;

double const deadzone = 0.1;

// Robot Logic
void Robot::RobotInit() {
	//init controllers 
	xbox = new frc::XboxController(0);

	//Motor examples 
	_sparkMotor = new Spark(0);
	// _talonMotor = new wml::TalonSrx(1);

	_leftTalon = new wml::TalonSrx(1);
	_rightTalon = new wml::TalonSrx(2);
	_leftVictor = new wml::VictorSpx(8);
	_rightVictor = new wml::VictorSpx(9);

	// _sparkMotor->SetInverted(true);
	// _talonMotor->SetInverted(false);

	_leftTalon->SetInverted(true);
	// _rightTalon->SetInverted(false);
	_leftVictor->SetInverted(true);
	// _rightVictor->SetInverted(true);

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

	//motor examples
	sparkSpeed = xbox->GetX(hand::kLeftHand);
	if (abs(sparkSpeed) >= deadzone) {
		_sparkMotor->Set(sparkSpeed);
	} else {
		_sparkMotor->Set(0);
	}
	

	// leftSpeed = xbox->GetY(hand::kLeftHand);
	// if (leftSpeed >= deadzone || leftSpeed <= -0.1) {
	// 	_leftTalon->Set(leftSpeed);
	// 	_leftVictor->Set(leftSpeed);
	// } else {
	// 	_leftTalon->Set(0);
	// 	_leftVictor->Set(0);
	// }


	rightSpeed = xbox->GetY(hand::kRightHand);
	if (abs(rightSpeed) >= deadzone) {
		_rightTalon->Set(rightSpeed);
		_rightVictor->Set(rightSpeed);
	} else {
		_rightTalon->Set(0);
		_rightVictor->Set(0);
	}

	// if(xbox->GetXButton()) {
	// 	_solenoid.SetTarget(wml::actuators::BinaryActuatorState::kForward);
	// } else {
	// 	_solenoid.SetTarget(wml::actuators::BinaryActuatorState::kReverse);
	// }

	_compressor.Update(dt);
	_solenoid.Update(dt);

	if (_solenoid.IsDone()) _solenoid.Stop();
	lastTimeStamp = currentTime;
}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}