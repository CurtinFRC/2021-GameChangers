#include "Robot.h"

using namespace frc;
using namespace wml;

double currentTimeStamp;
double lastTimeStamp;
double dt;

// Robot Logiccd
void Robot::RobotInit() {
    intake = new Intake(robotMap->contGroup, robotMap->intake.intakeDown, robotMap->intake.intakeMotor);
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

    intake->TeleopOnUpdate(dt);

    lastTimeStamp = currentTimeStamp;
}

// Test Logic4
void Robot::TestInit() {}
void Robot::TestPeriodic() {}