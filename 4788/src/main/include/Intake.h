#pragma once

#include <iostream> 
#include "RobotMap.h"

class Intake {
  public:
   Intake( wml::controllers::SmartControllerGroup &contGroup, wml::actuators::DoubleSolenoid &IntakeDown, wml::TalonSrx &IntakeMotor);

   /**
    * This is the discription for intake telop
    */
   void TeleopOnUpdate(double dt);

  private:
   wml::controllers::SmartControllerGroup &_contGroup;
   wml::actuators::DoubleSolenoid &_IntakeDown;
   wml::TalonSrx &_intakeMotor;
   frc::Timer _timer;
     
   double speedIntake;
   bool _ToggleEnabled = false;
   bool _ToggleIntakeOn = false;
};
