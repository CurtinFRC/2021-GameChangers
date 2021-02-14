#include "strategies/MagStrategies.h"

MagStrategy::MagStrategy(std::string name, Mag &mag, Controllers &contGroup) : Strategy(name), _mag(mag), _contGroup(contGroup) {
	Requires(&mag);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);
}

void MagStrategy::OnUpdate(double dt) {
	if (_contGroup.Get(ControlMap::MagSpin, wml::controllers::Controller::ButtonMode::ONRISE)) {
		if (!ControlMap::MagToggle) {
			ControlMap::MagToggle = true;
		} else {
			ControlMap::MagToggle = false;
		}
	}

	if (!ControlMap::MagToggle) {
		_mag.setMag(MagState::MANUAL, ControlMap::MagSpeed);
	} else if (ControlMap::MagToggle) {
		_mag.setMag(MagState::MANUAL, 0);
	}
}