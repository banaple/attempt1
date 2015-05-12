#include<opencv\cv.h>
#include<opencv\highgui.h>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace cv;
using namespace std;
/*
int main(int argc, const char** argv)
{
	//read the image data in the file "2508.png" and store it in 'img'
	Mat image = imread("2508.png", CV_LOAD_IMAGE_UNCHANGED); 
	
	//check whether the image is loaded or not
	if (image.empty()) 
	{
		cout << "Error : Image cannot be loaded..!!" << endl;
		//system("pause"); //wait for a key press
		return -1;
	}

	//make image gray
	Mat gray_image;
	cvtColor(image, gray_image, CV_BGR2GRAY);

	//apply sobel edge detection
	Mat sobelimage;
	Sobel(gray_image, sobelimage, CV_32F, 1, 0);

	//canny edge
	Mat dst, cdst;
	Canny(image, dst, 50, 200, 3);
	cvtColor(dst, cdst, CV_GRAY2BGR);
	vector<Vec2f> lines;
	// detect lines
	HoughLines(dst, lines, 1, CV_PI / 180, 150, 0, 0);

	// draw lines
	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
		if (theta>CV_PI / 180 * 140 || theta<CV_PI / 180 * 60)
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
	}

	namedWindow("Normal Bike Path", CV_WINDOW_NORMAL); //create a window with the name "Normal Bike Path"
	namedWindow("Grayscale Bike Path", CV_WINDOW_NORMAL); //create a window with the name "Grayscale Bike Path"
	namedWindow("Edge Detection Bike Path", CV_WINDOW_NORMAL); //create a window with the name "Edge Detection Bike Path"
	namedWindow("Canny Edge Bike Path", CV_WINDOW_NORMAL); //create a window with the name "Canny Edge Detection Bike Path"

	imshow("Normal Bike Path", image); //display the image which is stored in the 'image' in the "Normal Bike Path" window
	imshow("Grayscale Bike Path", gray_image); //display the image which is stored in the 'gray_image' in the "Grayscale Bike Path" window
	imshow("Edge Detection Bike Path", sobelimage); //display the image which is stored in the 'sobelimage' in the "Edge Detection Bike Path" window
	imshow("Canny Edge Bike Path", cdst); //display the image which is stored in the 'cdst' in the "Canny Edge Detection Bike Path" window

	waitKey(0); //wait infinite time for a keypress

	destroyWindow("Normal Bike Path"); //destroy the window with the name, "Normal Bike Path"
	destroyWindow("Grayscale Bike Path"); //destroy the window with the name, "Grayscale Bike Path"
	destroyWindow("Edge Detection Bike Path"); //destroy the window with the name, "Edge Detection Bike Path"
	destroyWindow("Canny Edge Bike Path"); //destroy the window with the name, "Edge Detection Bike Path"

	return 0;
}
*/
