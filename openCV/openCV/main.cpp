#pragma once

#include"opencv2/opencv.hpp"
#include<iostream>

#include"PixelAccess.h"

using namespace std;
using namespace cv;

int main() {

	PixelAccess pixelAccess;
	pixelAccess.setPixelAccess();

	return 0;
}