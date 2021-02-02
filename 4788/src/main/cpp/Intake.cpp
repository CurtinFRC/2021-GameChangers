#include "Intake.h"

Intake::Intake(wml::VictorSpx &intakeMotor, wml::actuators::DoubleSolenoid &intakeSolenoid) : _intakeMotor(intakeMotor), _intakeSolenoid(intakeSolenoid) {}


void Intake::setIntake(const IntakeStates st, double power) {
	_intakeState = st;
	_power = power;
}


void Intake::updateIntake(double dt) {
	double setPower = 0;

	// switch(_intakeState) {
	// 	case IntakeStates::ASTOWED:
	// 		_intakeSolenoid.SetTarget(wml::actuators::BinaryActuatorState::kReverse);
	// 		setPower = 0;
	// 		break;
	// 	case IntakeStates::ADEPLOYED:
	// 		_intakeSolenoid.SetTarget(wml::actuators::BinaryActuatorState::kForward);
	// 		setPower = _power;
	// 		break;
	// 	case IntakeStates::MSPINBACKWARDS:
	// 		setPower = _power;
	// 		setPower = -setPower;
	// 		break;
	// 	case IntakeStates::MSPINFORWARD:
	// 		setPower = _power;
	// 		break;
	// 	case IntakeStates::MSTOP:
	// 		setPower = 0;
	// 		break;
	// }

	// _intakeSolenoid.Update(dt);
  // _intakeMotor.Set(setPower);
}

void Intake::update(double dt) {
	updateIntake(dt);
}