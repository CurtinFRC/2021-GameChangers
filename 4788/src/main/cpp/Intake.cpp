#include "Intake.h"

Intake::Intake(wml::VictorSpx &intakeMotor, wml::actuators::DoubleSolenoid &intakeSolenoid) : _intakeMotor(intakeMotor), _intakeSolenoid(intakeSolenoid) {}


void Intake::setIntake(const IntakeStates st, double power) {
	_intakeState = st;
	_power = power;
}

void Intake::updateIntake(double dt) {
	double setPower = 0;

	switch(_intakeState) {
		case IntakeStates::STOWED:
			_intakeSolenoid.SetTarget(wml::actuators::BinaryActuatorState::kReverse);
			setPower = 0;
			break;
		case IntakeStates::DEPLOYED:
			_intakeSolenoid.SetTarget(wml::actuators::BinaryActuatorState::kForward);
			setPower = _power;
			break;
	}

	_intakeSolenoid.Update(dt);
  _intakeMotor.Set(setPower);
}

void Intake::update(double dt) {
	updateIntake(dt);
}