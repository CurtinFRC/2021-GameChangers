#include "Intake.h" // Our intake in main/include/Intake.h
#include "strategy/Strategy.h" // in WML

using Controllers = wml::controllers::SmartControllerGroup;

// class IntakeActuation : public wml::Strategy {
//  public:

// 	IntakeActuation(std::string name, Intake &intake, Controllers &contGroup);

	
// 	void OnUpdate(double dt) override;

//  private:
// 	Intake &_intake;
// 	Controllers &_contGroup;
// };


class IntakeStill : public wml::Strategy {
 public:
	IntakeStill(std::string name, Intake &intake, Controllers &contGroup);

	void OnUpdate(double dt) override;
 private:
	Intake &_intake;
	Controllers &_contGroup;
};