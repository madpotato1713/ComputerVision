#include "Chap10.h"



Chap10::Chap10()
{
}


Chap10::~Chap10()
{
}


void Chap10::color_inverse() {
	Mat src = imread("images/butterfly.jpg", IMREAD_COLOR);

	if (src.empty()) {
		cerr << "Image load failed" << endl;
		return;
	}

	Mat dst(src.rows, src.cols, src.type());

	// case 1: at
	//for (int y = 0; y < src.rows; y++) {
	//	for (int x = 0; x < src.cols; x++) {
	//		//Vec3b& p1 = src.at<Vec3b>(y, x);
	//		//Vec3b& p2 = dst.at<Vec3b>(y, x);

	//		//p2[0] = 255 - p1[0]; // B
	//		//p2[1] = 255 - p1[1]; // G
	//		//p2[2] = 255 - p1[2]; // E

	//		dst.at<Vec3b>(y, x) = Vec3b(255, 255, 255) - src.at<Vec3b>(y, x);
	//	}
	//}

	// case 2: ptr
	//for (int y = 0; y < src.rows; y++) {
	//	Vec3b* p1 = src.ptr<Vec3b>(y);
	//	Vec3b* p2 = dst.ptr<Vec3b>(y);
	//	for (int x = 0; x < src.cols; x++) {
	//		//p2[x][0] = 255 - p1[x][0];
	//		//p2[x][1] = 255 - p1[x][1];
	//		//p2[x][2] = 255 - p1[x][2];
	//		p2[x] = Vec3b(255, 255, 255) - p1[x];
	//	}
	//}

	// case 3: data
	/*uchar* p1 = src.data;
	uchar* p2 = dst.data;
	int height = src.rows, width = src.cols;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int index = y * width * 3 + x * 3;
			p2[index + 0] = 255 - p1[index + 0];
			p2[index + 1] = 255 - p1[index + 1];
			p2[index + 2] = 255 - p1[index + 2];
		}
	}*/

	dst = Scalar(255, 255, 255) - src;

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}