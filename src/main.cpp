#include "opencv2/opencv.hpp"
#include <iostream>
#define W 640
#define H 480

using namespace cv;
using namespace std;
int main(int, char**)
{
VideoCapture cap(0); // open the default camera
if(!cap.isOpened()) // check if we succeeded
return -1;

std:vector<Mat> BGR;
namedWindow("BGR",1);
int x,y,r,g,b,a;
x=W/2;
y=H/2;

for(;;)
{



Mat frame;
cap >> frame; // get a new frame from camera
//cvtColor(frame, BGR, CV_BGR2RGB);
Vec3b pixel = frame.at<Vec3b>(y,x);
b= pixel[0]; 
g=pixel[1];
r=pixel[2];
rectangle( frame, Point( x-10, y-10 ), Point( x+10, y+10), Scalar( 0, 55, 255 ), 2); 
line(frame, Point(x,y), Point(x,y+20),Scalar(0, 55, 255),2);
line(frame, Point(x+10,y), Point(x+20,y),Scalar(0, 55, 255),2);
line(frame, Point(x,y-10), Point(x,y-20),Scalar(0, 55, 255),2);
line(frame, Point(x-10,y), Point(x-20,y),Scalar(0, 55, 255),2);
//imshow("edges", frame);

//split(frame, BGR);

//через frame
//int b=(int)frame.data[frame.channels()*(frame.cols *y+x)+0];
//int g=(int)frame.data[frame.channels()*(frame.cols *y+x)+1];
//int r=(int)frame.data[frame.channels()*(frame.cols *y+x)+2];

//через Vec

imshow("edges", frame);
//класический способ (разкоментить split)
//int b=(int)BGR[0].at<uchar>(W/2,H/2);
//int g=(int)BGR[1].at<uchar>(W/2,H/2);
//int r=(int)BGR[2].at<uchar>(W/2,H/2);
//line(frame, Point(a,b), Point(x,y),Scalar(r,g,b),2);

std::cout << "B " << b << " G " << g << " R " << r << std::endl;

if(waitKey(30) == 32) break; // 32 is space key
}

// the camera will be deinitialized automatically in VideoCapture destructor
return 0;
}
