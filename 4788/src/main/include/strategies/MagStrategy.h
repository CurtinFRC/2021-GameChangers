#pragma once

#include "Mag.h"
#include "strategy/Strategy.h"

using Controllers = wml::controllers::SmartControllerGroup;

class MagManualStrategy : public wml::Strategy {
 public:
	MagManualStrategy(std::string name, Mag &mag, Controllers &contGroup);

	void OnUpdate(double dt) override;

 private:
	Mag &_mag;
	Controllers &_contGroup;
};