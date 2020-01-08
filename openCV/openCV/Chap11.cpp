#include "Chap11.h"

Chap11::Chap11()
{
}

Chap11::~Chap11()
{
}

void Chap11::adaptive() {
	Mat src = imread("images/sudoku.jpg", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed" << endl;
		return;
	}

	imshow("src", src);

	namedWindow("dst");
	createTrackbar("Block Size", "dst", 0, 200, on_trackbar, (void*)&src);
	setTrackbarPos("Block Size", "dst", 11);

	waitKey();
	return;
}

void Chap11::on_trackbar(int pos, void* userdata) {
	Mat src = *(Mat*)userdata;

	int bsize = pos;
	if (bsize % 2 == 0) bsize--;
	if (bsize < 3) bsize = 3;

	Mat dst;
	adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, bsize, 5);

	imshow("dst", dst);
}

void Chap11::on_threshold(int pos, void* userdata) {
	Mat src = *(Mat*)userdata;

	Mat dst;
	threshold(src, dst, pos, 255, THRESH_BINARY);

	imshow("dst", dst);
}

void Chap11::ex_threshold(int argc, char* argv[]) {
	Mat src;

	if (argc < 2)
		src = imread("images/neutrophils.png", IMREAD_GRAYSCALE);
	else
		src = imread(argv[1], IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed" << endl;
		return;
	}

	imshow("src", src);

	namedWindow("dst");
	createTrackbar("Threshold", "dst", 0, 255, on_threshold, (void*)&src);
	setTrackbarPos("Threshold", "dst", 128);

	waitKey();
}