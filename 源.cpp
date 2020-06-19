#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
#include<opencv2/highgui/highgui_c.h>
using namespace cv;
int main(int argc, char** argv)
{
	Mat src = imread("C:/Users/Thinkpad/Desktop/vs/2020 July/0601 huidu erzhihua/0601 huidu erzhihua/1.JPG");//图片路径
	if (src.empty())
	{
		printf_s("找不到照片\n");
		return -1;
	}
	namedWindow("测试图", CV_WINDOW_NORMAL);//窗口大小可调整
	cvResizeWindow("测试图", 500, 400);//设定窗口大小
	imshow("测试图", src);   //加载原图

	Mat output_image;
	namedWindow("灰度化图", CV_WINDOW_NORMAL);
	cvtColor(src, output_image, CV_BGR2GRAY);//图片灰度化处理
	cvResizeWindow("灰度化图", 500, 400);
	imshow("灰度化图", output_image);

	Mat last;
	namedWindow("二值化图", CV_WINDOW_NORMAL);
	threshold(output_image, last, 100, 255, CV_THRESH_BINARY);//图片二值化处理
	cvResizeWindow("二值化图", 500, 400);
	imshow("二值化图", last);

	waitKey(0);
	return 0;
}