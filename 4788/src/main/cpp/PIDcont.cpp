#include "PIDcont.h"

double PIDcont::Calc(double input, double goal, double min, double max, double kP, double kI, double kD, double &sum, double &previousError, double dt) {
  double error = goal - input;
  double derror = (error - previousError) / dt;
  sum = sum + error * dt;

  double output = kP * error + kI * sum + kD * derror;

  previousError = error;

  if(output < min) {
    output = min;
  } else if(output > max) {
    output = max;
  }

  return output;
}