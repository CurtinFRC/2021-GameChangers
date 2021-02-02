#include "strategies/TurretStrategies.h"

TurretManualStrategy::TurretManualStrategy(std::string name, Turret &turret, Controllers &contGroup) : Strategy{name}, _turret{turret}, _contGroup{contGroup} {}

void TurretManualStrategy::OnStart(){
}

void TurretManualStrategy::OnUpdate(double dt) {
	_rot = abs(_contGroup.Get(ControlMap::RotStick)) > ControlMap::XboxDeadzone ? _contGroup.Get(ControlMap::RotStick) : 0;
	_vert = abs(_contGroup.Get(ControlMap::VertStick)) > ControlMap::XboxDeadzone ? _contGroup.Get(ControlMap::VertStick) : 0;
	_shoot = _contGroup.Get(ControlMap::ShootTrig);
}