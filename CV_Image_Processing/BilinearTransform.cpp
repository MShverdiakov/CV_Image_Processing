#include <opencv2/opencv.hpp>

using namespace cv;


int bilinearTransform() {
    String path = "..\\image.jpg";
    Mat image = imread(path);



    Mat result = Mat::zeros(image.size(), image.type());

    for (int y = 0; y < image.rows; y++) {
        for (int x = 0; x < image.cols; x++) {
            double x_new = 0.1 * x + 0.9 * y + 0.002 * x * y;
            double y_new = 0.2 * x + 0.1 * y + 0.0022 * x * y;

            if (x_new >= 0 && x_new < image.cols && y_new >= 0 && y_new < image.rows) {
                result.at<Vec3b>((int)y_new, (int)x_new) = image.at<Vec3b>(y, x);
            }
        }
    }
    // Applying perspective transformation
    //Mat result;
    //warpPerspective(image, result, perspectiveMatrix, Size(image.cols, image.rows));

    // Displaying original and transformed images
    imshow("Original", image);
    imshow("Transformed", result);
    waitKey(0);
    destroyAllWindows();

    return 0;
}