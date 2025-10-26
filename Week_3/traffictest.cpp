#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;

Mat getColor(Mat img,int hmin,int smin,int vmin,int hmax,int smax,int vmax){
    Mat imgHSV,imgmask;
    cvtColor(img,imgHSV,COLOR_BGR2HSV);
    Scalar lower(hmin,smin,vmin);
    Scalar upper(hmax,smax,vmax);
    inRange(imgHSV,lower,upper,imgmask);
    return imgmask;
}

void getContour(Mat imgproc,Mat img,char ch){
    std::vector<std::vector<Point>> contours;
    std::vector<Vec4i> hierarchy;
    findContours(imgproc,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    std::vector<std::vector<Point>> conpoly(contours.size());
    for(int i = 0;i < contours.size();i++){
        int area = contourArea(contours[i]);
        std::cout << area << std::endl;
        if(area > 25000 && area < 37000){
            float peri = arcLength(contours[i],true);
            approxPolyDP(contours[i], conpoly[i], 0.02 * peri,true);
            drawContours(img,conpoly,i,Scalar(255,0,0),3);
            std::vector<Rect> boundRect(contours.size());
            boundRect[i] = boundingRect(conpoly[i]);
            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
            if(ch == 'r'){
                putText(img,"red",Point(50,50),FONT_ITALIC,2,Scalar(0,0,255),5);
            }
            else if(ch == 'g'){
                putText(img,"green",Point(50,50),FONT_ITALIC,2,Scalar(255,0,0),5);
            }
        }
    }
}

int main(){
    VideoCapture cap("TrafficLight.mp4");
    VideoWriter out;
    out.open("./result.avi",VideoWriter::fourcc('D','I','V','X'),
    cap.get(CAP_PROP_FPS),Size(cap.get(CAP_PROP_FRAME_WIDTH),
    cap.get(CAP_PROP_FRAME_HEIGHT)),true);
    while(true){
        Mat img;
        cap.read(img);
        Mat imgmaskR = getColor(img,175,123,76,179,246,255);
        Mat imgmaskG = getColor(img,72,200,76,101,246,255);
        getContour(imgmaskR,img,'r');
        getContour(imgmaskG,img,'g');
        imshow("a",img);
        waitKey(1);
        out << img;
    }
}