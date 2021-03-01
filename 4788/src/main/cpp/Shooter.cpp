#include "Shooter.h"

Shooter::Shooter(wml::TalonFX &flyWheelMotor, wml::TalonSrx &hoodMotor, wml::TalonSrx &turretMotor, wml::TalonSrx &fireMotor) : _flyWheelMotor(flyWheelMotor), _hoodMotor(hoodMotor), _turretMotor(turretMotor), _fireMotor(fireMotor) {}

void Shooter::updateShooter(double dt) {

}

void Shooter::update(double dt) {
	updateShooter(dt);
}