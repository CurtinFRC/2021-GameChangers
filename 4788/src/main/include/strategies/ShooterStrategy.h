#include "Shooter.h"
#include "strategy/Strategy.h"

using Controllers = wml::controllers::SmartControllerGroup;

class ShooterStrategy : public wml::Strategy {
 public:
  ShooterStrategy(std::string name, Shooter &shooter, Controllers &contGroup);

  void OnUpdate(double dt) override;

 private:
  Shooter &_shooter;
  Controllers &_contGroup;
};