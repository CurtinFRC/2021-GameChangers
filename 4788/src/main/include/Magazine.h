#pragma once

#include <iostream> 
#include "RobotMap.h"

class Magazine {
 public:
  Magazine(wml::controllers::SmartControllerGroup &contGroup, wml::Gearbox &magGearbox);

  void TeleopOnUpdate(double dt);
  void Limiter();

 private:
  wml::controllers::SmartControllerGroup &_contGroup;
  wml::Gearbox &_magGearbox;
  // wml::Gearbox &_magRotationalAxis; 

  double _magazinePower; // The washing machine piece
  double _magTicks; // If WM gets jammed
  double _magPreviouseTicks;
  bool _toggleEnabled = false;
  bool _toggleMagOn = false;

  frc::Timer _timer;
};