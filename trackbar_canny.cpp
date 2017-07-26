// trackbar_canny.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include<iostream>

using namespace std;

int g_trackbar_pos1;
int g_trackbar_pos2;
int g_min_thresh, g_max_thresh;
int g_aperture_size =3;

cv::Mat img, dst;
cv::Mat img_gray, edges;

cv::VideoCapture g_cap(0);



void onTrackbarSlide1(int pos, void *)
{
	g_min_thresh = pos;
	cout <<"min: "<< g_min_thresh << "\tmax: "<< g_max_thresh << endl;
}

void onTrackbarSlide2(int pos, void *)
{
	g_max_thresh = pos;
	cout << "min: " << g_min_thresh << "max: " << g_max_thresh << endl;
}



int main()
{
	//cv::Mat img = cv::imread("D:\\Users\\shubhjai\\Pictures\\data set\\lena.jpg");
	cv::namedWindow("Output", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("input", cv::WINDOW_AUTOSIZE);
	cv::createTrackbar("max_thresh", "Output", &g_trackbar_pos1, 400, onTrackbarSlide1);
	cv::createTrackbar("min_thresh", "Output", &g_trackbar_pos2, 400, onTrackbarSlide2);

	
if (!g_cap.isOpened())
	{
		cout << "image not found" << endl;
		return -1;
	}
	char c;
	while (true)
	{
		g_cap.read(img);

		cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);

		cv::blur(img_gray, img_gray, cv::Size(5, 5));
		cv::Canny(img_gray, edges, g_min_thresh, g_max_thresh, g_aperture_size);
		
		cv::imshow("input", img);
		cv::imshow("Output", edges);
		
		c = (int)cv::waitKey(50);
		if (c == 27)
			break;
	}







	onTrackbarSlide1(0, 0);


	cv::waitKey(0);
    return 0;
}

