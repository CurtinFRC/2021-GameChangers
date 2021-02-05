#include "strategies/ClimberStrategy.h"

ClimberStrategy::ClimberStrategy(std::string name, Climber &climber, Controllers &contGroup) : Strategy(name), _climber(climber), _contGroup(contGroup) {
  Requires(&climber);
  SetCanBeInterrupted(true);
  SetCanBeReused(true);
}

void ClimberStrategy::OnUpdate(double dt) {
  bool ClimberUp = false;
  double winchUpPower = fabs(_contGroup.Get(ControlMap::WinchUp)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::WinchUp) : 0;

  if (ClimberUp) { //the climber has been deployed 
    //winch
    if (_contGroup.Get(ControlMap::WinchDown)) {
      _climber.setWinch(ClimberState::UP, ControlMap::WinchDownPower);
    } else {
      _climber.setWinch(ClimberState::UP, winchUpPower);
    }

    //adjust climber height with bumpers
    if (_contGroup.Get(ControlMap::ClimberUp)) {
      _climber.setClimber(ClimberState::UP, ControlMap::climberAdjustSpeed);
    } else if (_contGroup.Get(ControlMap::ClimberDown)){
      _climber.setClimber(ClimberState::UP, -(ControlMap::climberAdjustSpeed));
    } else {
      _climber.setClimber(ClimberState::UP, 0);
    }

    if (_contGroup.Get(ControlMap::ClimberBottom)) {
      _climber.climberDown();
      ClimberUp = false;
    }
  } else {
    if (_contGroup.Get(ControlMap::ClimberTop, wml::controllers::Controller::ONFALL)) {
      _climber.climberUp();
      ClimberUp = true;
    }
  }
}


