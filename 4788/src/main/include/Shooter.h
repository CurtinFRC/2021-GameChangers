#pragma once

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class FlyWheelState {
	OFF,
};

enum class HoodState {
	OFF,
};

enum class TurretState {
	OFF,
};

enum class FireState {
	OFF,
};

class Shooter : public wml::StrategySystem {
 public:
	//flywheel - talon fx 
	//hood - talon srx
	//turret - talon srx 
	//fire motor - talon srx
	Shooter(wml::TalonFX &flyWheelMotor, wml::TalonSrx &hoodMotor, wml::TalonSrx &turretMotor, wml::TalonSrx &fireMotor);

	void setFlywheel(const FlyWheelState st);
	void setHood(const HoodState st);
	void setTurret(const TurretState st);
	void setFire(const FireState st);

	void updateShooter(double dt);
	void update(double dt);

 private:
	wml::TalonFX &_flyWheelMotor;
	wml::TalonSrx &_hoodMotor;
	wml::TalonSrx &_turretMotor;
	wml::TalonSrx &_fireMotor;

	FlyWheelState _flyWheelState{FlyWheelState::OFF};
	TurretState _turretState{TurretState::OFF};
	HoodState _hoodState{HoodState::OFF};
	FireState _fireState{FireState::OFF};

	double _flywheelPower;
	double _turretPower;
	double _hoodPower;
	double _firePower;
};