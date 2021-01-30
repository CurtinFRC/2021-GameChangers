#include "strategies/MagazineStrategies.h"

MagazineManualStrategy::MagazineManualStrategy(std::string name, Magazine &magazine, Controllers &contGroup) : Strategy(name), _magazine(magazine), _contGroup(contGroup) {
	Requires(&magazine);
  SetCanBeInterrupted(true);
  SetCanBeReused(true);
}

void MagazineManualStrategy::OnUpdate(double dt) {
	// _magTicks = _magazine.magazineEncoderValue();

	// Controls power in power out
	double powerIn = fabs(_contGroup.Get(ControlMap::Outake)) >= ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Outake) : 0;
	double powerOut = fabs(_contGroup.Get(ControlMap::Outake)) <= ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Outake) : 0;

	if (_contGroup.Get(ControlMap::Outake) >= ControlMap::TriggerDeadzone) {
		_magazine.setMagazine(MagazineState::ON, 0.6);
		// _magazine.setMagazine(MagazineState::ON, powerIn - powerOut);
		// if ((_magTicks - _magPreviouseTicks) >= ControlMap::MagEncoderSafeZone) {
		// 	_magazine.setMagazine(MagazineState::OFF, 0);
		// }
	} else {
		_magazine.setMagazine(MagazineState::OFF, 0);
	}


}