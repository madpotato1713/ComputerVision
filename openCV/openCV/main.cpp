#pragma once

#include"opencv2/opencv.hpp"
#include<iostream>

//#include"Chap10.h"
//#include"Chap11.h"
//#include"Chap12.h"
#include"Chap13.h"

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {

	//Chap11::ex_threshold(0, 0);
	//Chap11::adaptive();
	//Chap11::erode_dialte();
	//Chap11::open_close();

	//Chap12::labeling_basic();
	//Chap12::labeling_stats();
	//Chap12::contours_basic();
	//Chap12::contours_hier();
	//Chap12::polygon();

	//Chap13::template_matching();
	//Chap13::detect_face();
	//Chap13::detect_eyes();
	//Chap13::detect_pedestrian();
	Chap13::decode_qrcode();

	return 0;
}

