#include "strategies/ClimberStrategies.h"

ClimberStrategy::ClimberStrategy(std::string name, Climber &climber, Controllers &contGroup) : Strategy(name), _climber(climber), _contGroup(contGroup) {
	Requires(&climber);
  SetCanBeInterrupted(true);
  SetCanBeReused(true);
}

void ClimberStrategy::OnUpdate(double dt) {
	double powerIn = fabs(_contGroup.Get(ControlMap::ClimberUp)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::ClimberUp) : 0;
	double powerOut = fabs(_contGroup.Get(ControlMap::ClimberDown)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::ClimberDown) : 0;

	if(_contGroup.Get(ControlMap::DeployClimber, wml::controllers::Controller::ButtonMode::ONRISE)) {
    if(!ControlMap::ClimberToggle) {
      ControlMap::ClimberToggle = true;
    } else {
      ControlMap::ClimberToggle = false;
    }
  }

  if (!ControlMap::ClimberToggle) {
    _climber.setClimber(ClimberState::MANUAL, powerIn - powerOut);
  } else if (ControlMap::ClimberToggle) {
    _climber.setClimber(ClimberState::MANUAL, 0);
  }
}

