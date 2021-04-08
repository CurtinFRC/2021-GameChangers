#include "strategies/ShooterStrategy.h"

ShooterManualStrategy::ShooterManualStrategy(std::string name, Shooter &shooter, Controllers &contGroup) : Strategy(name), _shooter(shooter), _contGroup(contGroup) {
	Requires(&shooter);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);

}

void ShooterManualStrategy::OnUpdate(double dt) {
	double turretPower = fabs(_contGroup.Get(ControlMap::TurretTurn)) > fabs(ControlMap::XboxDeadzone) ? _contGroup.Get(ControlMap::TurretTurn) : 0;
	double flyWheelPower = fabs(_contGroup.Get(ControlMap::SpinUp)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::SpinUp) : 0;
	double hoodPower = fabs(_contGroup.Get(ControlMap::HoodLM)) > fabs(ControlMap::XboxDeadzone) ? _contGroup.Get(ControlMap::HoodLM) : 0;

	if (_contGroup.Get(ControlMap::FireButton)) {
		_shooter.setFire(ControlMap::FireSpeed);
		std::cout << "fire" << std::endl;
	} else {
		_shooter.setFire(0);
	}

	if (_contGroup.Get(ControlMap::Speed)) {
		ControlMap::FlyWheelMaxSpeed = 0.9;
		std::cout << "max speed" << ControlMap::FlyWheelMaxSpeed << std::endl;
	} 

	turretPower *= ControlMap::TurretMaxSpeed;
	hoodPower *= ControlMap::HoodMaxSpeed;
	flyWheelPower *= ControlMap::FlyWheelMaxSpeed;

	_shooter.setFlywheel(-flyWheelPower);
	_shooter.setHood(hoodPower);
	_shooter.setTurret(turretPower);
}

//fire is a X button 
//left joystick is turret - turret turn 
//right trigger
//hood in right joystick 


//  else if (_contGroup.Get(ControlMap::ReverseFire)) {
// 		_shooter.setFire(ControlMap::ReverseFireSpeed);
// 	}