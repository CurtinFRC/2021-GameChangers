#pragma once 

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class ClimberState {
	MANUAL
};

class Climber : public wml::StrategySystem {
 public:
	Climber(wml::TalonSrx &climberMotor);

	void setClimber(const ClimberState st, double power = 0);

	void updateClimber(double dt);
	void update(double dt);
 private:
	wml::TalonSrx &_climberMotor;

	ClimberState _climberState{ ClimberState::MANUAL };
	double setPower = 0;
	double _power;
};