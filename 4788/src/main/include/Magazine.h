#pragma once

#include <iostream> 
#include "RobotMap.h"

class Magazine {
  public:
   Magazine(wml::controllers::SmartControllerGroup &contGroup, wml::TalonSrx &magMotor1, wml::TalonSrx &magMotor2, wml::TalonSrx &magMotor3);

   void TeleopOnUpdate(double dt);

  private:
   wml::controllers::SmartControllerGroup &_contGroup;
   wml::TalonSrx &_magMotor1;
   wml::TalonSrx &_magMotor2;
   wml::TalonSrx &_magMotor3;

   //Auto Ball Detection
   void AutoMag();

   double MagazinePower; // The washing machine piece
   double MagazinePowerOutake; // The outake
   bool _ToggleEnabled = false;
   bool _ToggleMagOn = false;

   frc::Timer _timer;


};