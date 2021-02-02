#include "Magazine.h"

using namespace wml;
using namespace wml::controllers;

Magazine::Magazine(Gearbox &magGearbox) : _magGearbox(magGearbox) {}

// int Magazine::magazineEncoderValue() {
// 	return(_magGearbox.encoder->GetEncoderTicks());
// }

void Magazine::setMagazine(const MagazineState st, double magMotorPower1, double magMotorPower2) {
  _magazineState = st;
  _magMotorPower1 = magMotorPower1;
  _magMotorPower2 = magMotorPower2;
}

void Magazine::updateMagazine(double dt) {
  double voltage = 0;

  switch(_magazineState) {
		case MagazineState::OFF: // Stowed Control
			voltage = 0;
			break;

		case MagazineState::ON: // Deployed Control
			voltage = 12 * _magMotorPower1; // private class _power modified by strategies/MagazineStrategies
			voltage = 12 * _magMotorPower2;
			break;
  }

  _magGearbox.transmission->SetVoltage(voltage);
}


void Magazine::update(double dt) {
  updateMagazine(dt);
}