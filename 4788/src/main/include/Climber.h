#pragma once 

#include "strategy/StrategySystem.h"
#include "RobotMap.h"


//double linkage 
enum class ClimberState {
  UP,
  DOWN,
};

class Climber : public wml::StrategySystem {
 public:
  Climber(wml::VictorSpx &winch, wml::TalonSrx &climberMotor, wml::actuators::DoubleSolenoid &climberSolenoid);

  void climberUp();
  void climberDown();
  void setClimber(const ClimberState st, double power = 0);
  void setWinch(const ClimberState st, double power = 0);

  void updateClimber(double dt);
  void update(double dt);

 private:
  wml::VictorSpx &_winch;
  wml::TalonSrx &_climberMotor;
  wml::actuators::DoubleSolenoid &_climberSolenoid;

  frc::Timer ClimberTimer; //god i love that rhyme 
  ClimberState _climberState{ ClimberState::DOWN };

  double _power;
  double _winchPower;
};

//skyscraper 

// enum class Climber State {
//   UP,
//   DOWN,
// };

// class Climber : public wml::StrategySystem {
//  public: 
//   Climber(wml::VictorSpx &winch, wml::actuators::DoubleSolenoid &climberSolenoid);

//   void updateCliimber(double dt);
//   void update(double dt);

//  private:
//   wml::VictorSpx &_winch;
//   wml::actuators::DoubleSolenoid &_climberSolenoid;

//   ClimberState _climberState{ ClimberState::DOWN };
// }; 