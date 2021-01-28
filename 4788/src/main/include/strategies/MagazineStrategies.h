#include "Magazine.h" 
#include "strategy/Strategy.h"

using Controllers = wml::controllers::SmartControllerGroup;

class MagazineManualStrategy : public wml::Strategy {
 public:
  MagazineManualStrategy(std::string name, Magazine &magazine, Controllers &contGroup);
  void OnUpdate(double dt) override;
  
 private:
  Magazine &_magazine;
	Controllers &_contGroup;
  int _magPreviouseTicks;
  int _magTicks;
};