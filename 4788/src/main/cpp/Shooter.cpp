#include "Shooter.h"

Shooter::Shooter(wml::TalonFX &flyWheelMotor, wml::TalonSrx &hoodMotor, wml::TalonSrx &turretMotor, wml::TalonSrx &fireMotor) : _flyWheelMotor(flyWheelMotor), _hoodMotor(hoodMotor), _turretMotor(turretMotor), _fireMotor(fireMotor) {}

void Shooter::setFlywheel(double power) {
	_flywheelPower = power;
}

void Shooter::setHood(double power) {
	_hoodPower = power;
}

void Shooter::setTurret(double power) {
	_turretPower = power;
}

void Shooter::setFire(double power) {
	_firePower = power;
}

void Shooter::updateShooter(double dt) {
	double setFlyPower = 0;
	double setHoodPower = 0;
	double setTurretPower = 0;
	double setFirePower = 0;

	switch (_shooterState) {
		case ShooterState::ON:
			setFlyPower = _flywheelPower;
			setHoodPower = _hoodPower;
			setTurretPower = _turretPower;
			setFirePower = _firePower;
			break;
		case ShooterState::OFF:
			setFlyPower = 0;
			setHoodPower = 0;
			setTurretPower = 0;
			setFirePower = 0;
			break;
	}

	_flyWheelMotor.Set(setFlyPower);
	_hoodMotor.Set(setHoodPower);
	_turretMotor.Set(setTurretPower);
	_fireMotor.Set(setFirePower);

}

void Shooter::update(double dt) {
	updateShooter(dt);
}