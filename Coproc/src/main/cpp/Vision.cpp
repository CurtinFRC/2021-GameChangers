#include "Vision.h"
#include <iostream>

void Vision::Init() {
  // Logic here will run once (Initialization)
	CJ::Core::init();

	// cam.config = {
	// 	640,
	// 	480,
	// 	0,
	// 	"Vision Camera",
	// 	false,
	// 	50,
	// 	60
	// };

	cam.config.Exposure = 10;


	inputImage.name = "Input From Camera";
	CJ::Core::setupVision(&inputImage, &cam);
}

void Vision::Periodic() {
  // Logic here will run periodicly (Looping)
}