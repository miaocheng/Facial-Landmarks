// Summary: ����OpenCV��LBF�㷨���������ؼ�����
// Author:  Amusi
// Date:    2018-03-20
// Reference:
//		[1]Tutorial: https://www.learnopencv.com/facemark-facial-landmark-detection-using-opencv/
//		[2]Code: https://github.com/spmallick/learnopencv/tree/master/FacialLandmarkDetection

// Note: OpenCV3.4�Լ���֧��Facemark

#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
//#include "facemarkLBF.hpp"
#include "drawLandmarks.hpp"

//#include "./opencv/modules/modules.hpp"


using namespace std;
using namespace cv;
using namespace cv::face;


int main(int argc,char** argv)
{
    // ���������������Face Detector��
	// [1]Haar Face Detector
    //CascadeClassifier faceDetector("haarcascade_frontalface_alt2.xml");
	// [2]LBP Face Detector
	CascadeClassifier faceDetector("lbpcascade_frontalface.xml");

    // ����Facemark��Ķ���
    Ptr<Facemark> facemark = FacemarkLBF::create();

    // �������������ģ��
    facemark->loadModel("lbfmodel.yaml");

    // ������������ͷ����������Ƶ
    VideoCapture cam(0);
    
    // �洢��Ƶ֡�ͻҶ�ͼ�ı���
    Mat frame, gray;
    
    // ��ȡ֡
    while(cam.read(frame))
    {
      
      // �洢�������ο������
      vector<Rect> faces;
	  // ����Ƶ֡ת�����Ҷ�ͼ, ��ΪFace Detector�������ǻҶ�ͼ
      cvtColor(frame, gray, COLOR_BGR2GRAY);

      // �������
      faceDetector.detectMultiScale(gray, faces);
      
	  // �����ؼ��������
      vector< vector<Point2f> > landmarks;
      
	  // ���������ؼ���������landmark detector��
      bool success = facemark->fit(frame,faces,landmarks);
      
      if(success)
      {
        // ����ɹ�, ����Ƶ֡�ϻ��ƹؼ���
        for(int i = 0; i < landmarks.size(); i++)
        {
			// �Զ���������������㺯��, �ɻ���������������״/����
			drawLandmarks(frame, landmarks[i]);
			// OpenCV�Դ����������ؼ��㺯��: drawFacemarks
			drawFacemarks(frame, landmarks[i], Scalar(0, 0, 255));
        }
	
      }

      // ��ʾ���
      imshow("Facial Landmark Detection", frame);

      // �������ESC��, ���˳�����
      if (waitKey(1) == 27) break;
      
    }

    return 0;

}


