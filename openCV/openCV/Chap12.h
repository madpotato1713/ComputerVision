#pragma once

#include"opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;

class Chap12
{
public:
	Chap12();
	~Chap12();

	static void labeling_basic();
	static void labeling_stats();
	static void contours_basic();
	static void contours_hier();
	static void setLabel(Mat& img, const vector<Point>& pts, const String& label);
	static void polygon();
};
