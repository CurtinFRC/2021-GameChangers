#include "strategies/ShooterStrategy.h"

ShooterManualStrategy::ShooterManualStrategy(std::string name, Shooter &shooter, Controllers &contGroup) : Strategy(name), _shooter(shooter), _contGroup(contGroup) {
	Requires(&shooter);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);
}

void ShooterManualStrategy::OnUpdate(double dt) {
	double flyWheelPower = fabs(_contGroup.Get(ControlMap::SpinUp)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::SpinUp) : 0;

	if (_contGroup.Get(ControlMap::FireButton)) {
		_shooter.setFire(-ControlMap::FireSpeed);
		std::cout << "fire" << std::endl;
	} else {
		if (_contGroup.Get(ControlMap::ReverseFire)) {
			_shooter.setFire(ControlMap::FireSpeed);
		} else {
			_shooter.setFire(0);
		}
	}

	// if (_contGroup.Get(ControlMap::Speed)) {
	// 	ControlMap::FlyWheelMaxSpeed = 0.9;
	// 	std::cout << "max speed" << ControlMap::FlyWheelMaxSpeed << std::endl;
	// } 

	flyWheelPower *= ControlMap::FlyWheelMaxSpeed;

	_shooter.setFlywheel(flyWheelPower);
}