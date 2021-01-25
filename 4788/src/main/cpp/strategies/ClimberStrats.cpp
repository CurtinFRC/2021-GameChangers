#include "strategies/ClimberStrats.h"

ClimberManualStrategy::ClimberManualStrategy(std::string name, Climber &climber, Controllers &contGroup) : Strategy(name), _climber(climber), _contGroup(contGroup) {}

void ClimberManualStrategy::OnUpdate(double dt) {
	_currentTicks = _ClimberMotor.GetEncoderTicks();

	// If button is pressed pull on the string to raise climber
	if(_contGroup.Get(ControlMap::ClimberUp, Controller::ONRISE)) {
		
		// Check if the motor is jammed
		if (_currentTicks - _previousTicks < ControlMap::ClimberJamTolerance) {
			_climber.setClimber(ClimberState::JAMMED);
		} else {
			_climber.setClimber(ClimberState::NORMAL ,ControlMap::ClimberSpeed);
		}

	// If button is pressed release the string to lower climber
	} else if (_contGroup.Get(ControlMap::ClimberDown, Controller::ONRISE)) {
		if (_previousTicks - _currentTicks < ControlMap::ClimberJamTolerance) {
			_climber.setClimber(ClimberState::JAMMED);
		} else {
			_climber.setClimber(ClimberState::NORMAL, -ControlMap::ClimberSpeed);
		}

	// If no button is pressed stop
	} else {
		_climber.setClimber(ClimberState::NORMAL, 0);
	}
}