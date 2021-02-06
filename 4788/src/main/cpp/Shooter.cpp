#include "Shooter.h" 

Shooter::Shooter(wml::VictorSpx &fireMotor, wml::TalonSrx &hoodMotor, wml::TalonSrx &shooterMotor, wml::TalonSrx &turretMotor) : _fireMotor(fireMotor), _hoodMotor(hoodMotor), _shooterMotor(shooterMotor), _turretMotor(turretMotor) {}

void Shooter::updateShooter(double dt) {

}

void Shooter::update(double dt) {
  updateShooter(dt);
}