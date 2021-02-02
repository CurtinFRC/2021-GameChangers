#include "strategies/ClimberStrategy.h"

ClimberStrategy::ClimberStrategy(std::string name, Climber &climber, Controllers &contGroup) : Strategy(name), _climber(climber), _contGroup(contGroup) {
  Requires(&climber);
  SetCanBeInterrupted(true);
  SetCanBeReused(true);
}

void ClimberStrategy::OnUpdate(double dt) {

}

