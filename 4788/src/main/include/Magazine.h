#pragma once
#include <iostream> 
#include "RobotMap.h"
#include "strategy/StrategySystem.h"

enum class MagazineState {
  ON,
  OFF,
};

class Magazine : public wml::StrategySystem {
 public:
  Magazine(wml::Gearbox &magGearbox);
  void setMagazine(const MagazineState st, double magPower = 0);
  void updateMagazine(double dt);
  void update(double dt);

  int magazineEncoderValue();

 private:
  wml::Gearbox &_magGearbox;
  // wml::Gearbox &_magRotationalAxis; 
  
  MagazineState _magazineState{ MagazineState::OFF };

  double _magPower; // The washing machine piece
  bool _toggleEnabled = false;
  bool _toggleMagOn = false;

  // frc::Timer _timer;
};
