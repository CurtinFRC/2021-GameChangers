#include "strategies/MagStrategies.h"

MagStrategy::MagStrategy(std::string name, Mag &mag, Controllers &contGroup) : Strategy(name), _mag(mag), _contGroup(contGroup) {
	Requires(&mag);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);
}

void MagStrategy::OnUpdate(double dt) {
	
}