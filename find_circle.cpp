#include<stdio.h>
#include<cv.h>
#include<highgui.h>
#include<math.h>
#include<stdlib.h>

int main(int argc,char** argv)
{

IplImage* img=NULL;
if((img=cvLoadImage("input.jpg"))==0)
{


printf("cvLoadImage failed\n");

exit(0);
}


IplImage* gray=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
CvMemStorage* storage=cvCreateMemStorage(0);
cvCvtColor(img,gray,CV_BGR2GRAY);

cvSmooth(gray,gray,CV_GAUSSIAN,7,7);
IplImage * canny=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
IplImage* rgbcanny=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
cvCanny(gray,canny,50,100,3);

CvSeq* circles=cvHoughCircles(gray,storage,CV_HOUGH_GRADIENT,1,gray->height/3,250,100);

for(size_t i=0;i<circles->total;i++)
{

float *p=(float*)cvGetSeqElem(circles,i);
cv::Point center(cvRound(p[0]),cvRound(p[1]));

int radius=cvRound(p[2]);
cvCircle(rgbcanny,center,3,CV_RGB(0,255,0),-1,8,0);
cvCircle(rgbcanny,center,3,CV_RGB(0,0,255),2,8,0);
printf("x: %d y: %d r: %d \n",center.x,center.y,radius);
}
cvNamedWindow("circles",1);
cvShowImage("circles",rgbcanny);
cvSaveImage("out.png",rgbcanny);
cvWaitKey(0);
return 0;
}




