#pragma once
#include <array>
#define ARRAYSIZE 4

class MovingAv
{
  public:
    static void Calc(std::array<double, ARRAYSIZE> &aveArray, double &ave, double current);
};
