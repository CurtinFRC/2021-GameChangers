#pragma once

#include "Intake.h"
#include "strategy/Strategy.h"

using Controllers = wml::controllers::SmartControllerGroup;

class IntakeManualStrategy : public wml::Strategy {
 public:
	IntakeManualStrategy(std::string name, Intake &intake, Controllers &contGroup);

	void OnUpdate(double dt) override;
 private:
	Intake &_intake;
	Controllers &_contGroup;

	double powerIn = 0;
	double powerOut = 0;
};