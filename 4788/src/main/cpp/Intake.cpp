#include "Intake.h"

using namespace wml;
using namespace wml::controllers;

Intake::Intake(SmartControllerGroup &contGroup, wml::actuators::DoubleSolenoid &IntakeDown, wml::TalonSrx &IntakeMotor) : _contGroup(contGroup), _IntakeDown(IntakeDown), _intakeMotor(IntakeMotor){
  _IntakeDown.SetTarget(wml::actuators::BinaryActuatorState::kReverse); //Defult State
}

void Intake::TeleopOnUpdate(double dt) {
  if (_contGroup.Get(ControlMap::DownIntake, Controller::ONRISE)) {
  	if (_ToggleEnabled) {
      _IntakeDown.SetTarget(wml::actuators::BinaryActuatorState::kReverse);
      _ToggleEnabled = false;
    } else if (!_ToggleEnabled) {
      _IntakeDown.SetTarget(wml::actuators::BinaryActuatorState::kForward);
      _ToggleEnabled = true;
    }
  }

  if (_contGroup.Get(ControlMap::IntakeIn) >= ControlMap::TriggerDeadzone) {
    speedIntake = _contGroup.Get(ControlMap::IntakeIn);
  } else {
    speedIntake = 0;
  }

  _intakeMotor.Set(speedIntake);
	_IntakeDown.Update(dt);

}