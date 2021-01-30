#include "Intake.h" // Our intake in main/include/Intake.h
#include "strategy/Strategy.h" // in WML

using Controllers = wml::controllers::SmartControllerGroup;

class IntakeManualStrategy : public wml::Strategy {
 public:

	IntakeManualStrategy(std::string name, Intake &intake, Controllers &contGroup);

	
	void OnUpdate(double dt) override;

 private:
	Intake &_intake;
	Controllers &_contGroup;
};