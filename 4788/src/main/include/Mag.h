#pragma once 

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class MagStates {
	ON,
	OFF,
	REVERSE
};

class Mag : public wml::StrategySystem {
 public:
	Mag(wml::TalonSrx &magMotor);

	void setMag(const MagStates st, double power);

	void updateMag(double dt);
	void update(double dt);

 private:
	wml::TalonSrx &_magMotor;

	MagStates _magState{MagStates::OFF};

	double _power;
};