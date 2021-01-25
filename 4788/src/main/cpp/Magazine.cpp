#include "Magazine.h"

using namespace wml;
using namespace wml::controllers;

Magazine::Magazine(SmartControllerGroup &contGroup, Gearbox &magGearbox) : _contGroup(contGroup), _magGearbox(magGearbox) {}

void Magazine::Limiter() {
  _timer.Start();

  _magTicks = _magGearbox.encoder->GetEncoderTicks(); 
  // ControlMap::MagEncoderSafeZone);

  _timer.Stop();
	_timer.Reset();
}

void Magazine::TeleopOnUpdate(double dt) {
  Limiter();

  if (_contGroup.Get(ControlMap::Outake) >= ControlMap::TriggerDeadzone) {
    _magazinePower = _contGroup.Get(ControlMap::Outake);
    if ((_magTicks - _magPreviouseTicks) >= ControlMap::MagEncoderSafeZone) {
      _magGearbox.transmission->SetVoltage(0 * _magazinePower);
    }
  } else {
    _magazinePower = 0.15;
  }
  //power to motor

  if (_magTicks <= ControlMap::MagEncoderSafeZone) {
    _magGearbox.transmission->SetVoltage(0 * _magazinePower);
  } else {
    _magGearbox.transmission->SetVoltage(12 * _magazinePower);
  }

  _magPreviouseTicks = _magTicks;

}

