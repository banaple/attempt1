#include<opencv\cv.h>
#include<opencv\highgui.h>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	string filename = "C:\\Users\\Neil Appleton\\Desktop\\2015\\BEB 801\\LARiverBikePath.mp4";
	VideoCapture capture(filename);
	Mat frame;

	if (!capture.isOpened())
		throw "Error when reading mp4";

	for (;;)
	{
		capture >> frame;

		//canny edge
		Mat dst, cdst;
		Canny(frame, dst, 120, 350, 3);
		cvtColor(dst, cdst, CV_GRAY2BGR);
		vector<Vec2f> lines;
		// detect lines
		HoughLines(dst, lines, 1, CV_PI / 180, 150, 0, 0);
		// draw lines
		for (size_t i = 0; i < lines.size(); i++)
		{
			float rho = lines[i][0], theta = lines[i][1];
			if ((theta>CV_PI / 180 * 120 && theta<CV_PI / 180 * 140))
			{
				Point pt1, pt2;
				double a = cos(theta), b = sin(theta);
				double x0 = a*rho, y0 = b*rho;
				pt1.x = cvRound(x0 + 1000 * (-b));
				pt1.y = cvRound(y0 + 1000 * (a));
				pt2.x = cvRound(x0 - 1000 * (-b));
				pt2.y = cvRound(y0 - 1000 * (a));
				line(cdst, pt1, pt2, Scalar(0, 0, 255), 3, CV_AA);
			}
			if ((theta<CV_PI / 180 * 70 && theta>CV_PI / 180 * 50))
			{
				Point pt1, pt2;
				double a = cos(theta), b = sin(theta);
				double x0 = a*rho, y0 = b*rho;
				pt1.x = cvRound(x0 + 1000 * (-b));
				pt1.y = cvRound(y0 + 1000 * (a));
				pt2.x = cvRound(x0 - 1000 * (-b));
				pt2.y = cvRound(y0 - 1000 * (a));
				line(cdst, pt1, pt2, Scalar(0, 0, 125), 3, CV_AA);
			}
		}

		namedWindow("Bike Path", 1);			//create a window with the name "Bike Path"
		namedWindow("Canny Edge Bike Path", 1); //create a window with the name "Canny Edge Detection Bike Path"
		imshow("Bike Path", frame);
		imshow("Canny Edge Bike Path", cdst);	//display the image which is stored in the 'cdst' in the "Canny Edge Detection Bike Path" window
		waitKey(1);							    // waits to display frame
	}
	waitKey(0);
}