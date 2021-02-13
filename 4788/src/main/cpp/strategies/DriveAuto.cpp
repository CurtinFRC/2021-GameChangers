#include "strategies/DriveAuto.h"

DrivetrainAuto::DrivetrainAuto(std::string name, wml::Drivetrain &drivetrain, wayfinder::WayFinder &wayFinder, wfd_paths &wp) : Strategy(name), _drivetrain(drivetrain), _wayFinder(wayFinder), _wp(wp) {
  Requires(&drivetrain);
  SetCanBeReused(true);
  SetCanBeInterrupted(true);

  wp.path = wayFinder.buildPath(wp.spline1);

}

void DrivetrainAuto::OnUpdate(double dt) {
  _wayFinder.followPath(_wp.path, dt, false);
}