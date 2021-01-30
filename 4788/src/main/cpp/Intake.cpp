#include "Intake.h"

Intake::Intake(wml::Gearbox &intakeGearbox, wml::actuators::DoubleSolenoid &intakeSolenoid) : _intakeGearbox(intakeGearbox), _intakeSolenoid(intakeSolenoid) {}


void Intake::setIntake(const IntakeState st, double power) {
	_intakeState = st;
	_power = power;
}


void Intake::updateIntake(double dt) {
	// double voltage = 0; 

	// switch(_intakeState) {
	// 	case IntakeState::STOWED:
	// 		// voltage = 0;
  //     _power = 0;
	// 		break;

	// 	case IntakeState::DEPLOYED:
	// 		// voltage = 12 * _power;
      
	// 		break;
	// }

	// _intakeGearbox.transmission->SetVoltage(voltage);
	// _intakeSolenoid.Update(dt);
  // _intakeMotor->Set(_power);
}

void Intake::update(double dt) {
	updateIntake(dt);
}