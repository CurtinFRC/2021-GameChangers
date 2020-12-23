#include "Robot.h"

using namespace frc;
using namespace wml;

using hand = frc::XboxController::JoystickHand;

double currentTimeStamp;
double lastTimeStamp;
double dt; //stands for delta time 

//add other variables here
double SparkSpeed;
double TalonSpeed;

// Robot Logic
void Robot::RobotInit() {
	
	dt = frc::Timer::GetFPGATimestamp() - lastTimeStamp;
	lastTimeStamp = frc::Timer::GetFPGATimestamp();

	//init controllers 
	xbox = new frc::XboxController(0);

	//Motor examples 
	SparkMotor[0] = new frc::Spark(0);
	TalonMotor = new wml::TalonSrx(1);

	SparkMotor[0]->SetInverted(true);
	TalonMotor->SetInverted(false);

	//registers the pressure sensor as a sensor to be logged to Network Tables
	NTProvider::Register(&pressureSensor); 

}

void Robot::RobotPeriodic() {
	if (pressureSensor.GetScaled() < 80) {
		compressor.SetTarget(wml::actuators::BinaryActuatorState::kForward); // turn the compressor on 
	}
}

// Dissabled Robot Logic
void Robot::DisabledInit() {
	InterruptAll(true);
}
void Robot::DisabledPeriodic() {}

// Auto Robot Logic
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

// Manual Robot Logic
void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {

	//motor examples
	SparkSpeed = xbox->GetY(hand::kLeftHand);
	SparkMotor[0]->Set(SparkSpeed);

	TalonSpeed = xbox->GetTriggerAxis(hand::kRightHand);
	if (TalonSpeed >= 0.1) { //acounts for the deadzone
		TalonMotor->Set(TalonSpeed);
	} else {
		TalonMotor->Set(0);
	}

	if(xbox->GetXButton()) {
		solenoid.SetTarget(wml::actuators::BinaryActuatorState::kForward);
	} else {
		solenoid.SetTarget(wml::actuators::BinaryActuatorState::kReverse);
	}

	compressor.Update(dt);
	solenoid.Update(dt);

	if (solenoid.IsDone()) solenoid.Stop();
	NTProvider::Update();
}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}