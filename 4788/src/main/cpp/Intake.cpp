#include "Intake.h"

Intake::Intake(wml::TalonSrx &intakeMotor, wml::actuators::DoubleSolenoid &intakeSolenoid) : _intakeMotor(intakeMotor), _intakeSolenoid(intakeSolenoid) {}

void Intake::setIntake(const IntakeStates st, double power) {
	_intakeState = st;
	_power = power;
}

void Intake::updateIntake(double dt) {
	double setPower = 0;

	switch (_intakeState) {
		case IntakeStates::STOWED:
			_intakeSolenoid.SetTarget(wml::actuators::BinaryActuatorState::kForward);
			setPower = _power;
			std::cout << "stowed" << std::endl;
			break;
		case IntakeStates::DEPLOYED:
			_intakeSolenoid.SetTarget(wml::actuators::BinaryActuatorState::kReverse);
			
			std::cout << "deployed" << std::endl;
			break;
	}

	_intakeMotor.Set(setPower);
	_intakeSolenoid.Update(dt);
}

void Intake::update(double dt) {
	updateIntake(dt);
}