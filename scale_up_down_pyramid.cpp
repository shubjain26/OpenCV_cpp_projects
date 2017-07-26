// scaling down image


#include "stdafx.h"
#include "opencv2\opencv.hpp"
#include<iostream>
using namespace std;

int main()
{
	cv::Mat img1, img2,cny ;

	cv::namedWindow("input", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("output", cv::WINDOW_AUTOSIZE);

	char c = 0;
	img1 = cv::imread("D:\\Users\\shubhjai\\Pictures\\data set\\lena.jpg");
	if (img1.empty())
		return -1;
	cv::imshow("input", img1);

	img1.copyTo(img2);

	while (true)
	{
		if (c == 'u')
		{
			cv::pyrDown(img2, img2);
		}
		if (c == 'd')
		{
			cv::pyrUp(img2, img2);
		}
		if (c == 27)
		{
			break;
		}
		cv::Canny(img2, cny, 10, 100, 3, true);
		cv::imshow("output", img2);
		cv::imshow("Canny", cny);
		c = (int)cv::waitKey(0);

	}

	cv::waitKey(0);
	return 0;
}
