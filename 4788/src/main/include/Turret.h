#pragma once

#include <iostream>
#include "RobotMap.h"
#include "strategy/StrategySystem.h"

enum class TurretInit {
	ROT,
	VERT
};

enum class TurretState {
	STATIONARY,
	MOVING,
	ZEROING,
	IDLE
};

class Turret : public wml::StrategySystem {
	public:
		Turret(wml::Gearbox &RotationalAxis, wml::Gearbox &VerticalAxis, wml::Gearbox &FlyWheel, 
		wml::sensors::BinarySensor &RotLimit, wml::sensors::BinarySensor &VertLimit);

		void shooter(double dt, double input);
		void rotate(double dt, double input);
		void vertical(double dt, double input);
		double pid(double input, double goal, double min, double max, double kP, double kI, double kD, double& sum, double& previousError, double dt);

	private:
		wml::Gearbox &_RotationalAxis;
		wml::Gearbox &_VerticalAxis;
		wml::Gearbox &_FlyWheel;

		wml::sensors::BinarySensor &_rotLimit;
		wml::sensors::BinarySensor &_vertLimit;

		double _previousErrorS = 0;
		double _previousErrorR = 0;
		double _previousErrorV = 0;
		double _sumS = 0;
		double _sumR = 0;
		double _sumV = 0;

		bool _init = true;

		double _gearRatio = 196;

		TurretInit _initState{ TurretInit::ROT };
		TurretState _state{ TurretState::IDLE };

		double mathClamp(const double min, const double max, const double input);
};