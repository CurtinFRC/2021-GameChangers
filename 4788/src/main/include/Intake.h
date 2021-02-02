#pragma once

#include "strategy/StrategySystem.h" // In WML (Note strategy system. NOT STRATEGY.H. Strategy.h is for the actual strategy in include/strategy/IntakeStrategies.h)
#include "RobotMap.h" // Our robotmap


/**
 * Declared states the intake can be in
 */
enum class IntakeStates {
	ASTOWED, // Up, motor off
	ADEPLOYED, // Down, motor on (variable speed)
	MSPINFORWARD,
	MSPINBACKWARDS,
	MSTOP,
};

/**
 * Main intake class
 */
class Intake : public wml::StrategySystem {
 public:

	Intake(wml::VictorSpx &intakeMotor, wml::actuators::DoubleSolenoid &intakeSolenoid);

	void setIntake(const IntakeStates st, double power = 0);

	void updateIntake(double dt);

	void update(double dt);

 private:
	// Class controllable gearboxes
	wml::VictorSpx &_intakeMotor;
	wml::actuators::DoubleSolenoid &_intakeSolenoid;

	// States
	IntakeStates _intakeState{ IntakeStates::MSTOP };

	// intake motor power
	double _power;
};