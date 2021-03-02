#include "strategies/ShooterStrategy.h"

ShooterManualStrategy::ShooterManualStrategy(std::string name, Shooter &shooter, Controllers &contGroup) : Strategy(name), _shooter(shooter), _contGroup(contGroup) {
	Requires(&shooter);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);

}

void ShooterManualStrategy::OnUpdate(double dt) {
	double turretPower = _contGroup.Get(ControlMap::TurretTurn) > fabs(ControlMap::XboxDeadzone) ? _contGroup.Get(ControlMap::TurretTurn) : 0;
	double FlyWheelPower = fabs(_contGroup.Get(ControlMap::SpinUp)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::SpinUp) : 0;
	double hoodPower = _contGroup.Get(ControlMap::HoodLM) > fabs(ControlMap::XboxDeadzone) ? _contGroup.Get(ControlMap::HoodLM) : 0;

	if (_contGroup.Get(ControlMap::Fire)) {
		_shooter.setFire();
	} else {

	}

	_shooter.setFlywheel();
	_shooter.setHood();
	_shooter.setTurret();
}

//fire is a X button 
//left joystick is turret - turret turn 
//right trigger
//hood in right joystick 