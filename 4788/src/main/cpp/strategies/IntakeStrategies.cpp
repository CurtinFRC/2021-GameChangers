#include "strategies/IntakeStrategies.h" 

IntakeStrategy::IntakeStrategy(std::string name, Intake &intake, Controllers &contGroup) : Strategy(name), _intake(intake), _contGroup(contGroup) {
	Requires(&intake);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);
}

void IntakeStrategy::OnUpdate(double dt) {
	double intakingPower = fabs(_contGroup.Get(ControlMap::Intake)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Intake) : 0;
	// double outakingPower = fabs(_contGroup.Get(ControlMap::Outake)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Outake) : 0;

	if (!ControlMap::ClimberToggle) {
		_intake.setIntake(IntakeState::MANUAL, 0);
	} else {
		if (_contGroup.Get(ControlMap::Outake)) {
			_intake.setIntake(IntakeState::MANUAL, -0.8);
		} else {
			_intake.setIntake(IntakeState::MANUAL, intakingPower);
		}
	}
}