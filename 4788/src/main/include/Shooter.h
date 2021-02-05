#pragma once 

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class ShooterState {
  IDLE,
  SPINUP, 
  FIRE,
};

class Shooter : public wml::StrategySystem {
 public:
  Shooter(wml::TalonSrx &shooterMotor, wml::VictorSpx &fireMotor, );

  void updateShooter(double dt);

  void update(double dt);
 private:
  wml::TalonSrx &_shooterMotor;
  wml::VictorSpx &_fireMotor;

  ShooterState _shooterState{ ShooterState::IDLE};
};