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
	
	// Mat create function. Does no allow initialization
	cv::Mat L;
	L.create(4,4, CV_8UC(2));
	std::cout << "L = " << std::endl << " " << L << std::endl << std::endl;
	
	// MATLAB style initializer
	E = cv::Mat::eye(4,4, CV_64F);
	std::cout << "E = " << std::endl << " " << E << std::endl << std::endl;	// notice E is overwritten
    cv::Mat O = cv::Mat::ones(2, 2, CV_32F);
    std::cout << "O = " << std::endl << " " << O << std::endl << std::endl;
    cv::Mat Z = cv::Mat::zeros(3,3, CV_8UC1);
    std::cout << "Z = " << std::endl << " " << Z << std::endl << std::endl;	
	
	// Folllowing is possible for small matrices
	C = (cv::Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    //std::cout << "C = " <<  std::endl << " " << C <<  std::endl <<  std::endl;
	C = (cv::Mat_<double>({ 0, -1, 0, -1, 5, -1, 0, -1, 0})).reshape(3);
    std::cout << "C = " <<  std::endl << " " << C <<  std::endl <<  std::endl;
 	
	//Create new object from the row of an existing ones
	cv::Mat RowClone = C.row(1).clone();	// zero-based
	std::cout << "RowClone = " << std::endl << " " << RowClone << std::endl << std::endl;
	
	// To fill a matrix with radom values, specifying the limit values
	cv::Mat R = cv::Mat(3, 2, CV_8UC3 );
	cv::randu(R, cv::Scalar::all(0), cv::Scalar::all(255));
	std::cout << "R = " << std::endl << " " << R << std::endl << std::endl;

	// Show the images
	cv::namedWindow("Image A", cv::WINDOW_AUTOSIZE);
	cv::imshow("Image A", A);
	//cv::namedWindow("Image B", cv::WINDOW_AUTOSIZE);
	//cv::imshow("Image B", B);
	//cv::namedWindow("Image C", cv::WINDOW_AUTOSIZE);
	//cv::imshow("Image C", C);	
	cv::namedWindow("Image D", cv::WINDOW_AUTOSIZE);
	cv::imshow("Image D", D);	
	cv::namedWindow("Image E", cv::WINDOW_AUTOSIZE);
	cv::imshow("Image E", E);	

	cv::waitKey(0);

	return 0;
}
