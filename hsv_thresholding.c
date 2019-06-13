//Phase 1
#include <opencv2/opencv.hpp>               //Defining the OpenCV Header Files
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include<stdio.h>
using namespace std;
using namespace cv;
//////////////////////
#define h 500  //h=height                  //Defining the height of the image
#define w 500  //w=width                   //Defining the width of the image


//Main file content

int main()
{//Main bracket starts


//Phase 2
	//Image variables
	IplImage* input_image = cvLoadImage("c:\\RAMW.jpg"); //Load the image file
	IplImage* rast_image = cvCreateImage(cvSize(w, h), 8, 3); // Defining input space
      // to load the copy of input image for further processing

	IplImage* hsv_image = cvCreateImage(cvSize(w, h), 8, 3); // Defining input space
      // to load the HSV image

	IplImage* def_threshold = cvCreateImage(cvSize(w, h), 8, 1); // Resolution (w,h),8 bit depth and single channel represented by 1 //Defining input space to load the thresholded image
	

//Phase 3
//Naming the Windows
	cvNamedWindow("Original Image", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Original image with defined resolution", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Thresholded image", CV_WINDOW_AUTOSIZE);

//Phase 4
	//Trackbar settings
	int h1 = 0; int s1 = 0; int v1 = 0; //h1=Huelowerand h2=Hueupper, s1=Satlowerand 
                                           //s2=Satupper, v1=Valupper, v2=Vallower
	int h2 = 0; int s2 = 0; int v2 = 0;
	
       //Formation of trackbar
	cvCreateTrackbar("H1", "cnt", &h1, 255, 0);//Range in degrees from 0 to 255 for h1
	cvCreateTrackbar("H2", "cnt", &h2, 255, 0);//Range in degrees from 0 to 255 for h2
	cvCreateTrackbar("S1", "cnt", &s1, 255, 0);//Range in degrees from 0 to 255 for s1
	cvCreateTrackbar("S2", "cnt", &s2, 255, 0);//Range in degrees from 0 to 255 for s2
	cvCreateTrackbar("V1", "cnt", &v1, 255, 0);//Range in degrees from 0 to 255 for v1
	cvCreateTrackbar("V2", "cnt", &v2, 255, 0);//Range in degrees from 0 to 255 for v2


//Phase 5
//Image resize
cvResize(input_image, rast_image, CV_INTER_LINEAR); //Resize the input image and
     //store in the variable "rast_image" defined in Phase 2.
	
     //Conversion to HSV color space
cvCvtColor(rast_image, hsv_image, CV_BGR2HSV);//Convert rast_image to HSV colorspace
	
while (1)// Iterate over values of h1,h2,s1,s2,v1,v2 to find different patterns
	{
		//Thresholding the image
		cvInRangeS(hsv_image, cvScalar(h1, s1, v1), cvScalar(h2, s2, v2), 
def_threshold); //Adjust h1,h2,s1,s2 and v1,v2 to get new patterns

		//Showing the images
		cvShowImage("Original Image", rast_image); //Display rast_image
		cvShowImage("Thresholded Image", def_threshold);//Display thresholded image
		//Escape Sequence
		char c = cvWaitKey(33);
		if (c == 27)
			break;
	}




//Phase 6
//Compute White (non-zero) and Black Pixels
int non-zero_pixels= countNonZero(def_threshold); //Value for white pixels
cout<<”\nThe number of white pixels are:”<<non-zero_pixels; 

// ALTERNATIVE TO DETERMINE NON-ZERO PIXELS
//USERS CAN REFER TO THE PYTHON CODE ATTACHED AT THE END OF THIS C++ CODE

	
//Phase 7
//Showing the image
	cvShowImage("Original Image", rast_image); //Display rast_image
	cvShowImage("Thresholded Image", def_threshold); //Display thresholded image
	//Waiting for user to press any key
	cvWaitKey(0);

	//Cleanup the memory
	cvReleaseImage(&input_image);  //Release the input image from memory
	cvReleaseImage(&def_threshold); //Release the thresholded image from the memory
	cvReleaseImage(&rast_image); //Release the rast_image from the memory
	cvReleaseImage(&hsv_image); // Release the HSV image from the memory
	cvDestroyAllWindows(); // Delete all image windows




} //Main bracket ends

