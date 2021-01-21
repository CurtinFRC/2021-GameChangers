#include "Magazine.h"

using namespace wml;
using namespace wml::controllers;

// Magazine::Magazine(wml::controllers::SmartControllerGroup &contGroup, wml::TalonSrx &magMotor, frc::AnalogInput &Position1, frc::AnalogInput &Position5, bool &p1, bool &p2, bool &p3) : _contGroup(contGroup), _magMotor(magMotor), _position1(Position1), _position5(Position5), _p1(p1), _p2(p2), _p3(p3) {

// }

void Magazine::AutoMag() {
  //Auto

}

void Magazine::TeleopOnUpdate(double dt) {
  if (_contGroup.Get(ControlMap::Outake) >= ControlMap::TriggerDeadzone) {
    MagazinePowerOutake = _contGroup.Get(ControlMap::Outake);
  } else {
    MagazinePowerOutake = 0;
  }

  MagazinePower = 1;

  _magMotor1.Set(MagazinePower);
  _magMotor2.Set(MagazinePowerOutake);
  _magMotor3.Set(MagazinePowerOutake);
}