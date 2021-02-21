#include "strategies/MagazineStrategies.h"

MagazineManualStrategy::MagazineManualStrategy(std::string name, Magazine &magazine, Controllers &contGroup) : Strategy(name), _magazine(magazine), _contGroup(contGroup) {
	Requires(&magazine);
  SetCanBeInterrupted(true);
  SetCanBeReused(true);
}

void MagazineManualStrategy::OnUpdate(double dt) {
	// _magTicks = _magazine.magazineEncoderValue();

	// Controls power in power out
	// double powerIn = fabs(_contGroup.Get(ControlMap::Outake)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Outake) : 0;
	double powerOutL = _contGroup.Get(ControlMap::MagLeft);
	double powerOutR = _contGroup.Get(ControlMap::MagRight);
	bool magOutakeToggle = false;
	bool magReverseToggle = false;

	// if (_contGroup.Get(ControlMap::Outake) >= ControlMap::TriggerDeadzone) {
	// 	_magazine.setMagazine(MagazineState::ON, powerOut, powerOut);
	// 	// _magazine.setMagazine(MagazineState::ON, powerOut);
	// 	// if ((_magTicks - _magPreviouseTicks) >= ControlMap::MagEncoderSafeZone) {
	// 	// 	_magazine.setMagazine(MagazineState::OFF, 0);
	// 	// }
	// } else {
	// 	_magazine.setMagazine(MagazineState::OFF);
	// }

	// tPOV is not button. You have to make it into a pseudo button. Look at 2020 code controlmap
	// if(_contGroup.Get(ControlMap::Outake, wml::controllers::Controller::ButtonMode::ONRISE)) {
  //   if(!MagazineToggle) {
  //     MagazineToggle = true;
  //   } else {
  //     MagazineToggle = false;
  //   }
  // }

  // if (!MagazineToggle) {
  //   _magazine.setMagazine(MagazineState::ON, powerOut, powerOut);
  // } else {
  //   _magazine.setMagazine(MagazineState::OFF);
  // }

	if(_contGroup.Get(ControlMap::MagRight, wml::controllers::Controller::ButtonMode::ONRISE)) {
		magOutakeToggle = true;
	} else {
		magOutakeToggle = false;
	}

	if(_contGroup.Get(ControlMap::MagLeft, wml::controllers::Controller::ButtonMode::ONRISE)) {
		magReverseToggle = true;
	} else {
		magReverseToggle = false;
	}

	if(magReverseToggle == true) {
		_magazine.setMagazine(MagazineState::REVERSE, powerOutL, powerOutL);
	} else {
		_magazine.setMagazine(MagazineState::OFF);
	}

	if(magOutakeToggle == true) {
		_magazine.setMagazine(MagazineState::ON, powerOutR, powerOutR);
	} else {
		_magazine.setMagazine(MagazineState::OFF);
	}
}

 