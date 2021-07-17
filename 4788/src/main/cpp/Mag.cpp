#include "Mag.h"

Mag::Mag(wml::TalonSrx &magMotor) : _magMotor(magMotor) {}

void Mag::setMag(const MagStates st) {
	_magState = st;
}

void Mag::updateMag(double dt) {
	double setPower = 0;

	switch (_magState) {
		case MagStates::OFF:
			nt::NetworkTableInstance::GetDefault().GetTable("RobotValue")->GetSubTable("Mag")->GetEntry("MagForwards").SetString("STATIONARY"); //yes i am aware my spelling is wrong
			setPower = 0;
			break;
		case MagStates::ON:
			nt::NetworkTableInstance::GetDefault().GetTable("RobotValue")->GetSubTable("Mag")->GetEntry("MagForwards").SetString("FORWARDS");
			setPower = ControlMap::MagSpeed;
			break;
		case MagStates::REVERSE:
			nt::NetworkTableInstance::GetDefault().GetTable("RobotValue")->GetSubTable("Mag")->GetEntry("MagForwards").SetString("REVERSE");
			setPower = ControlMap::ReverseMagSpeed;
			break;
	}

	_magMotor.Set(setPower);
}

void Mag::update(double dt) {
	updateMag(dt);
}