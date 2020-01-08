#pragma once

#include"opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;

class Chap11
{
public:
	Chap11();
	~Chap11();
	static void on_threshold(int pos, void* userdata);
	static void ex_threshold(int argc, char* argv[]);
	static void on_trackbar(int pos, void* userdata);
	static void adaptive();
};

