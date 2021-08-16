#include "Intake.h"

Intake::Intake(wml::VictorSpx &intakeMotor) : _intakeMotor(intakeMotor) {}

void Intake::setIntake(const IntakeStates st, double power) {
	_intakeState = st;
	_power = power;
}

void Intake::updateIntake(double dt) {
	double setPower = 0;

	switch (_intakeState) {
		case IntakeStates::ON:
			setPower = _power;
			break;
		case IntakeStates::OFF:
			setPower = 0;
		break;
	}

	_intakeMotor.Set(setPower);
}

void Intake::update(double dt) {
	updateIntake(dt);
}