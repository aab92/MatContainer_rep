#include <stdio.h>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		printf("usage: TestMatClass  <Image_Path>\n");
	}

	cv::Mat A,C;	// creates just the header parts
	A = cv::imread(argv[1], cv::IMREAD_COLOR);	// here we'll know the method used (allocate matrix)
	//printf("changes were actually applied!\n");	

	cv::Mat B(A);	// Use the copy constructor

	C = A;	// Assignment operator

	// Creating Mat objects with header refering to a subsection of the full data.
	cv::Mat D (A, cv::Rect(100, 100, 200, 200) );	// using a rectangle
	cv::Mat E = A(cv::Range::all(), cv::Range(100,200));	// using row and column boundaries	

	// To make an actual copy of an image, so that we can modify it  without affecting the original Mat object:
	cv::Mat F = A.clone();
	cv::Mat G;
	A.copyTo(G);	
	
	// Mat constructor
	cv::Mat M(2,2, CV_8UC3, cv::Scalar(0,0,255) );
	std::cout << "M = " << std::endl << " " << M << std::endl << std::endl;

	// Show the images
	cv::namedWindow("Image A", cv::WINDOW_AUTOSIZE);
	cv::imshow("Image A", A);
	cv::namedWindow("Image B", cv::WINDOW_AUTOSIZE);
	cv::imshow("Image B", B);
	cv::namedWindow("Image C", cv::WINDOW_AUTOSIZE);
	cv::imshow("Image C", C);	
	cv::namedWindow("Image D", cv::WINDOW_AUTOSIZE);
	cv::imshow("Image D", D);	
	cv::namedWindow("Image E", cv::WINDOW_AUTOSIZE);
	cv::imshow("Image E", E);	

	cv::waitKey(0);

	return 0;
}
