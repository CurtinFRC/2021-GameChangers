#pragma once

#include <iostream>
#include "RobotMap.h"
#include "strategy/StrategySystem.h"
#include "devices/StateDevice.h"
#include "Gearbox.h"
#include "PIDcont.h"
#include "MovingAv.h"
#include <array>
#define ARRAYSIZE 4

enum class TurretState {
	ZERO,
	ZEROING,
	ARMING,
	READY,
	IDLE
};

enum class SubState {
	PID,
	ZEROING,
	IDLE
};

class Turret : public wml::devices::StateDevice<TurretState>, public wml::StrategySystem {
	public:
	// Turret
		Turret(wml::Gearbox &RotationalAxis, wml::Gearbox &VerticalAxis, wml::Gearbox &FlyWheel, 
		wml::sensors::BinarySensor &RotLimit, wml::sensors::BinarySensor &VertLimit);
	// Functions - Public
		void onStatePeriodic(double dt);
		void verticalPeriodic(double dt);
		void rotationPeriodic(double dt);
		void flywheelPeriodic(double dt);
		void flywheel(double goal);
		void rotate(double goal);
		void vertical(double goal);
		void setShooting();
		bool isReady();
		virtual std::string GetStateString() final;

	protected:
	virtual void OnStatePeriodic(TurretState state, double dt) override;

	private:
	// Vertical
		double _sumV{ 0 };
		double _aveV{ 0 };
		double _inputV{ 0 };
		std::array<double, ARRAYSIZE> _movingAveV{};
		double _toleranceV{ 2 };
		double _verticalGoal{ 0 };
		double _previousErrorV{ 0 };
		wml::Gearbox &_verticalAxis;
		wml::sensors::BinarySensor &_vertLimit;
	// Rotation
		double _sumR{ 0 };
		double _aveR{ 0 };
		double _inputR{ 0 };
		std::array<double, ARRAYSIZE> _movingAveR{};
		double _toleranceR{ 0.1 };
		double _rotationGoal{ 0 };
		double _previousErrorR{ 0 };
		wml::Gearbox &_rotationalAxis;
		wml::sensors::BinarySensor &_rotLimit;
	// Flywheel
		double _sumF{ 0 };
		double _aveF{ 0 };
		double _inputF{ 0 };
		std::array<double, ARRAYSIZE> _movingAveF{};
		double _toleranceF{ 0.1 };
		double _flyWheelGoal{0};
		double _previousErrorF{0};
		wml::Gearbox &_flyWheel;
	// States
		SubState _verticalState{ SubState::ZEROING };
		SubState _rotationState{ SubState::ZEROING };
		SubState _flyWheelState{ SubState::ZEROING };	
	// Functions - Private
		double mathClamp(const double min, const double max, const double input);
		bool allIdle();
		bool isPidReady();
};