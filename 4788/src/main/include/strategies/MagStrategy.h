#include "Mag.h"
#include "strategy/Strategy.h"

using Controllers = wml::controllers::SmartControllerGroup;

class MagStrategy : public wml::Strategy {
 public:
  MagStrategy(std::string name, Mag &mag, Controllers &contGroup);

  void OnUpdate(double dt) override;
 private:
  Mag &_mag;
  Controllers &_contGroup;
};