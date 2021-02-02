#pragma once 

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class ClimberState {
  UP,
  DOWN,
};

class Climber : public wml::StrategySystem {
 public:
  Climber(wml::VictorSpx &winch, wml::actuators::DoubleSolenoid &climberSolenoid);

  void updateClimber(double dt);

  void update(double dt);
 private:
  wml::VictorSpx &_winch;
  wml::actuators::DoubleSolenoid &_climberSolenoid;

  ClimberState _climberState{ ClimberState::DOWN };
};