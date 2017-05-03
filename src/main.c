#include <stdio.h>
#include <stdlib.h>
#include <cv.h>
#include <highgui.h>


int main(int argc, char *argv[])
{
    IplImage* img = 0;
    int height,width,step,channels;
    uchar *data;
    int i,j,k;

    if(argc<2){
        printf("Usage: main <image-file-name>\n\7");
        exit(0);
    }

    // load an image
    img=cvLoadImage(argv[1],CV_LOAD_IMAGE_ANYDEPTH>0);
    if(!img){
        printf("Could not load image file: %s\n",argv[1]);
        exit(0);
    }

    // get the image data
    height    = img->height;
    width     = img->width;
    step      = img->widthStep;
    channels  = img->nChannels;
    data      = (uchar *)img->imageData;
    printf("Processing a %dx%d image with %d channels\n",height,width,channels);

    // create a window
    cvNamedWindow("mainWin", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("mainWin", 1000, 1000);


    // show the image
    cvShowImage("Wind", img );

    // wait for a key
    cvWaitKey(0);

    // release the image
    cvReleaseImage(&img );
    return 0;
}