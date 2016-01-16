#include <opencv2/opencv.hpp>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
using namespace cv;

int main(int, char**)
{
    VideoCapture cap("/media/New Volume/Downloads/Miley Cyrus/miley cyrus-hollywood.flv"); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat edges;
    namedWindow("edges",1);
int count=1;
int timer=100;
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        //cvtColor(frame, edges, CV_BGR2GRAY);
        //GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        //Canny(edges, edges, 0, 30, 3);
if(!timer)
{
string s="demo.jpg";
stringstream ss2;
ss2 << count;
string str2 = ss2.str();
s=str2+s;
//cv::Mat src = cv::imread("demo.jpg");
resize(frame, frame, Size(300, 200), 0, 0, INTER_CUBIC);
// Resize src to img size
//cv::resize(frame, frame, src.size());
	imwrite(s,frame);
        imshow("edges", frame);
        //if(waitKey(30) >= 0) break;
timer=100;
count++;
if(count==100000)
break;
}
timer--;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
