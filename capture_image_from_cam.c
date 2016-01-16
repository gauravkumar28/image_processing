#include <stdio.h>
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#include <stdlib.h>
IplImage * img = 0;
IplImage * img1 = 0;
IplImage * img2 = 0;
int height, width, step, channels;
uchar * data;
uchar * * pix;
int i, j, sum = 0;
void main() {
// start up the cam source , 0 refers to the default cam
CvCapture * capture = cvCaptureFromCAM(0);
// this checks for a faliure
if (!cvGrabFrame(capture)) { // capture a frame
printf("Could not grab a frame\n");
exit(0);
}
// grab a frame from the cam
img = cvRetrieveFrame(capture,0);
//retrive data about the image
height = img->height; // height of image
width = img->width; // weighr of iamge
step = img->widthStep;
// no of array element for one row of imagedata
channels = img->nChannels; // no of channels.... R,G,B, alpga , gama......
pix = (uchar * * )calloc(sizeof(uchar * ), height + 1);
// alocate memory for a dummy iamge img2
if (!img2)
img2 = cvCreateImage(cvSize(img->width, img->height),IPL_DEPTH_8U, img->nChannels);
// noe the dummy variable is used to store the fliped version of the cam image,
//this is due to the fact that open cv while in cam mode grabs a vertical fliped version of the iamge.
cvFlip(img, img2, 0);
cvFlip(img2, img2, 0); //enable this statment to see hoe the image looks without flip
//create a window
cvNamedWindow("mainWin", CV_WINDOW_AUTOSIZE);
cvMoveWindow("mainWin", 100, 100); //move it to 100, 100 position
cvShowImage("mainWin", img2); // display the image
cvSaveImage("image.jpg",img2,0);
cvWaitKey(0); // wait for a key press
cvReleaseImage(&img1);
cvReleaseImage(&img2);
free(pix);
cvReleaseCapture(&capture); //release the cam....
} //END OF MAIN

