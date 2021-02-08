#include "strategies/ClimberStrats.h"

ClimberManualStrategy::ClimberManualStrategy(std::string name, Climber &climber, Controllers &contGroup) : Strategy(name), _climber(climber), _contGroup(contGroup){}

void ClimberManualStrategy::OnUpdate(double dt) {
	// Set the current ticks to the current encode ticks
	_currentTicks = _climber.climberEncoderValue();

	// If the climber is disabled and someone presses the enable button
	if (_contGroup.Get(ControlMap::ClimberActivate) && _climberStateStrat == ClimberState::DISABLED) {
		// Make the climber extend
		_climber.setClimber(ClimberState::EXTENDING);
		_climberStateStrat = ClimberState::EXTENDING;
	}
	if (_climberStateStrat == ClimberState::EXTENDING) {
		// If the climber has hit the top (Done by comparing the encoder ticks to see when there is too little a change)
		if (_currentTicks - _previousTicks < ControlMap::ClimberJamTolerance) {
			// Stop the climber and set it to enabled mode
			_climber.setClimber(ClimberState::ENABLED, 0);
			_climberStateStrat = ClimberState::ENABLED;
		}
		else {
			// Otherwise, continue the extending
			_climber.setClimber(ClimberState::EXTENDING);
			_climberStateStrat = ClimberState::EXTENDING;
		}
	}

	// If the climber is enabled
	if (_climberStateStrat == ClimberState::ENABLED) {
		// If the disabled button is pressed, disable it.
		if (_contGroup.Get(ControlMap::ClimberDeactivate, wml::controllers::Controller::ONRISE)) {
			_climber.setClimber(ClimberState::DISABLED);
			_climberStateStrat = ClimberState::DISABLED;
		}
		// If the joystick is moved and it isn't in the deadzone
		if (abs(_contGroup.Get(ControlMap::ClimberAdjust)) > ControlMap::XboxDeadzone) {
			// Make the climber adjust (slight movements as I haven't added jam prevention)
			_climber.setClimber(ClimberState::ENABLED, ControlMap::ClimberAdjustSpeed*_contGroup.Get(ControlMap::ClimberAdjust));
			_climberStateStrat = ClimberState::ENABLED;
		}
	}

	_previousTicks = _climber.climberEncoderValue();
}