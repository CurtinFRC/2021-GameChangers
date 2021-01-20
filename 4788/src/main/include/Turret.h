#pragma once

#include "RobotMap.h"

class Turret {
	public:
		Turret(wml::Gearbox &RotationalAxis, wml::Gearbox &VerticalAxis, wml::Gearbox &FlyWheel);

		void Shooter(double dt, double input);
		void ShooterInit();

	private:
		wml::Gearbox &_RotationalAxis;
		wml::Gearbox &_VerticalAxis;
		wml::Gearbox &_FlyWheel;

		//wml::sensors::BinarySensor &_LeftLimit;
		//wml::sensors::BinarySensor &_AngleDownLimit;

		double _kP = 0;
		double _kI = 0;
		double _kD = 0;

		double _previousError = 0;
		double _sum = 0;
		double _goal = 0;
};