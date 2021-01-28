#include "Robot.h"

using namespace frc;
using namespace wml;

double currentTimeStamp;
double lastTimeStamp;
double dt;

// Robot Logiccd
void Robot::RobotInit() {
  // magazine = new Magazine(robotMap->contGroup, robotMap->magazine.magMotor1, robotMap->magazine.magMotor2,robotMap->magazine.magMotor3);
  magazine = new Magazine(robotMap.magazineSystem.magGearbox);

  magazine->SetDefault(std::make_shared<MagazineManualStrategy>("Magazine Manual", *magazine, robotMap.contGroup));

	StrategyController::Register(magazine);
}

void Robot::RobotPeriodic() {
  currentTimeStamp = frc::Timer::GetFPGATimestamp();
  dt = currentTimeStamp - lastTimeStamp;

  StrategyController::Update(dt);
  magazine->update(dt);
	// magazine->SetDefault(std::make_shared<MagazineManualStrategy>("Magazine Manual", *magazine, robotMap.contGroup));
  NTProvider::Update();

  lastTimeStamp = currentTimeStamp;
}

// Dissabled Robot Logic
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

// Auto Robot Logic
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

// Manual Robot Logic
void Robot::TeleopInit() {
  Schedule(magazine->GetDefaultStrategy(), true);
}
void Robot::TeleopPeriodic() {

}

// Test Logic4
void Robot::TestInit() {}
void Robot::TestPeriodic() {}