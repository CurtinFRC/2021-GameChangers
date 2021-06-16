#include "strategies/MagStrategy.h" 

MagManualStrategy::MagManualStrategy(std::string name, Mag &mag, Controllers &contGroup) : Strategy(name), _mag(mag), _contGroup(contGroup) {
	Requires(&mag);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);
}

void MagManualStrategy::OnUpdate(double dt) {
	double MagPower = fabs(_contGroup.Get(ControlMap::MagTurn)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::MagTurn) : 0;

	if (fabs(MagPower) > 0) {
		_mag.setMag(MagStates::ON, MagPower);
	} else {
		_mag.setMag(MagStates::OFF, 0);
	}
}