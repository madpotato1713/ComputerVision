#pragma once

#include"opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;

class PixelAccess {
protected:
	Mat src1;
	Mat src2;
	Mat src3;

public:
	PixelAccess() {
		src1 = Mat::zeros(3, 3, CV_8UC1);
		src2 = Mat::zeros(3, 3, CV_8UC1);
		src3 = Mat::zeros(3, 3, CV_8UC1);
	}

	void setPixelAccess();
};