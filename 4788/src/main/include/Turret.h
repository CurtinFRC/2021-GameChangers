#pragma once

#include <iostream>
#include "RobotMap.h"
#include "strategy/StrategySystem.h"

enum class TurretState {
	ZERO,
	ZEROING,
	SHOOT,
	READY,
	IDLE
};

enum class SubState {
	PID,
	ZEROING,
	IDLE
};

class Turret : public wml::StrategySystem {
	public:
		Turret(wml::Gearbox &RotationalAxis, wml::Gearbox &VerticalAxis, wml::Gearbox &FlyWheel, 
		wml::sensors::BinarySensor &RotLimit, wml::sensors::BinarySensor &VertLimit);

		void init();
		void onStatePeriodic(double dt);
		void verticalPeriodic(double dt);
		void rotationPeriodic(double dt);
		void flywheelPeriodic(double dt);
		void flywheel(double goal);
		void rotate(double goal);
		void vertical(double goal);
		void setShooting();
		bool isReady();

	private:
		wml::Gearbox &_rotationalAxis;
		wml::Gearbox &_verticalAxis;
		wml::Gearbox &_flyWheel;

		wml::sensors::BinarySensor &_rotLimit;
		wml::sensors::BinarySensor &_vertLimit;

		double _previousErrorS = 0;
		double _previousErrorR = 0;
		double _previousErrorV = 0;
		double _sumS = 0;
		double _sumR = 0;
		double _sumV = 0;

		double _flyWheelGoal = 0;
		double _rotationGoal = 0;
		double _verticalGoal = 0;
		
		SubState _rotationState{ SubState::ZEROING };
		SubState _verticalState{ SubState::ZEROING };
		SubState _flyWheelState{ SubState::ZEROING };	

		double _gearRatio = 196;

		TurretState _state{ TurretState::ZERO };

		int _arraySize = 4;

		//double _movingAveV[4]{0,0,0,0};
		//double _movingAveR[4]{0,0,0,0};
		//double _movingAveS[4]{0,0,0,0};
		double _aveV = 0;
		double _aveR = 0;
		double _aveS = 0;

		double _inputV = 0;
		double _inputR = 0;
		double _inputS = 0;

		double pid(double input, double goal, double min, double max, double kP, double kI, double kD, double& sum, double& previousError, double dt);
		double mathClamp(const double min, const double max, const double input);
		bool allIdle();
		bool isPidReady();
		void movingAve(double &aveArray[], double &ave, double current);
};