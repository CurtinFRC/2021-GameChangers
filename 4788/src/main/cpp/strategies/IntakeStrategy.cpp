#include "strategies/IntakeStrategy.h"

IntakeActuation::IntakeActuation(std::string name, Intake &intake, Controllers &contGroup) : Strategy(name), _intake(intake), _contGroup(contGroup) {
  Requires(&intake);
  SetCanBeInterrupted(true);
  SetCanBeReused(true);
}

void IntakeActuation::OnUpdate(double dt) {
  bool IntakeToggle = false;

  if(_contGroup.Get(ControlMap::Down, wml::controllers::Controller::ONRISE)) {
    if(!IntakeToggle) {
      IntakeToggle = true;
    } else {
      IntakeToggle = false;
    }
  }

  if (!IntakeToggle) {
    //Intake in and out, in with bumper, r for outake
    if (_contGroup.Get(ControlMap::Intake)) {
      _intake.setIntake(IntakeStates::DEPLOYED, ControlMap::IntakeSpeed);
    } else if (_contGroup.Get(ControlMap::Outake)){
      _intake.setIntake(IntakeStates::DEPLOYED, -(ControlMap::IntakeSpeed));
    } else {
      _intake.setIntake(IntakeStates::DEPLOYED, 0);
    }

  } else if (IntakeToggle) {
    _intake.setIntake(IntakeStates::STOWED, 0);
  }
}