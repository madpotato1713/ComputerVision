#pragma once

#include"opencv2/opencv.hpp"
#include<iostream>

#include"Chap11.h"

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {

	//Chap11::ex_threshold(0, 0);
	//Chap11::adaptive();
	//Chap11::erode_dialte();
	Chap11::open_close();

	return 0;
}

