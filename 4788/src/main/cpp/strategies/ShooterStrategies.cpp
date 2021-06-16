#include "strategies/ShooterStategies.h" 

ShooterStrategy::ShooterStrategy(std::string name, Shooter &shooter, Controllers &contGroup) : Strategy(name), _shooter(shooter), _contGroup(contGroup) {
	Requires(&shooter);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);
}

void ShooterStrategy::OnUpdate(double dt) {
	double shooterPower = fabs(_contGroup.Get(ControlMap::FlywheelSpinUp)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::FlywheelSpinUp) : 0;

	if (!ControlMap::ClimberToggle) {
		_shooter.setShooter(ShooterState::MANUAL, 0);
	} else {
		_shooter.setShooter(ShooterState::MANUAL, shooterPower);
		if (_contGroup.Get(ControlMap::FireShooter)) {
			_shooter.setFire(ShooterState::MANUAL, ControlMap::fireSpeed);
		} else {
			_shooter.setFire(ShooterState::MANUAL, 0);
		}
	}
}