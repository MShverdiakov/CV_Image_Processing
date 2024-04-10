#include <opencv2/opencv.hpp>

int imageRotation() {
    cv::Mat orig_image = cv::imread("../image.jpg"); // Загрузка изображения

    cv::Mat image;
    cv::Size newSize(500, 500); // Новый размер изображения

    cv::resize(orig_image, image, newSize);

    // Настройка параметров для поворота
    double angle = 45.0; // Угол поворота (в градусах)
    cv::Point2f center(image.cols / 2.0, image.rows / 2.0); // Центр вращения

    // Получение матрицы поворота
    cv::Mat rotationMatrix = cv::getRotationMatrix2D(center, angle, 0.6);

    // Применение поворота к изображению
    cv::Mat rotatedImage;
    cv::warpAffine(image, rotatedImage, rotationMatrix, image.size(), cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar());

    // Отображение повернутого изображения
    cv::namedWindow("Rotated Image", cv::WINDOW_NORMAL);
    cv::resizeWindow("Rotated Image", image.cols * 1.0, image.cols * 1.0);
    cv::imshow("Rotated Image", rotatedImage);

    cv::waitKey(0);

    return 0;
}