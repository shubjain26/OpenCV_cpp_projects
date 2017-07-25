// opencv_test3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2\core.hpp"
#include "opencv2\highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace std;


int main()
{
	cv::VideoCapture cap;
	cap.open("Video2.mp4");

	cv::namedWindow("video", CV_WINDOW_AUTOSIZE);
	cv::namedWindow("video_gray", CV_WINDOW_AUTOSIZE);
	cv::Mat frame;
	cv::Mat frame_gray;

	while (1)
	{
		cap >> frame;

		if (frame.empty()) break;

		cv::cvtColor(frame, frame_gray, CV_BGR2GRAY);
		cv::imshow("video", frame);

		cv::imshow("video_gray", frame_gray);
	//	cv::waitKey(1);

	}

	cv::waitKey(0);
	cv::destroyAllWindows();


	return 0;
}
