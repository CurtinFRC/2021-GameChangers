// #include "Shooter.h"
#include "strategies/ShooterStrategy.h"

ShooterStrategy::ShooterStrategy(std::string name, Shooter &shooter, Controllers &contGroup) : Strategy(name), _shooter(shooter), _contGroup(contGroup) {
  Requires(&shooter);
  SetCanBeInterrupted(true);
  SetCanBeReused(true);
}

void ShooterStrategy::OnUpdate(double dt) {

}
