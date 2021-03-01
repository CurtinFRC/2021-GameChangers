#include "strategies/MagStrategy.h" 

MagManualStrategy::MagManualStrategy(std::string name, Mag &mag, Controllers &contGroup) : Strategy(name), _mag(mag), _contGroup(contGroup) {
	Requires(&mag);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);
}

void MagManualStrategy::OnUpdate(double dt) {
	if (_contGroup.Get(ControlMap::MagToggleButton, wml::controllers::ONRISE)) {
		if (!(ControlMap::MagToggle)) {
			ControlMap::MagToggle = true;
		} else {
			ControlMap::MagToggle = false;
		}
	}

	if (!(ControlMap::MagToggle)) {
		_mag.setMag(MagStates::ON);
	} else {
		_mag.setMag(MagStates::OFF);
	}
}