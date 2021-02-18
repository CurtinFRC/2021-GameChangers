#include "strategies/TurretStrategies.h"

TurretManualStrategy::TurretManualStrategy(std::string name, Turret &turret, Controllers &contGroup) : Strategy{name}, _turret{turret}, _contGroup{contGroup} {
  Requires(&turret);
  SetCanBeInterrupted(true);
  SetCanBeReused(true);
}

void TurretManualStrategy::OnStart(){
}

void TurretManualStrategy::OnUpdate(double dt) {
	_rot = abs(_contGroup.Get(ControlMap::RotStick)) > ControlMap::XboxDeadzone ? _contGroup.Get(ControlMap::RotStick) : 0;
	_vert = abs(_contGroup.Get(ControlMap::VertStick)) > ControlMap::XboxDeadzone ? _contGroup.Get(ControlMap::VertStick) : 0;
	_shoot = _contGroup.Get(ControlMap::ShootTrig);
	_turret.rotate(_rot);
	_turret.vertical(_vert);
	_turret.flywheel(_shoot);
}

void TurretManualStrategy::SetRot(double input) {
  _turret.rotate(input);
}

void TurretManualStrategy::SetVert(double input) {
  _turret.vertical(input);
}

void TurretManualStrategy::SetFlywheel(double input) {
  _turret.flywheel(input);
}

void TurretManualStrategy::Arm() {
  _turret.arm();
}

// -Just Jaci being pog and spreading the word-
/*
class ArmTurretStrategy : public wml::Strategy {
 public:
  ArmTurretStrategy(std::string name, Turret &turret, double ...) 
  : wml::Strategy(name), _turret(turret) {
    Requires(turret);
    SetTimeout(2.0);
  }

  void OnStart() override {
    _turret.SetArming();
  }

  void OnUpdate(double dt) override {
    if (_turret.isReady())
      SetDone();
  }

 private:
  Turret &_turret;
};

class ResetTurretStrategy : public wml::Strategy {
 public:
  ArmTurretStrategy(std::string name, Turret &turret, double ...) 
  : wml::Strategy(name), _turret(turret) {
    Requires(turret);
    SetTimeout(2.0);
  }

  void OnStart() override {
    _turret.SetIdle();
    SetDone();
  }

 private:
  Turret &_turret;
};

// FeedMagazineStrategy

ArmTurretStrategy name{...}

auto it = StrategyBuilder{}.Start()
              ->Add(std::make_shared<ArmTurretStrategy>(...))
              ->Then(std::make_shared<FeedMagazineStrategy>(...))
              ->Then(std::make_shared<ResetTurretStrategy>(...))
              ->Build();
*/
// -I don't have the heart to delete it so it vibes here now-