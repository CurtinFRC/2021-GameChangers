#include "strategies/ClimberStrategy.h"

ClimberManualStrategy::ClimberManualStrategy(std::string name, Climber &climber, Controllers &contGroup) : Strategy(name), _climber(climber), _contGroup(contGroup) {
	Requires(&climber);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);
}

void ClimberManualStrategy::OnUpdate(double dt) {
	double ClimberPower = fabs(_contGroup.Get(ControlMap::ClimberPower)) > ControlMap::XboxDeadzone ? _contGroup.Get(ControlMap::ClimberPower) : 0;

	if (_contGroup.Get(ControlMap::ClimberActuation)) {
		_climber.setClimber(ClimberStates::UP, ClimberPower);

	} else {
		_climber.setClimber(ClimberStates::DOWN, 0);
	}
}
