#include "Robot.h"

using namespace frc;
using namespace wml;

Drivetrain *drivetrain;

wayfinder::WayFinder *wayFinder;

wayfinder::RobotControl::Config wfdConfig{
	drivetrain,
	true,
	false,
	0.3,
	0.001,
	0.01,
	0,
	0.8,
	0.3,
	0.3
};

wayfinder::Path::sSpline spline1{
	{{0,0}, {1,1}, {2,2}, {3,3}, {4,4}}, // Waypoints

	{0,0}, // Control Points
	{4,4} 
};

wayfinder::Path::sPath path;

// Robot Logic
void Robot::RobotInit() {
	wayFinder = new wayfinder::WayFinder(&wfdConfig);
	path = wayFinder->buildPath(spline1);
}

void Robot::RobotPeriodic() {}

// Dissabled Robot Logic
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

// Auto Robot Logic
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {
	if (wayFinder->followPath(path, 1)) {
		// Do code after path has finished
	}

	if (wayFinder->atWayPoint(2, path)) {
		// do something at node 2
		std::cout << "Reached a node" << std::endl;
	}
	std::cout << wayFinder->getCurrentLocation(&wfdConfig, true);
}

// Manual Robot Logic
void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {}

// Test Logic4
void Robot::TestInit() {}
void Robot::TestPeriodic() {}