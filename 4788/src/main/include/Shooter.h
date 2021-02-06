#pragma once 

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class ShooterState {
  ZERO,
  IDLE,
  MANUALAIM,
  AUTOAIM,
  SHOOTING,
};

class Shooter : public wml::StrategySystem {
 public:
  Shooter(wml::VictorSpx &fireMotor, wml::TalonSrx &hoodMotor, wml::TalonSrx &shooterMotor, wml::TalonSrx &turretMotor);

  void updateShooter(double dt);
  void update(double dt);
 private:
  wml::TalonSrx &_shooterMotor;
  wml::VictorSpx &_fireMotor;
  wml::TalonSrx &_hoodMotor;
  wml::TalonSrx &_turretMotor;

  ShooterState _shooterState{ ShooterState::IDLE};
};