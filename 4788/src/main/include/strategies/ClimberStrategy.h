#include "Climber.h"
#include "strategy/Strategy.h"

using Controllers = wml::controllers::SmartControllerGroup;

class ClimberStrategy : public wml::Strategy {
 public:
  ClimberStrategy(std::string name, Climber &climber, Controllers &contGroup);

  void OnUpdate(double dt) override;

 private:
  Climber &_climber;
  Controllers &_contGroup;
};