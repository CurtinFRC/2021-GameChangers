#include "strategies/ShooterStategies.h" 

ShooterManualStrategy::ShooterManualStrategy(std::string name, Shooter &shooter, Controllers &contGroup) : Strategy(name), _shooter(shooter), _contGroup(contGroup) {
	Requires(&shooter);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);
}

void ShooterManualStrategy::OnUpdate(double dt) {
	double shooterPower = fabs(_contGroup.Get(ControlMap::FlywheelSpinUp)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::FlywheelSpinUp) : 0;

	// if (!ControlMap::ClimberToggle) {
	_shooter.setFlywheel(shooterPower);
	// } else {
	// 	_shooter.setFlywheel(shooterPower);
		if (_contGroup.Get(ControlMap::FireShooter)) {
			_shooter.setFire(ControlMap::FireSpeed);
		} else {
			_shooter.setFire( 0);
		}
	// }
}