#pragma once

#include"opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;

static int lower_hue, upper_hue;
static Mat src, src_hsv, mask;

class Chap10
{
public:
	Chap10();
	~Chap10();

	static void color_inverse();
	static void color_grayscale();
	static void color_split();
	static void color_req();
	static void inrange();
	static void on_hue_changed(int, void*);
	static void backproj();
};

