#include "strategies/MagStrategy.h"

MagStrategy::MagStrategy(std::string name, Mag &mag, Controllers &contGroup) : Strategy(name), _mag(mag), _contGroup(contGroup) {
  Requires(&mag);
  SetCanBeInterrupted(true);
  SetCanBeReused(true);
}

void MagStrategy::OnUpdate(double dt) {
  double MagPower = fabs(_contGroup.Get(ControlMap::MagForwards)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::MagForwards) : 0;
  if (MagPower > 0) {
    _mag.setMag(MagState::MANUAL, MagPower);
  } else if (_contGroup.Get(ControlMap::MagBackwards)) {
    _mag.setMag(MagState::MANUAL, ControlMap::MagBackSpeed);
  } else {
    _mag.setMag(MagState::AUTO, 0);
  }
}
