#include "Shooter.h"

Shooter::Shooter(wml::TalonSrx &shooterMotor, wml::TalonSrx &fireMotor) : _shooterMotor(shooterMotor), _fireMotor(fireMotor) {}

void Shooter::setIntake(const ShooterStates st, double power) {
  _intakeStates = st;
  _power = power;
}

void Shooter::updateShooter(double dt) {
  switch(_intakeStates) {
    case ShooterStates::WARMUP:
      //run shooter motor 
      _shooterMotor->Set(_power);
    break;
    case ShooterStates::FIRE:
      //run shooter and fire motor 
      _shooterMotor->Set(_power);
      _fireMotor->Set(_power);

    break;
  }
}