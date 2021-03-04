#pragma once

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class IntakeStates {
	STOWED,
	DEPLOYED
};

class Intake : public wml::StrategySystem {
 public:
	Intake(wml::TalonSrx &intakeMotor, wml::actuators::DoubleSolenoid &intakeSolenoid);

	void setIntake(const IntakeStates st, double power = 0);

	void updateIntake(double dt);
	void update(double dt);
 private:
	wml::TalonSrx &_intakeMotor;
	wml::actuators::DoubleSolenoid &_intakeSolenoid;

	IntakeStates _intakeState{ IntakeStates::STOWED};

	double _power;
};