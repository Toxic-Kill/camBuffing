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
		cv::Mat gauMat;
		cv::Mat bufMat;
		cap >> frame;//捕捉当前帧
		cvtColor(frame, hsvMat, COLOR_BGR2HSV);//转为HSV格式
		cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), detectMat);//捕捉皮肤
		medianBlur(frame, gauMat, 7);//对当前帧进行中值滤波
		frame.copyTo(bufMat);//将当前帧深度复制到bufMat中
		gauMat.copyTo(bufMat, detectMat);//将中值滤波后的皮肤部分遮罩在当前帧上
		cv::imshow("frame", frame);//显示当前帧
		cv::imshow("buffing", bufMat);//显示磨皮处理后的当前帧
		waitKey(30);
	}
}