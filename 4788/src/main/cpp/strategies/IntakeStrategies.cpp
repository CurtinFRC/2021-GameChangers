#include "strategies/IntakeStrategies.h" 

IntakeManualStrategy::IntakeManualStrategy(std::string name, Intake &intake, Controllers &contGroup) : Strategy(name), _intake(intake), _contGroup(contGroup) {
	Requires(&intake);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);
}

void IntakeManualStrategy::OnUpdate(double dt) {
	double intakingPower = fabs(_contGroup.Get(ControlMap::Intake)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Intake) : 0;
	_intake.setIntake(IntakeStates::DEPLOYED, intakingPower);
}