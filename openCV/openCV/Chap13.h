#pragma once

#include"opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;

class Chap13
{
public:
	Chap13();
	~Chap13();

	static void template_matching(); 
	static void detect_face();
	static void detect_eyes();
	static void detect_pedestrian();
	static void decode_qrcode();
};

