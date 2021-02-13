#include "Magazine.h"

using namespace wml;
using namespace wml::controllers;

Magazine::Magazine(TalonSrx &magMotor1, VictorSpx &magMotor2) : _magMotor1(magMotor1), _magMotor2(magMotor2) {}

// int Magazine::magazineEncoderValue() {
// 	return(_magGearbox.encoder->GetEncoderTicks());
// }

void Magazine::setMagazine(const MagazineState st, double magMotorPower1, double magMotorPower2) {
  _magazineState = st;
  _magMotorPower1 = magMotorPower1;
  _magMotorPower2 = magMotorPower2;
}

void Magazine::updateMagazine(double dt) {

  switch(_magazineState) {
		case MagazineState::OFF: // Stowed Control
			_magMotorPower1 = 0;
      _magMotorPower2 = 0;
			break;

		case MagazineState::ON: // Deployed Control
			_magMotorPower1 = 1; // private class _power modified by strategies/MagazineStrategies
      _magMotorPower2 = 0.6;
			break;
  }

  _magMotor1.Set(_magMotorPower1);
  _magMotor2.Set(_magMotorPower2);
}


void Magazine::update(double dt) {
  updateMagazine(dt);
}