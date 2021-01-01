#include "Robot.h"

using namespace frc;
using namespace wml;

using hand = frc::XboxController::JoystickHand;

double currentTime;
double lastTimeStamp;
double dt; //stands for delta time 

//add other variables here
double sparkSpeed;
double talonSpeed;
double constexpr deadzone = 0.1;

// Robot Logic
void Robot::RobotInit() {
	//init controllers 
	xbox = new frc::XboxController(0);

	//Motor examples 
	_sparkMotor = new frc::Spark(0);
	_talonMotor = new wml::TalonSrx(1);

	_sparkMotor->SetInverted(true);
	_talonMotor->SetInverted(false);
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
	sparkSpeed = xbox->GetY(hand::kLeftHand);
	_sparkMotor->Set(sparkSpeed);


	talonSpeed = xbox->GetTriggerAxis(hand::kRightHand);
	if (talonSpeed >= deadzone) { //acounts for the deadzone
		_talonMotor->Set(talonSpeed);
	} else {
		_talonMotor->Set(0);
	}

	// ^ the equivilant using a conditional statement 
	//talonSpeed = xbox->GetTriggerAxis(hand::kRightHand) > deadzone ? xbox->GetTriggerAxis(hand::kRightHand) : 0; _talonMotor->Set(talonSpeed);

	if(xbox->GetXButton()) {
		_solenoid.SetTarget(wml::actuators::BinaryActuatorState::kForward);
	} else {
		_solenoid.SetTarget(wml::actuators::BinaryActuatorState::kReverse);
	}

	_compressor.Update(dt);
	_solenoid.Update(dt);

	if (_solenoid.IsDone()) _solenoid.Stop();
	lastTimeStamp = currentTime;
}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}
