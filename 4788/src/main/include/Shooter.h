#pragma once 

#include "strategies/StrategySystem.h"
#include "RobotMap.h"

enum class ShooterStates {
  WARMUP, 
  FIRE,
};

class Shooter : public wml::StrategySystem {
 public:
  Shooter(wml::TalonSrx &shooterMotor, wml::TalonSrx &fireMotor);

  void setShooter(const ShooterStates st, double power = 0);
  void updateShooter(double dt);
  void update(double dt);
 private:
  wml::TalonSrx &_shooterMotor;
	wml::TalonSrx &_fireMotor;

  ShooterStates _shooterStates{ ShooterStates::MARMUP}; 
  double _power;
};