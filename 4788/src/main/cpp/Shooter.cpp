#include "Shooter.h"

Shooter::Shooter(wml::TalonFX &flyWheelMotor, wml::TalonSrx &hoodMotor, wml::TalonSrx &turretMotor, wml::TalonSrx &fireMotor) : _flyWheelMotor(flyWheelMotor), _hoodMotor(hoodMotor), _turretMotor(turretMotor), _fireMotor(fireMotor) {}

void Shooter::setFlywheel(double power) {

}

void Shooter::setHood(double power) {

}

void Shooter::setTurret(double power) {

}

void Shooter::setFire(double power) {

}

void Shooter::updateShooter(double dt) {
	double setFlyPower = 0;
	double setHoodPower = 0;
	double setTurretPower = 0;
	double setFirePower = 0;

	switch (_shooterState) {
		case ShooterState::ON:
			
			break;
		case ShooterState::OFF:
			
			break;
	}
}

void Shooter::update(double dt) {
	updateShooter(dt);
}