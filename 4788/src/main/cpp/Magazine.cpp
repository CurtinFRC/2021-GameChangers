#include "Magazine.h"
#include <iostream>

using namespace wml;
using namespace wml::controllers;

Magazine::Magazine(wml::TalonSrx &magMotor1, wml::VictorSpx &magMotor2) : _magMotor1(magMotor1), _magMotor2(magMotor2) {}

// int Magazine::magazineEncoderValue() {
// 	return(_magGearbox.encoder->GetEncoderTicks());
// }

void Magazine::setMagazine(const MagazineState st, double magMotorPower1, double magMotorPower2) {
  _magazineState = st;
  _magMotorPower1 = magMotorPower1;
  _magMotorPower2 = magMotorPower2;
}

void Magazine::updateMagazine(double dt) {
  double voltage1 = 0;
  double voltage2 = 0;

  switch(_magazineState) {
		case MagazineState::OFF: // Stowed Control
			voltage1 = 0;
      voltage2 = 0;
			break;

		case MagazineState::ON: // Deployed Control
			voltage1 = 12 * _magMotorPower1; // private class _power modified by strategies/MagazineStrategies
			voltage2 = 12 * _magMotorPower2;
			break;
  }

  _magMotor1.Set(voltage1);
  _magMotor2.Set(voltage2);
}


void Magazine::update(double dt) {
  updateMagazine(dt);
}