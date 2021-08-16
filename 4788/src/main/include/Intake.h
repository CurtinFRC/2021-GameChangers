#pragma once

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class IntakeStates {
	ON,
	OFF
};

class Intake : public wml::StrategySystem {
 public:
	Intake(wml::VictorSpx &intakeMotor);

	void setIntake(const IntakeStates st, double power = 0);

	void updateIntake(double dt);
	void update(double dt);
 private:
	wml::VictorSpx &_intakeMotor;

	IntakeStates _intakeState{ IntakeStates::OFF};

	double _power;
};