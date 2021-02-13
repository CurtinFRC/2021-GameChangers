#include "Intake.h"

Intake::Intake(wml::VictorSpx &intakeMotor) : _intakeMotor(intakeMotor) {}

void Intake::setIntake(const IntakeState st, double power) {
	_intakeState = st;
	_power = power;
}

void Intake::updateIntake(double dt) {
	setPower = _power;

	_intakeMotor.Set(setPower);
}

void Intake::update(double dt) {
	updateIntake(dt);
}