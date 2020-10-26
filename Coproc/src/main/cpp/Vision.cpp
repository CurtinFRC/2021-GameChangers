#include "Vision.h"
#include <iostream>

CJ::Camera::Cam cam;
CJ::Image inputImage;

void Vision::Init() {
  // Logic here will run once (Initialization)
	CJ::Core::init();

	cam.config = {
		0,
		cv::CAP_ANY,
		60,
		640,
		480,
		0.1,
		true,
		"Cam"
	};

	inputImage.name = "Input From Camera";
	CJ::Core::setupVision(&inputImage, &cam);
}

void Vision::Periodic() {
  // Logic here will run periodicly (Looping)
	CJ::Output::Display(&inputImage);
}