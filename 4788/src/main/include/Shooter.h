#pragma once

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class ShooterState {
	ON,
	OFF,
};

class Shooter : public wml::StrategySystem {
	public:
	Shooter(wml::VictorSpx &flyWheelMotor, wml::VictorSpx &fireMotor);

	void setFlywheel(double power);
	void setFire(double power);

	void updateShooter(double dt);
	void update(double dt);

 private:
	wml::VictorSpx &_flyWheelMotor;
	wml::VictorSpx &_fireMotor;

	ShooterState _shooterState{ShooterState::ON};

	double _flywheelPower;
	double _firePower;
};