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
	printf("changes were actually applied!\n");	
	
	cv::waitKey(0);

	return 0;
}
