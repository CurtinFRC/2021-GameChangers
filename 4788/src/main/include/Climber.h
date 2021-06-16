#pragma once 

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class ClimberStates {
	UP, 
	DOWN
};

class Climber : public wml::StrategySystem {
	public: 
		Climber(wml::VictorSpx &climberMotor);

		void setClimber(const ClimberStates cs, double power = 0);

		void updateClimber(double dt);
		void update(double dt);
	private: 
		wml::VictorSpx &_climberMotor;
		
		ClimberStates _climberStates{ ClimberStates::DOWN };

		double _power;
};