#pragma once

#include <iostream> 
#include "RobotMap.h"

class Magazine {
 public:
  Magazine(wml::controllers::SmartControllerGroup &contGroup, wml::Gearbox &magGearbox);

  void TeleopOnUpdate(double dt);

 private:
  wml::controllers::SmartControllerGroup &_contGroup;
  wml::Gearbox &_magGearbox;

  double _magazinePower; // The washing machine piece
  bool _toggleEnabled = false;
  bool _toggleMagOn = false;

  frc::Timer _timer;
};