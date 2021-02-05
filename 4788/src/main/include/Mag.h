#pragma once 

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

using Controllers = wml::controllers::SmartControllerGroup;

enum class MagState {
  MANUAL, 
  AUTO, 
};

class Mag : public wml::StrategySystem {
 public:
  Mag(wml::TalonSrx &magMotor, Controllers &contGroup);

  void setMag(const MagState st, double power = 0);

  void updateMag(double dt);
  void update(double dt);
 private:
  wml::TalonSrx &_magMotor;
  Controllers &_contGroup;

  frc::Timer MagTimer;

  double _power;

  MagState _magState{ MagState::MANUAL };
};



// 3G2C57HYE9TEW7R