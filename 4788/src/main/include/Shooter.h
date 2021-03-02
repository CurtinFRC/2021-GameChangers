#pragma once

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class ShooterState {
	ON,
	OFF,
};

class Shooter : public wml::StrategySystem {
 public:
	//flywheel - talon fx 
	//hood - talon srx
	//turret - talon srx 
	//fire motor - talon srx
	Shooter(wml::TalonFX &flyWheelMotor, wml::TalonSrx &hoodMotor, wml::TalonSrx &turretMotor, wml::TalonSrx &fireMotor);

	void setFlywheel(double power);
	void setHood(double power );
	void setTurret(double power );
	void setFire(double power);

	void updateShooter(double dt);
	void update(double dt);

 private:
	wml::TalonFX &_flyWheelMotor;
	wml::TalonSrx &_hoodMotor;
	wml::TalonSrx &_turretMotor;
	wml::TalonSrx &_fireMotor;

	// // FlyWheelState _flyWheelState{FlyWheelState::OFF};
	// // TurretState _turretState{TurretState::OFF};
	// // HoodState _hoodState{HoodState::OFF};
	// // FireState _fireState{FireState::OFF};
	ShooterState _shooterState{ShooterState::OFF};

	double _flywheelPower;
	double _turretPower;
	double _hoodPower;
	double _firePower;
};