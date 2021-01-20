#include <iostream>

#include "Turret.h"

using namespace frc;
using namespace wml;

Turret::Turret(Gearbox &Rotation, Gearbox &VerticalAxis,  Gearbox &FlyWheel):
_RotationalAxis(Rotation), _VerticalAxis(VerticalAxis),  _FlyWheel(FlyWheel) {}

void Turret::ShooterInit() {
  _kP = 0;
  _kI = 0;
  _kD = 0;
  _previousError = 0;
  _sum = 0;
  _goal = 0;
}

void Turret::Shooter(double dt, double input) {
  double error = _goal - input;
  double derror = (error - _previousError) / dt;
  _sum = _sum + error * dt;

  double output = _kP * error + _kI * _sum + _kD * derror;

  _previousError = error;

  _FlyWheel.transmission->SetVoltage(output);
}