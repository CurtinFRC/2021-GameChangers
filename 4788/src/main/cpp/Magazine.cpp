#include "Magazine.h"

using namespace wml;
using namespace wml::controllers;

Magazine::Magazine(SmartControllerGroup &contGroup, Gearbox &magGearbox) : _contGroup(contGroup), _magGearbox(magGearbox) {}

void Magazine::TeleopOnUpdate(double dt) {
  if (_contGroup.Get(ControlMap::Outake) >= ControlMap::TriggerDeadzone) {
    _magazinePower = _contGroup.Get(ControlMap::Outake);
  } else {
    _magazinePower = 0.15;
  }

  _magGearbox.transmission->SetVoltage(12 * _magazinePower);
}