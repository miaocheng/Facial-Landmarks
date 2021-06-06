/********************************************************************************************************
* This file contains the funtions that show the facial landmarks detected by visual components of OpenCV.
* Reference: Online resources and documents
* Coded by Miao Cheng
* Email: miao_cheng@outlook.com
* Created Date: 2019-06-14
********************************************************************************************************/
#ifndef _renderFace_H_
#define _renderFace_H_

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv; 
using namespace std;

#define COLOR Scalar(255, 200,0)

// drawPolyline通过连接开始和结束索引之间的连续点来绘制多边形线。
void drawPolyline
(
  Mat &im,
  const vector<Point2f> &landmarks,
  const int start,
  const int end,
  bool isClosed = false
)
{
    // 收集开始和结束索引之间的所有点
    vector <Point> points;
    for (int i = start; i <= end; i++)
    {
        points.push_back(cv::Point(landmarks[i].x, landmarks[i].y));
    }

    // 绘制多边形曲线
    polylines(im, points, isClosed, COLOR, 2, 16);
    
}


// 绘制人脸关键点
void drawLandmarks(Mat &im, vector<Point2f> &landmarks)
{
    // 在脸上绘制68点及轮廓（点的顺序是特定的，有属性的）
    if (landmarks.size() == 68)
    {
      drawPolyline(im, landmarks, 0, 16);           // Jaw line
      drawPolyline(im, landmarks, 17, 21);          // Left eyebrow
      drawPolyline(im, landmarks, 22, 26);          // Right eyebrow
      drawPolyline(im, landmarks, 27, 30);          // Nose bridge
      drawPolyline(im, landmarks, 31, 35, true);    // Lower nose
      drawPolyline(im, landmarks, 36, 41, true);    // Left eye
      drawPolyline(im, landmarks, 42, 47, true);    // Right Eye
      drawPolyline(im, landmarks, 48, 59, true);    // Outer lip
      drawPolyline(im, landmarks, 60, 67, true);    // Inner lip
    }
    else
    {
		// 如果人脸关键点数不是68，则我们不知道哪些点对应于哪些面部特征。所以，我们为每个landamrk画一个圆圈。
		for(int i = 0; i < landmarks.size(); i++)
		{
			circle(im,landmarks[i],3, COLOR, FILLED);
		}
    }
    
}


int drawLandlines(Mat & _im, vector<Point2f> & _landpoints, const int _start, const int _end)
{
	// +++++ _start <= 16 +++++
	if (_start <= 16 && _end <= 16)
		drawPolyline(_im, _landpoints, _start, _end);
	else if (_start <= 16 && _end >= 17 && _end <= 21)
	{
		drawPolyline(_im, _landpoints, _start, 16);
		drawPolyline(_im, _landpoints, 17, _end);
	}
	else if (_start <= 16 && _end >= 22 && _end <= 26)
	{
		drawPolyline(_im, _landpoints, _start, 16);
		drawPolyline(_im, _landpoints, 17, 21);
		drawPolyline(_im, _landpoints, 22, _end);
	}
	else if (_start <= 16 && _end >= 27 && _end <= 30)
	{
		drawPolyline(_im, _landpoints, _start, 16);
		drawPolyline(_im, _landpoints, 17, 21);
		drawPolyline(_im, _landpoints, 22, 26);
		drawPolyline(_im, _landpoints, 27, _end);
	}
	else if (_start <= 16 && _end >= 31 && _end <= 35)
	{
		drawPolyline(_im, _landpoints, _start, 16);
		drawPolyline(_im, _landpoints, 17, 21);
		drawPolyline(_im, _landpoints, 22, 26);
		drawPolyline(_im, _landpoints, 27, 30);
		drawPolyline(_im, _landpoints, 31, _end);
	}
	else if (_start <= 16 && _end >= 36 && _end <= 41)
	{
		drawPolyline(_im, _landpoints, _start, 16);
		drawPolyline(_im, _landpoints, 17, 21);
		drawPolyline(_im, _landpoints, 22, 26);
		drawPolyline(_im, _landpoints, 27, 30);
		drawPolyline(_im, _landpoints, 31, 35);
		drawPolyline(_im, _landpoints, 36, _end);
	}
	else if (_start <= 16 && _end >= 42 && _end <= 47)
	{
		drawPolyline(_im, _landpoints, _start, 16);
		drawPolyline(_im, _landpoints, 17, 21);
		drawPolyline(_im, _landpoints, 22, 26);
		drawPolyline(_im, _landpoints, 27, 30);
		drawPolyline(_im, _landpoints, 31, 35);
		drawPolyline(_im, _landpoints, 36, 41);
		drawPolyline(_im, _landpoints, 42, _end);
	}
	else if (_start <= 16 && _end >= 48 && _end <= 59)
	{
		drawPolyline(_im, _landpoints, _start, 16);
		drawPolyline(_im, _landpoints, 17, 21);
		drawPolyline(_im, _landpoints, 22, 26);
		drawPolyline(_im, _landpoints, 27, 30);
		drawPolyline(_im, _landpoints, 31, 35);
		drawPolyline(_im, _landpoints, 36, 41);
		drawPolyline(_im, _landpoints, 42, 47);
		drawPolyline(_im, _landpoints, 48, _end);
	}
	else if (_start <= 16 && _end >= 60 && _end <= 67)
	{
		drawPolyline(_im, _landpoints, _start, 16);
		drawPolyline(_im, _landpoints, 17, 21);
		drawPolyline(_im, _landpoints, 22, 26);
		drawPolyline(_im, _landpoints, 27, 30);
		drawPolyline(_im, _landpoints, 31, 35);
		drawPolyline(_im, _landpoints, 36, 41);
		drawPolyline(_im, _landpoints, 42, 47);
		drawPolyline(_im, _landpoints, 48, 59);
		drawPolyline(_im, _landpoints, 60, _end);
	}
	
	return 0;
}


int drawLandpoints(Mat & _m, vector<Point2f> & _landpoints, const int _start, const int _end)
{
	//Point p;
	for (int i = _start; i <= _end; i++)
	{
		//p.x = _landpoints[i].x;
		//p.y = _landpoints[i].y;

		circle(_m, _landpoints[i], 3, Scalar(0, 0, 255), -1);
	}

	return 0;

}


int showMat(Mat & _M)
{
	for (int i = 0; i < _M.rows; i++)
	{
		uchar * data = _M.ptr<uchar>(i);
		for (int j = 0; j < _M.cols; j++)
			cout << int(data[j]) << " ";

		cout << endl;

	}

	return 0;
}





#endif // _renderFace_H_


