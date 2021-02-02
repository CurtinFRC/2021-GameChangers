#include "Shooter.h" 

Shooter::Shooter(wml::TalonSrx &shooterMotor, wml::VictorSpx &fireMotor) : _shooterMotor(shooterMotor), _fireMotor(fireMotor) {}

void Shooter::updateShooter(double dt) {

}

void Shooter::update(double dt) {
  updateShooter(dt);
}