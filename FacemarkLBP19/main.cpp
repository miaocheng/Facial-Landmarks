
#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include "drawLandmarks.hpp"

#include "getPts.hpp"

using namespace cv;
using namespace std;
using namespace cv::face;


int main()
{
	//const char * str = "./images/eat.jpg";
	//getPts(str);
	char ch;
	char str[100];
	
	FILE * fp = fopen("./dirImages.txt", "r");
	FILE * fx = fopen("./facialPtx.txt", "w+");
	FILE * fy = fopen("./facialPty.txt", "w+");

	int n = 0;
	float _x[68], _y[68];
	for (int i = 0; i < 10708; i++)
	//for (int i = 0; i < 5; i++)
	{
		n = 0;
		while ( (ch = fgetc(fp)) != '\n')
		{
			str[n] = ch;
			n++;
		}

		str[n] = '\0';

		cout << "n = " << n << endl;
		cout << "str = " << str << endl;
		getPts(str, _x, _y);

		for (int j = 0; j < 68; j++)
		{
			fprintf(fx, "%f ", _x[j]);
			fprintf(fy, "%f ", _y[j]);
		}

		fputc('\n', fx);
		fputc('\n', fy);

	}

	fclose(fp);
	fclose(fx);
	fclose(fy);

	return 0;

}


