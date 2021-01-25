#pragma once
#include "RobotMap.h"

enum class ClimberState {
	NORMAL,
	JAMMED
}

class Climber {
  public :
	// Constructor
    Climber(wml::controllers::SmartControllerGroup &contGroup, wml::TalonSrx &ClimberMotor);

		//Set climber state and power
		void setClimber(const ClimberState, double power = 0);

		// Looping and update for climber
		void updateClimber(double dt);

		// Update (master loop for Climber)
		void update (double dt);
		/*
		// Setup Functions
		void TeleopOnUpdate (double dt);
		void AutoOnUpdate(double dt);
 		void TestOnUpdate(double dt);
		 */

  private :
		wml::controllers::SmartControllerGroup &_contGroup;
		wml::TalonSrx &_ClimberMotor;
		ClimberState _climberState{ ClimberState::NORMAL };

		double _power;
};