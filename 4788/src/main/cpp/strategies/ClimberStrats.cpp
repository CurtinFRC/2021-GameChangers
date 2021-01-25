#include "strategies/ClimberStrats.h"

ClimberManualStrategy::ClimberManualStrategy(std::string name, Climber &climber, Controllers &contGroup) : Strategy(name), _climber(climber), _contGroup(contGroup){}

void ClimberManualStrategy::OnUpdate(double dt) {
	_currentTicks = _climber.climberEncoderValue();

	// If button is pressed pull on the string to raise climber
	if(_contGroup.Get(ControlMap::ClimberUp, wml::controllers::Controller::ONRISE)) {

		// Check if the climber is jammed
		if (_currentTicks - _previousTicks < ControlMap::ClimberJamTolerance) {
			_climber.setClimber(ClimberState::JAMMED);
		} else {
		// Make climber go up
		_climber.setClimber(ClimberState::NORMAL, ControlMap::ClimberSpeed);
		}

	// If button is pressed release the string to lower climber
	} else if (_contGroup.Get(ControlMap::ClimberDown, wml::controllers::Controller::ONRISE)) {

		// Check if the climber is jammed
		if (_previousTicks - _currentTicks < ControlMap::ClimberJamTolerance) {
			_climber.setClimber(ClimberState::JAMMED);
		} else {
			//Make climber go down
			_climber.setClimber(ClimberState::NORMAL, -ControlMap::ClimberSpeed);
		}

	// If no button is pressed stop
	} else {
		_climber.setClimber(ClimberState::NORMAL, 0);
	}
}