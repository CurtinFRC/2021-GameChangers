#include "Climber.h"

// telescoping 
Climber::Climber(wml::VictorSpx &winch, wml::TalonSrx &climberMotor, wml::actuators::DoubleSolenoid &climberSolenoid) : _winch(winch), _climberMotor(climberMotor), _climberSolenoid(climberSolenoid) {}

void Climber::climberUp() {
  //climber goes all the way to the top, go until encoder doesnt register a change
  bool climberTop = false; //put this somewhere else reeeeeeeeeeeeeeeeeeeeeeee

  if (_climberMotor.GetEncoderAngularVelocity() == 0) {
    ClimberTimer.Start();
    if (ClimberTimer.Get() > 1) {
      climberTop = true;
    }
  } else {
    ClimberTimer.Reset();
    ClimberTimer.Stop();
  }

  if (climberTop) {
    _climberMotor.Set(0);
    _climberState = ClimberState::UP;
  } else {
    _climberMotor.Set(ControlMap::ClimberUpSpeed);
  }
}

void Climber::climberDown() {
  bool climberDown = false;

  if (_climberMotor.GetEncoderAngularVelocity() == 0) {
    ClimberTimer.Start();
    if (ClimberTimer.Get() > 1) {
      climberDown = true;
    }
  } else {
    ClimberTimer.Reset();
    ClimberTimer.Stop();
  }

  if (!climberDown) {
    _climberMotor.Set(0);
    _climberState = ClimberState::DOWN;
  } else {
    _climberMotor.Set(-(ControlMap::ClimberUpSpeed));
  }
}

void Climber::setClimber(const ClimberState st, double power) {
  _power = power;
  _climberState = st;
}

void Climber::setWinch(const ClimberState st, double power) {
  _winchPower = power;
  _climberState = st;
}

void Climber::updateClimber(double dt) {
  double setPower;
  double winchSetPower;

  switch (_climberState) {
      case ClimberState::UP:
        // make the climber go all the way up
        winchSetPower = _winchPower;
        setPower = _power;
        break;

      case ClimberState::DOWN:
        setPower = 0;
        winchSetPower = 0;
        break;
  }
  _climberMotor.Set(setPower);
  _winch.Set(winchSetPower);
}

void Climber::update(double dt) {
  updateClimber(dt);
}
