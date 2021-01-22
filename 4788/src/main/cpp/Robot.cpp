#include "Robot.h"

using namespace frc;
using namespace wml;

double currentTimeStamp;
double lastTimeStamp;
double dt;

// Robot Logiccd
void Robot::RobotInit() {
    // magazine = new Magazine(robotMap->contGroup, robotMap->magazine.magMotor1, robotMap->magazine.magMotor2,robotMap->magazine.magMotor3);
    magazine = new Magazine(robotMap.contGroup, robotMap.magazine.magGearbox);
}

void Robot::RobotPeriodic() {
}

// Dissabled Robot Logic
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

// Auto Robot Logic
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

// Manual Robot Logic
void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
  currentTimeStamp = frc::Timer::GetFPGATimestamp();
  dt = currentTimeStamp - lastTimeStamp;

  magazine->TeleopOnUpdate(dt);

  lastTimeStamp = currentTimeStamp;
}

// Test Logic4
void Robot::TestInit() {}
void Robot::TestPeriodic() {}