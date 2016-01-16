#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<cv.h>
#include<highgui.h>

int main(int argc,char**argv)
{
IplImage* img =0;
int height,width,step,channels;
uchar *data;
int i,j,k;
if(argc<2)
{

printf("Enter File  Name\n");
exit(0);
}
//load image;
img=cvLoadImage(argv[1]);
if(!img)
{

printf("Could Not load image filae : %s\n",argv[1]);
exit(0);
}

//get  image data

height =img->height;
width =img->width;
step =img->widthStep;
channels =img->nChannels;
data =(uchar*)img->imageData;
printf("processing a %dX%d image with %d channel\n",height,width,channels);

//create a window
cvNamedWindow("mainWin",CV_WINDOW_AUTOSIZE);
cvMoveWindow("mainWin",100,100);
//invert the iamge

for(i=0;i<height;i++)
{

for(j=0;j<width;j++)
{

for(k=0;k<channels;k++)
{data[i*step+j*channels+k]=255-data[i*step+j*channels+k];
}
}
}

//show  a image

cvShowImage("mainwin",img);
//wait  for a key


cvWaitKey(0);

//release the image

cvReleaseImage(&img);

return 0;
}
