#pragma once 

#include "RobotMap.h"
// #include "Robot.h"
#include "strategy/Strategy.h"
// #include "controllers/Controllers.h"
#include "strategies/DriveSystem.h"
// #include "Drivetrain.h"
#include "wfd_paths.h"

// using namespace wayfinder;

class DrivetrainAuto : public wml::Strategy {
 public:
	DrivetrainAuto(std::string name, wml::Drivetrain &drivetrain, wayfinder::WayFinder &wayFinder, wfd_paths &wp);

	void OnUpdate(double dt) override;

 private:
	wml::Drivetrain &_drivetrain;
	wayfinder::WayFinder &_wayFinder;
	wfd_paths &_wp;

};