#pragma once 

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class MagState {
	MANUAL,
};

class Mag : public wml::StrategySystem {
 public:
	Mag(wml::TalonSrx &magMotor);

	void setMag(const MagState st, double power = 0);

	void updateMag(double dt);
	void update(double dt);
 private:
	wml::TalonSrx &_magMotor;

	MagState _magState{ MagState::MANUAL };
	double _power;
	double setPower = 0;
};