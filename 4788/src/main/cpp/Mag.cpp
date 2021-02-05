#include "Mag.h"

Mag::Mag(wml::TalonSrx &magMotor, Controllers &contGroup) : _magMotor(magMotor), _contGroup(contGroup) {}

void Mag::setMag(const MagState st, double power) {
  _power = power;
  _magState = st;
}

void Mag::updateMag(double dt) {
  double setPower = 0;
  bool magJammed = false;

  switch (_magState) {
    case MagState::MANUAL:
        
        
        if (_magMotor.GetEncoderAngularVelocity() == 0) {
          MagTimer.Start();
          if (MagTimer.Get() > 1) {
            magJammed = true;
          }
        } else {
          MagTimer.Reset();
          MagTimer.Stop();
        }

        if (magJammed) {
          MagTimer.Start();
          setPower = 0;
          _contGroup.GetController(ControlMap::CoDriver).SetRumble(wml::controllers::RumbleType::kRightRumble, 0.5);
          if (MagTimer.Get() > 1) {
            MagTimer.Reset();
            MagTimer.Stop();
            magJammed = false;
          }
        } else {
          setPower = _power;
        }
        break;
    case MagState::AUTO:
        setPower = 0;
        break;
  }

  _magMotor.Set(setPower);
}

void Mag::update(double dt) {
  updateMag(dt);
}