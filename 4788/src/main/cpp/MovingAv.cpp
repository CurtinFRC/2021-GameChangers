#include "MovingAv.h"

void MovingAv::Calc(std::array<double, ARRAYSIZE> &aveArray, double &ave, double current) {
	ave -= aveArray[0]/aveArray.size();
	ave += current/aveArray.size();
	for(std::size_t i = 0; i < aveArray.size() - 1; i++) {
		aveArray[i] = aveArray[i+1];
	}
	aveArray[aveArray.size() - 1] = current;
}