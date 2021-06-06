/********************************************************************************************************
* This file contains the funtions that capture the facial landmarks based on pre-training models.
* Reference: Online resources and documents
* Coded by Miao Cheng
* Email: miao_cheng@outlook.com
* Created Date: 2019-06-14
********************************************************************************************************/
#ifndef __GETPTS_H
#define __GETPTS_H


#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include "drawLandmarks.hpp"

//#include "getPts.hpp"

using namespace cv;
using namespace std;

using namespace cv::face;


int getPts(char * _dirStr, float * _x, float * _y)
{
	Mat image, gray;//Mat是OpenCV最基本的数据结构，这是定义一个图像矩阵类型

	//image = imread(imageName.c_str(), IMREAD_COLOR);//读入图片数据
	image = imread(_dirStr);
	//imshow("Original image", image);

	// +++++ The detetor +++++
	//CascadeClassifier faceDetector("lbpcascade_frontalface_alt2.xml");
	CascadeClassifier faceDetector;
	faceDetector.load("haarcascade_frontalface_alt2.xml");

	gray.create(image.size(), image.type());
	cvtColor(image, gray, COLOR_BGR2GRAY);
	//showMat(gray);
	//imshow("Gray image", gray);

	//cout << Size() << endl;
	vector<Rect> fff;

	faceDetector.detectMultiScale(gray, fff,
		1.1,
		3, 0
	);

	vector< vector<Point2f>> landmarks;

	Ptr<Facemark> facemark = FacemarkLBF::create();
	facemark->loadModel("lbfmodel.yaml");

	bool success = facemark->fit(image, fff, landmarks);

	Mat tImage = image.clone();

	cout << "The landmarks size: " << landmarks.size() << endl;
	for (int i = 0; i < 68; i++)
	{
		_x[i] = landmarks[0][i].x;
		_y[i] = landmarks[0][i].y;
	}

	waitKey(0);

	return 0;
}







#endif

