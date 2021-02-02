#pragma once 

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class MagState {
  AUTO, 
  MANUAL, 
};

class Mag : public wml::StrategySystem {
 public:
  Mag(wml::TalonSrx &magMotor, wml::VictorSpx &fireMotor);

  void updateMag(double dt);

  void update(double dt);
 private:
  wml::TalonSrx &_magMotor;
  wml::VictorSpx &_fireMotor;

  MagState _magState{ MagState::MANUAL };
};

// 3G2C57HYE9TEW7R