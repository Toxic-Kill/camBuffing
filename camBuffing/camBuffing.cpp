#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap(0);//调用摄像头
	//肤色
	double i_minH = 0;
	double i_maxH = 20;
	//0-255
	double i_minS = 43;
	double i_maxS = 255;
	//0-255
	double i_minV = 55;
	double i_maxV = 255;
	//0-255
	while (1)
	{
		cv::Mat frame;
		cv::Mat hsvMat;
		cv::Mat detectMat;
		cv::Mat bufMat;
		cap >> frame;
		cvtColor(frame, hsvMat, COLOR_BGR2HSV);
		cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), detectMat);
		cvtColor(detectMat, bufMat, COLOR_HSV2BGR);
		cv::imshow("frame", frame);
		cv::imshow("buffing", bufMat);
		waitKey(30);
	}
}