#pragma once
#include "RobotMap.h"

enum MagazineState {
  ON,
  OFF
};

class Magazine : public wml::StrategySystem {
 public:
  Magazine(wml::Gearbox &magGearbox);
  void setMagazine(const MagazineState st, double magMotorPower1 = 0, double magMotorPower2 = 0);
  void updateMagazine(double dt);
  void update(double dt);

  // int magazineEncoderValue();

 private:
  wml::Gearbox &_magGearbox;
  //wml::Gearbox &_magRotationalAxis; 
  
  MagazineState _magazineState{ MagazineState::OFF };

  double _magMotorPower1; // The washing machine piece
  double _magMotorPower2;
  // bool _toggleEnabled = false;
  // bool _toggleMagOn = false;

  frc::Timer _timer;
};