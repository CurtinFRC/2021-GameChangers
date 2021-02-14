#pragma once 

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class IntakeState {
	MANUAL, 
};

class Intake : public wml::StrategySystem {
 public:
	Intake(wml::VictorSpx &intakeMotor);

	void setIntake(const IntakeState st, double power = 0);

	void updateIntake(double dt);
	void update(double dt);
 private:
	wml::VictorSpx &_intakeMotor;
	
	IntakeState _intakeState{ IntakeState::MANUAL };
	double _power;
	double setPower = 0;
};