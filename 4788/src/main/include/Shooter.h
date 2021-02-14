#pragma once 

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class ShooterState {
	MANUAL, 
};

class Shooter : public wml::StrategySystem {
 public:
	Shooter(wml::VictorSpx &shooterMotor, wml::VictorSpx &fireMotor);

	void setShooter(const ShooterState st, double power = 0);
	void setFire(const ShooterState st, double power = 0);

	void updateShooter(double dt);
	void update(double dt);
 private:
	wml::VictorSpx &_shooterMotor;
	wml::VictorSpx &_fireMotor;

	ShooterState _shooterState{ ShooterState::MANUAL};
	double _power;
	double _firePower; 
	double setPower = 0;
	double firePower = 0;
};