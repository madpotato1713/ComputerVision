#include "Chap10.h"



Chap10::Chap10()
{
}


Chap10::~Chap10()
{
}

void Chap10::backproj() {
	Mat ref, ref_ycrcb, mask;
	ref = imread("images/ref.png", IMREAD_COLOR);
	mask = imread("images/mask.bmp", IMREAD_GRAYSCALE);
	cvtColor(ref, ref_ycrcb, COLOR_BGR2YCrCb);

	Mat hist;
	int channels[] = { 1, 2 };
	int cr_bins = 128; int cb_bins = 128;
	int histSize[] = { cr_bins, cb_bins };
	float cr_range[] = { 0, 256 };
	float cb_range[] = { 0, 256 };
	const float* ranges[] = { cr_range, cb_range };

	calcHist(&ref_ycrcb, 1, channels, mask, hist, 2, histSize, ranges);

	Mat src, src_rcrcb;
	src = imread("images/kids.png", IMREAD_COLOR);
	cvtColor(src, src_rcrcb, COLOR_BGR2YCrCb);

	Mat backproj;
	calcBackProject(&src_rcrcb, 1, channels, hist, backproj, ranges, 1, true);

	imshow("src", src);
	imshow("backproj", backproj);

	waitKey();
	
	return;
}

void Chap10::on_hue_changed(int, void*) {
	Scalar lowerb(lower_hue, 100, 0);
	Scalar upperb(upper_hue, 255, 255);

	inRange(src_hsv, lowerb, upperb, mask);

	imshow("mask", mask);
}

void Chap10::inrange() {

	src = imread("images/candies.png", IMREAD_COLOR);
	lower_hue = 40; upper_hue = 80;

	if (src.empty()) {
		cerr << "Image load failed" << endl;
		return;
	}

	cvtColor(src, src_hsv, COLOR_BGR2HSV);

	imshow("src", src);

	namedWindow("mask");
	createTrackbar("Lower Hue", "mask", &lower_hue, 179, on_hue_changed);
	createTrackbar("Upper Hue", "mask", &upper_hue, 179, on_hue_changed);
	on_hue_changed(0, 0);


	waitKey();
	return;
}

void Chap10::color_req() {
	Mat src = imread("images/pepper.bmp", IMREAD_COLOR);

	if (src.empty()) {
		cerr << "Image load failed" << endl;
		return;
	}

	Mat src_ycrcb;
	cvtColor(src, src_ycrcb, COLOR_BGR2YCrCb);

	vector<Mat> ycrcb_planes;
	split(src_ycrcb, ycrcb_planes);

	equalizeHist(ycrcb_planes[0], ycrcb_planes[0]);

	Mat dst_ycrcb;
	merge(ycrcb_planes, dst_ycrcb);

	Mat dst;
	cvtColor(dst_ycrcb, dst, COLOR_YCrCb2BGR);

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

void Chap10::color_split() {
	Mat src = imread("images/candies.png");

	if (src.empty()) {
		cerr << "Image load failed" << endl;
		return;
	}

	vector<Mat> bgr_planes;
	split(src, bgr_planes);

	imshow("src", src);
	imshow("B_plane", bgr_planes[0]);
	imshow("G_plane", bgr_planes[1]);
	imshow("R_plane", bgr_planes[2]);

	waitKey();
	destroyAllWindows();
}

void Chap10::color_grayscale() {
	Mat src = imread("images/butterfly.jpg");

	if (src.empty()) {
		cerr << "Image load failed" << endl;
		return;
	}

	Mat dst;
	cvtColor(src, dst, COLOR_BGR2GRAY);

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
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
	//		//p2[2] = 255 - p1[2]; // R

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