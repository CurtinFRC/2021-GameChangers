#pragma once
#include "RobotMap.h"

enum MagazineState {
  ON,
  OFF
};

class Magazine : public wml::StrategySystem {
 public:
  Magazine(wml::TalonSrx &magMotor1, wml::VictorSpx &magMotor2);
  void setMagazine(const MagazineState st, double magMotorPower1 = 1, double magMotorPower2 = 0.6);
  void updateMagazine(double dt);
  void update(double dt);

  // int magazineEncoderValue();

 private:

  wml::TalonSrx &_magMotor1;
  wml::VictorSpx &_magMotor2;
  
  MagazineState _magazineState{ MagazineState::OFF };

  double _magMotorPower1; // The washing machine piece
  double _magMotorPower2;
  // bool _toggleEnabled = false;
  // bool _toggleMagOn = false;

  frc::Timer _timer;
};