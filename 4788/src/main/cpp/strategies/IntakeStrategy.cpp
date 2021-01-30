#include "strategies/IntakeStrategy.h"

IntakeManualStrategy::IntakeManualStrategy(std::string name, Intake &intake, Controllers &contGroup) : Strategy(name), _intake(intake), _contGroup(contGroup) {
  Requires(&intake);
  SetCanBeInterrupted(true);
  SetCanBeReused(true);
}

void IntakeManualStrategy::OnUpdate(double dt) {
	// double powerIn = fabs(_contGroup.Get(ControlMap::Intake)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Intake) : 0;
	// double powerOut = fabs(_contGroup.Get(ControlMap::Outake)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Outake) : 0;

  if (_contGroup.Get(ControlMap::Intake)) {
    _intakeMotor->Set(IntakeSpeed);
  } else {
    _intakeMotor->Set(0);
  }

  if (_contGroup.Get(ControlMap::Outake)) {
    _intakeMotor->Set(-IntakeSpeed);
  } else {
    _intakeMotor->Set(0);
  }
}