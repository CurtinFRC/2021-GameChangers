#include "Climber.h"

Climber::Climber(wml::VictorSpx &winch, wml::actuators::DoubleSolenoid &climberSolenoid) : _winch(winch), _climberSolenoid(climberSolenoid) {}

void Climber::updateClimber(double dt) {

}

void Climber::update(double dt) {
  updateClimber(dt);
}