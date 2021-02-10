#pragma once

class PIDcont
{
  public:
    static double Calc(double input, double goal, double min, double max, double kP, double kI, double kD, double& sum, double& previousError, double dt);
};
