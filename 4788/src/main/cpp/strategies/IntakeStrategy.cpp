#include "strategies/IntakeStrategy.h"

IntakeManualStrategy::IntakeManualStrategy(std::string name, Intake &intake, Controllers &contGroup) : Strategy(name), _intake(intake), _contGroup(contGroup) {
	Requires(&intake);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);
}

void IntakeManualStrategy::OnUpdate(double dt) {
	double IntakePower = fabs(_contGroup.Get(ControlMap::Intake)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Intake) : 0;

	if (IntakePower > 0) {
		_intake.setIntake(IntakeStates::STOWED, IntakePower);
	} else {
		if (_contGroup.Get(ControlMap::Outake)) {
			_intake.setIntake(IntakeStates::STOWED, -0.8);
		} else {
			_intake.setIntake(IntakeStates::STOWED, 0);
		}
	}
}