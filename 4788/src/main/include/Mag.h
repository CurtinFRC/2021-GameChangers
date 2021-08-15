#pragma once 

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

<<<<<<< HEAD
enum class MagStates {
	ON,
	OFF,
	REVERSE
=======
enum class MagState {
	MANUAL,
>>>>>>> 7a319f36c2adba576e52e65f7b02fbb0931601ba
};

class Mag : public wml::StrategySystem {
 public:
	Mag(wml::TalonSrx &magMotor);

<<<<<<< HEAD
	void setMag(const MagStates st, double power);

	void updateMag(double dt);
	void update(double dt);

 private:
	wml::TalonSrx &_magMotor;

	MagStates _magState{MagStates::OFF};

	double _power;
=======
	void setMag(const MagState st, double power = 0);

	void updateMag(double dt);
	void update(double dt);
 private:
	wml::TalonSrx &_magMotor;

	MagState _magState{ MagState::MANUAL };
	double _power;
	double setPower = 0;
>>>>>>> 7a319f36c2adba576e52e65f7b02fbb0931601ba
};