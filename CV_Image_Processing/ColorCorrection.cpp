
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using namespace cv;
int colorCorrection()
{


	cv::Mat image = cv::imread("../WindowsLogo.jpg");

	if (image.empty()) {
		std::cerr << "Error: Failed to load image." << std::endl;
		return -1;
	}

	// Split the image into its BGR channels
	std::vector<cv::Mat> channels;
	cv::split(image, channels);

	// Adjust the color balance by multiplying each channel with a scaling factor
	// You can adjust these values to change the color balance
	double blueScale;  // Blue channel scaling factor
	int greenScale;  // Green channel scaling factor
	int redScale;  // Red channel scaling factor

	cout << "R < ";
	cin >> redScale;
	cout << "G < ";
	cin >> greenScale;
	cout << "B < ";
	cin >> blueScale;

	// redScale = redScale / channels[0];       if you need to enter 0-255 values


	channels[0] *= blueScale;  // Blue channel
	channels[1] *= greenScale;  // Green channel
	channels[2] *= redScale;  // Red channel

	// Merge the channels back together
	cv::Mat adjustedImage;
	cv::merge(channels, adjustedImage);

	// Display the adjusted image
	cv::imshow("Adjusted Image", adjustedImage);
	cv::waitKey(0);

	return 0;
}























/*
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
// we're NOT "using namespace std;" here, to avoid collisions between the beta variable and std::beta in c++17
using std::cin;
using std::cout;
using std::endl;
int main(void)
{
	double alpha = 0.5; double beta; double input;
	Mat src1, src2, dst;
	cout << " Simple Linear Blender " << endl;
	cout << "-----------------------" << endl;
	cout << "* Enter alpha [0.0-1.0]: ";
	cin >> input;
	// We use the alpha provided by the user if it is between 0 and 1
	if (input >= 0 && input <= 1)
	{
		alpha = input;
	}
	src1 = imread(samples::findFile("LinuxLogo.jpg"));
	src2 = imread(samples::findFile("WindowsLogo.jpg"));
	if (src1.empty()) { cout << "Error loading src1" << endl; return EXIT_FAILURE; }
	if (src2.empty()) { cout << "Error loading src2" << endl; return EXIT_FAILURE; }
	beta = (1.0 - alpha);
	addWeighted(src1, alpha, src2, beta, 0.0, dst);
	imshow("Linear Blend", dst);
	waitKey(0);
	return 0;
}
*/