#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//img = imread("C:\\OpenCV331\\00_images\\lena.jpg");

int main()
{
	/////////////////////////////////////////////
	Point pt1(20, 30);

	Point pt2;
	pt2.x = 20;
	pt2.y = 10;

	/////////////////////////////////////////////
	Rect rect1(20, 30, 150, 100);

	Rect rect2;
	rect2.x = 20;
	rect2.y = 30;
	rect2.width = 150;
	rect2.height = 100;

	int RectArea = rect2.area();

	/////////////////////////////////////////////
	Size size1(320, 240);

	Size size2;
	size2.width = 150;
	size2.height = 100;
	
	int Area = size2.area();

	/////////////////////////////////////////////	
	Scalar color(255);

	Mat img1(size1, CV_8U, color);
	imshow("SrcImg1", img1);

	waitKey(0);

	/////////////////////////////////////////////

	return 0;
}
