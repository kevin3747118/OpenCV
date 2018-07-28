#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//img = imread("C:\\OpenCV331\\00_images\\lena.jpg");

Mat imgSrc;
Mat imgGray;
Mat imgBW;

int thrdSlider;
const int thrdSliderMax = 255;
void OnTrackBar(int value1, void* value2);

int main()
{
	imgSrc = imread("catNoise01.jpg");

	if (imgSrc.empty())
	{
		cout << "影像載入失敗" << endl;
		return -1;
	}
	
	cvtColor(imgSrc, imgGray, COLOR_BGR2GRAY);

	namedWindow("winImg", WINDOW_AUTOSIZE);
	namedWindow("winGray", WINDOW_AUTOSIZE);
	namedWindow("winThrd", WINDOW_AUTOSIZE);

	imshow("winImg", imgSrc);
	imshow("winGray", imgGray);


	thrdSlider = 50;
	char trackbarName[15];
	sprintf_s(trackbarName, "Thrd %d", thrdSliderMax);

	createTrackbar(trackbarName, "winThrd", &thrdSlider,
		thrdSliderMax, OnTrackBar);


	waitKey(0);
	return 0;
}


void OnTrackBar(int value1, void* value2)
{
	threshold(imgGray, imgBW, thrdSlider, thrdSliderMax, CV_THRESH_BINARY);
	imshow("winThrd", imgBW);
}
