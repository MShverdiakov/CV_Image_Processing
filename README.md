# CV_Image_Processing

learning opencv, making basic function while reading a documentation. Learned a lot while making this project, lot of fun

## Image rotation
rotation of image using rotation matrix, just multiplying the all pixels.

## Image blending
getting alpha and beta saturation of two images, and multiplying all pixels and color channels using formula $\alpha * p{x, y} + \beta$

## Color correction
you can give a color scale or RGB of needed color, and program will scale every color channel by that factor

## Bilinear transform
inputing polynom like $x_new = 0.1 * x + 0.9 * y + 0.002 * x * y$ and that is new position of pixel
