#include"PixelAccess.h"

void PixelAccess::setPixelAccess() {
	//1. Mat::at 이용
	int cnt = 1;
	for (int y = 0; y < src1.cols; y++) {
		for (int x = 0; x < src1.rows; x++) {
			src1.at<uchar>(y, x) = cnt;
			cnt++;
		}
	}

	//2. Mat::ptr 이용
	cnt = 1;
	for (int y = 0; y < src2.cols; y++) {
		uchar* pt = src2.ptr<uchar>(y);
		for (int x = 0; x < src2.rows; x++) {
			pt[x] = cnt;
			cnt++;
		}
	}

	//3. Mat::data 이용
	cnt = 1;
	for (int y = 0; y < src3.cols; y++) {
		uchar * pt = src3.data;
		for (int x = 0; x < src3.rows; x++) {
			pt[src3.rows * y + x] = cnt;
			cnt++;
		}
	}

	cout << src1 << endl;
	cout << src2 << endl;
	cout << src3 << endl;
}