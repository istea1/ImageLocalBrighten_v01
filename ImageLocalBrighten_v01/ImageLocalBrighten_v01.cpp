#include "hazeremoval.h"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat flip_pixel_vals(Mat img_start);

int main(int argc, char** args) {
	const char* img_path = "C:\\cv\\ImageLocalBrighten\\x64\\Debug\\mindal4_nonbg.png";
	if (argc > 0) {
		const char* img_path = args[1];
	}
	Mat in_img = imread(img_path);
	in_img = flip_pixel_vals(in_img);
	Mat out_img(in_img.rows, in_img.cols, CV_8UC3);
	unsigned char* indata = in_img.data;
	unsigned char* outdata = out_img.data;

	CHazeRemoval hr;
	cout << hr.InitProc(in_img.cols, in_img.rows, in_img.channels()) << endl;
	cout << hr.Process(indata, outdata, in_img.cols, in_img.rows, in_img.channels()) << endl;
	out_img = flip_pixel_vals(out_img);
	imshow("out_img", out_img);
	//imwrite("C:\\cv\\ImageLocalBrighten\\x64\\Debug\\mindal4_nonbg_out_1.png", out_img);
	waitKey(0);
	// system("pause");
	return 0;
}

Mat flip_pixel_vals(Mat img_start) {
	Mat img;
	img_start.copyTo(img);
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < (img.cols) * 3; j++) {
			int pixel_val = img.at<unsigned char>(i, j);
			img.at<unsigned char>(i, j) = 255 - pixel_val;
		}
	}
	return img;
}
