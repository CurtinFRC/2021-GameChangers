#include "Magazine.h"

using namespace wml;
using namespace wml::controllers;

// Magazine::Magazine(wml::controllers::SmartControllerGroup &contGroup, wml::TalonSrx &magMotor, frc::AnalogInput &Position1, frc::AnalogInput &Position5, bool &p1, bool &p2, bool &p3) : _contGroup(contGroup), _magMotor(magMotor), _position1(Position1), _position5(Position5), _p1(p1), _p2(p2), _p3(p3) {

// }

void Magazine::AutoMag() {
  
  //Auto Control
  if (_position1.GetAverageValue() >= ControlMap::MagazineBallThreshFinal) {
    MagazinePower = 0;
    MagazinePowerFunnelRight = 1; 
    MagazinePowerFunnelLeft = 0.5;
  } else if (_position1.GetAverageValue() <= ControlMap::MagazineBallThreshFinal) {
    MagazinePower = 0.7;
    MagazinePowerFunnelRight = 0; 
    MagazinePowerFunnelLeft = 0;
    if (_position5.GetAverageValue() <= ControlMap::MagazineBallThreshIndex) {
      if (_position1.GetAverageValue() >= ControlMap::MagazineBallThreshFinal) {
        MagazinePower = 0;
        MagazinePowerFunnelRight = 1; 
        MagazinePowerFunnelLeft = 0.5;
      }
    }
  } else {
    MagazinePower = 0;
    MagazinePowerFunnelRight = 1; 
    MagazinePowerFunnelLeft = 0.5;
  }
}

void Magazine::TeleopOnUpdate(double dt) {
  _magMotor.Set(MagazinePower);
  _magMotorLeft.Set(MagazinePowerFunnelLeft);
  _magMotorRight.Set(MagazinePowerFunnelRight);
}