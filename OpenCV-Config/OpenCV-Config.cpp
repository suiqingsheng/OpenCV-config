// OpenCV-Config.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <opencv2\opencv.hpp>
#include <opencv2\ximgproc.hpp>

using namespace cv;
using namespace std;


int main()
{
	system("color 0a");

	//显示OpenCV版本
	cout << CV_VERSION;

	Mat src, gray,dst;
	//打开图像
	src = imread("library.jpg",-1);

	//判断图像是否存在
	if (!src.data)
	{
		cout << "打开图像失败" << endl;
		return -1;
	}

	//创建窗口
	namedWindow("原始图像",WINDOW_AUTOSIZE);
	//显示图像
	imshow("原始图像",src);

	//彩色图像灰度化
	cvtColor(src,gray,COLOR_BGR2GRAY);
	//局部阈值二值化
	ximgproc::niBlackThreshold(gray,dst,255,ThresholdTypes::THRESH_BINARY,5,0,ximgproc::LocalBinarizationMethods::BINARIZATION_SAUVOLA);

	//创建窗口
	namedWindow("二值图像", WINDOW_AUTOSIZE);
	//显示图像
	imshow("二值图像", dst);

	waitKey(0);

	destroyAllWindows();

	return 0;
}

