#include "Turret.h"
#include <iostream>

using namespace frc;
using namespace wml;

Turret::Turret(Gearbox &Rotation, Gearbox &VerticalAxis,  Gearbox &FlyWheel,  sensors::BinarySensor &LeftLimit,  sensors::BinarySensor &AngleDownLimit):
_RotationalAxis(Rotation), _VerticalAxis(VerticalAxis),  _FlyWheel(FlyWheel),  _LeftLimit(LeftLimit),  _AngleDownLimit(AngleDownLimit) {}

void Turret::ShooterInit() {
  double _kP = 0;
  double _kI = 0;
  double _kD = 0;
  double _previousError = 0;
  double _sum = 0;
  double _goal = 0;
}

void Turret::Shooter(double dt, double input) {
  double error = _goal - input;
  double derror = (error - _previousError) / dt;
  _sum = _sum + error * dt;

  double output = _kP * error + _kI * _sum + _kD * derror;

  _previousError = error;
  
}
