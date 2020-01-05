#pragma once

#include"opencv2/opencv.hpp"
#include<iostream>

//#include"PixelAccess.h"
#include"Chap10.h"

using namespace std;
using namespace cv;

int main() {

	//PixelAccess pixelAccess;
	//pixelAccess.setPixelAccess();
	//Chap10::color_inverse();

	//Chap10::color_grayscale();
	//Chap10::color_split();

	//Chap10::color_req();
	//Chap10::inrange();
	Chap10::backproj();

	return 0;
}