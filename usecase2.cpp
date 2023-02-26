#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    CascadeClassifier facemodelCC;
    try{
        facemodelCC.load("C:/opencv/haarcascade_frontalface_default.xml");
    }
    catch(const exception& e){
        cerr << "error loading face model" << e.what() << endl;
        return -1;
    }
    VideoCapture video("C:/opencv/troels.mp4");
    try{
        if (!video.isOpened()) {
            throw runtime_error("Could not open video file");
        }
    }
    catch (const exception& e){
        cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
    Mat frame;
    while (video.read(frame)) {
        Mat grayscMat;
        cvtColor(frame, grayscMat, COLOR_BGR2GRAY);
        vector<Rect> facesVectRect;
        facemodelCC.detectMultiScale(grayscMat, facesVectRect);

        for (const Rect& face : facesVectRect) {
            rectangle(frame, face, Scalar(0, 255, 0), 2);
        }
        imshow("Face detection", frame);
        char c = waitKey(1);
        if (c == 27) {
            break;
        }
    }
    video.release();
    destroyAllWindows();
    return 0;
}
