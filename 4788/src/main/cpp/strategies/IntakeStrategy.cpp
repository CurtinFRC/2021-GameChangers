#include "strategies/IntakeStrategy.h"

IntakeManualStrategy::IntakeManualStrategy(std::string name, Intake &intake, Controllers &contGroup) : Strategy(name), _intake(intake), _contGroup(contGroup) {
	Requires(&intake);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);
}

void IntakeManualStrategy::OnUpdate(double dt) {
	double IntakePower = fabs(_contGroup.Get(ControlMap::Intake)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Intake) : 0;
	IntakePower = fabs(_contGroup.Get(ControlMap::DriverIntake)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::DriverIntake) : 0;

	if (_contGroup.Get(ControlMap::IntakeActuation), wml::controllers::Controller::ButtonMode::ONRISE) {
		if (!(ControlMap::IntakeToggle)) {
			ControlMap::IntakeToggle = true;
		} else {
			ControlMap::IntakeToggle = false;
		}
	}

	if (_contGroup.Get(ControlMap::IntakeDownDriver, wml::controllers::Controller::ButtonMode::ONRISE)) {
		if (!(ControlMap::IntakeToggle)) {
			ControlMap::IntakeToggle = true;
		} else {
			ControlMap::IntakeToggle = false;
		}
	}

	if (!(ControlMap::IntakeToggle)) {
		if (_contGroup.Get(ControlMap::Outake)) {
			_intake.setIntake(IntakeStates::STOWED, IntakePower);
		} else {
			_intake.setIntake(IntakeStates::STOWED, -IntakePower);
		}
	} else {
		if (_contGroup.Get(ControlMap::Outake)) {
			_intake.setIntake(IntakeStates::DEPLOYED, IntakePower);
		} else {
			_intake.setIntake(IntakeStates::DEPLOYED, -IntakePower);
		}
	}
}
		// if (_contGroup.Get(ControlMap::Outake)) {
		// 	_intake.setIntake(IntakeStates::DEPLOYED, IntakePower);
		// 	std::cout << "reverse intake" << std::endl;
		// } else {
		// 	_intake.setIntake(IntakeStates::DEPLOYED, 0);
		// }