#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
#include<opencv2/highgui/highgui_c.h>
using namespace cv;
int main(int argc, char** argv)
{
	Mat src = imread("C:/Users/Thinkpad/Desktop/vs/2020 July/0601 huidu erzhihua/0601 huidu erzhihua/1.JPG");//ͼƬ·��
	if (src.empty())
	{
		printf_s("�Ҳ�����Ƭ\n");
		return -1;
	}
	namedWindow("����ͼ", CV_WINDOW_NORMAL);//���ڴ�С�ɵ���
	cvResizeWindow("����ͼ", 500, 400);//�趨���ڴ�С
	imshow("����ͼ", src);   //����ԭͼ

	Mat output_image;
	namedWindow("�ҶȻ�ͼ", CV_WINDOW_NORMAL);
	cvtColor(src, output_image, CV_BGR2GRAY);//ͼƬ�ҶȻ�����
	cvResizeWindow("�ҶȻ�ͼ", 500, 400);
	imshow("�ҶȻ�ͼ", output_image);

	Mat last;
	namedWindow("��ֵ��ͼ", CV_WINDOW_NORMAL);
	threshold(output_image, last, 100, 255, CV_THRESH_BINARY);//ͼƬ��ֵ������
	cvResizeWindow("��ֵ��ͼ", 500, 400);
	imshow("��ֵ��ͼ", last);

	waitKey(0);
	return 0;
}