#pragma once
#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class ClimberState {
	ENABLED,
	EXTENDING,
	DISABLED,
	JAMMED
};

class Climber : public wml::StrategySystem{
  public :
	// Constructor
    Climber(wml::TalonSrx &ClimberMotor);

		//Set climber state and power
		void setClimber(const ClimberState, double power = 0);

		// Looping and update for climber
		void updateClimber(double dt);

		// Update (master loop for Climber)
		void update (double dt);

		int climberEncoderValue();

		
		/*
		// Setup Functions
		void TeleopOnUpdate (double dt);
		void AutoOnUpdate(double dt);
 		void TestOnUpdate(double dt);
		 */

  private :
		wml::TalonSrx &_climberMotor;
		ClimberState _climberState{ ClimberState::DISABLED };

		double _power;
};