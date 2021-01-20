#pragma once

#include <iostream> 
#include "RobotMap.h"

class Magazine {
  public:
   Magazine(wml::controllers::SmartControllerGroup &contGroup, wml::TalonSrx &magMotor, wml::TalonSrx &magMotorFunnelLeft, wml::TalonSrx &magMotorFunnelRight, frc::AnalogInput &Position1, frc::AnalogInput &Position5,  bool &p1, bool &p2, bool &p3);

   void TeleopOnUpdate(double dt);

  private:
   wml::controllers::SmartControllerGroup &_contGroup;
   wml::TalonSrx &_magMotor;
   wml::TalonSrx &_magMotorLeft;
   wml::TalonSrx &_magMotorRight;
   frc::AnalogInput &_position1;
   frc::AnalogInput &_position5;

   //Auto Ball Detection
   void AutoMag();

   double MagazinePower; // not funnel piece
   double MagazinePowerFunnelLeft; //funnel piece left side
   double MagazinePowerFunnelRight; //funnel piece right side

   bool &_strt;
	 bool &_p1;
	 bool &_p2;
	 bool &_p3;

   frc::Timer _timer;


};