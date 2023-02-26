#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("C:/opencv4.7.0/shapes/right triangle.PNG");
    //Mat image = imread("C:/opencv4.7.0/shapes/right triangle.PNG");

    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    imshow("gray", gray);
    Mat edges;
    Canny(gray, edges, 50, 200);
    imshow("edges", edges);
    Mat blur;
    GaussianBlur(edges, blur, Size(5, 5), 0);
    imshow("blur", blur);
    vector<vector<Point>> contours;
    findContours(blur, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    bool isRightTriangle = false;
    vector<Point> polygon;
    approxPolyDP(contours[0], polygon, 10, true);
    Point vertices[3];
    for (int i = 0; i < 3; i++) {
        vertices[i] = polygon[i];
    }
    double angles[3];
    for (int i = 0; i < 3; i++) {
        Point side1 = vertices[(i + 1) % 3] - vertices[i];
        Point side2 = vertices[(i + 2) % 3] - vertices[i];
        double len1 = norm(side1);
        double len2 = norm(side2);
        double dotprod = side1.dot(side2);
        double angle = acos(dotprod / (len1 * len2)) * 180 / CV_PI;
        angles[i] = angle;
        }
    for (int i = 0; i < 3; i++) {
        if (abs(angles[i] - 90) < 10) {
                isRightTriangle = true;
                break;
            }
        }
    string geoName;
    if (isRightTriangle) {
        geoName = "Right triangle";
        cout << "The triangle is a right triangle." << endl;
    }
    else {
        geoName = "Triangle";
        cout << "The triangle is not a right triangle." << endl;
    }
    putText(image, geoName, { 1,10 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255), 1);
    drawContours(image, contours, 0, Scalar(255, 0, 255), 2);
    imshow("image", image);
    waitKey(0);
    destroyAllWindows();
    return 0;
}
