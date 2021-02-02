#include "Mag.h"

Mag::Mag(wml::TalonSrx &magMotor, wml::VictorSpx &fireMotor) : _magMotor(magMotor), _fireMotor(fireMotor) {}

void Mag::updateMag(double dt) {

}

void Mag::update(double dt) {
  updateMag(dt);
}