#pragma once 

#include "Climber.h"
#include "strategy/Strategy.h"

using Controllers = wml::controllers::SmartControllerGroup;

class ClimberManualStrategy : public wml::Strategy {
	public: 
		ClimberManualStrategy(std::string name, Climber &climber, Controllers &contGroup);

		void OnUpdate(double dt) override;
	private:
		Climber &_climber;
		Controllers &_contGroup;

		double power = 0;
};