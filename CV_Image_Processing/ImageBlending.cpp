#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using namespace cv;
int imageBlending()
{
	cv::Mat image = cv::imread("../WindowsLogo.jpg");

	if (image.empty()) {
		std::cerr << "Error: Failed to load image." << std::endl;
		return -1;
	}

	Mat image = imread("../LinuxLogo.jpg");
	if (image.empty())
	{
		cout << "Could not open or find the image!\n" << endl;
		return -1;
	}
	Mat new_image = Mat::zeros(image.size(), image.type());
	double alpha = 1.0;
	int beta = 0;
	cout << " Basic Linear Transforms " << endl;
	cout << "-------------------------" << endl;
	cout << "* Enter the alpha value [1.0-3.0]: "; cin >> alpha;
	cout << "* Enter the beta value [0-100]: "; cin >> beta;
	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			for (int c = 0; c < image.channels(); c++) {
				new_image.at<Vec3b>(y, x)[c] =
					saturate_cast<uchar>(alpha * image.at<Vec3b>(y, x)[c] + beta);
			}
		}
	}
	imshow("Original Image", image);
	imshow("New Image", new_image);

	waitKey();
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