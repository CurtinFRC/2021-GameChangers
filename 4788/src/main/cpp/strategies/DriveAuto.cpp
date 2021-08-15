#include "strategies/DriveAuto.h"

DrivetrainAuto::DrivetrainAuto(std::string name, wml::Drivetrain &drivetrain, wayfinder::WayFinder &wayFinder, wfd_paths &wp, bool &as, bool &t, bool &i, bool &pub, bool &te) : Strategy(name), _drivetrain(drivetrain), _wayFinder(wayFinder), _wp(wp), _as(as), _t(t), _i(i), _pub(pub), _te(te) {
	Requires(&drivetrain);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);
}

void DrivetrainAuto::OnUpdate(double dt) {
	std::cout << pathIncrementer << std::endl;
	try {
		switch (autoSelector) {
				case 0: //6 ball auto (its not quite 6 ball yet)
					switch (pathIncrementer) {
						case 0:
						if (_wayFinder.followPath(&_wp.path1L, dt, false)) {
							std::cout << "finished first leg" << std::endl;
						}
					default:
						std::cout << "Defalt running" << std::endl;
					}
					break;

				case 1: //simple, forwards auto
					if(_wayFinder.followPath(&_wp.path2L, dt, false)) {
						std::cout << "finished auto" << std::endl;
					}
				default:
					std::cout << "running the defalt case" << std::endl;
		}


	} catch (...) {
		std::cout << "error" << std::endl;
	}
}



// switch (pathIncrementer) {
// 						case 0:
// 							_as = true; //autostarted = true, fire 3 balls. 
// 							if (_t == true) { //if turning = true (set by shooter) go to next case to turn
// 								pathIncrementer = 1;
// 							}
// 						break;
// 						case 1://turn and line up. 
// 							if(_wayFinder.followPath(&_wp.path1L, dt, false)) {
// 								_i = true;
// 								pathIncrementer = 2;
// 							}
// 						break;
// 						case 2://after intake and mag on, go forwards 
// 							if (_pub == true) {
// 								if (_wayFinder.followPath(&_wp.path1L, dt, false)) { //go forwards, turn around
// 									_i = false; //turn off intake and mag
// 									pathIncrementer = 3;
// 								}
// 							}
// 						break;
// 						case 3: 
// 							_te = true;
// 						break;
// 					default:
// 						std::cout << "Defalt running" << std::endl;
// 					}