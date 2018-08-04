#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

using namespace std;
using namespace cv;

#define WINDOW_NAME "dstImgWin"

Mat srcImg;
Mat dstImg;

int ContrastValue = 20;
int BrightValue = 20;

void OnChange(int, void*)
{
	//公式 : g(i,j) = a * f(i,j) + b

	double alpha = (double)ContrastValue / 100.0;
	int beta = BrightValue;

	for (int i = 0; i<srcImg.rows; i++)
	{
		for (int j = 0; j<srcImg.cols; j++)
		{
			//B channel 
			dstImg.at<Vec3b>(i, j)[0] =
				saturate_cast<uchar>(alpha * srcImg.at<Vec3b>(i, j)[0] + beta);

			//G channel 
			dstImg.at<Vec3b>(i, j)[1] =
				saturate_cast<uchar>(alpha * srcImg.at<Vec3b>(i, j)[1] + beta);

			//R channel 
			dstImg.at<Vec3b>(i, j)[2] =
				saturate_cast<uchar>(alpha * srcImg.at<Vec3b>(i, j)[2] + beta);
		}
	}

	imshow("srcImg", srcImg);
	imshow(WINDOW_NAME, dstImg);
}


int main()
{
	srcImg = imread("baboon.jpg");
	dstImg = Mat::zeros(srcImg.size(), srcImg.type());

	//Mat::zeros();		//將matrix 元素都設為 0
	//Mat::ones();		//將matrix 元素都設為 1

	namedWindow(WINDOW_NAME, CV_WINDOW_AUTOSIZE);

	// Contrast: 對比度
	// Brightness: 亮度

	createTrackbar("Contrast", WINDOW_NAME, &ContrastValue, 300, OnChange, 0);
	createTrackbar("Bright", WINDOW_NAME, &BrightValue, 200, OnChange, 0);

	OnChange(ContrastValue, 0);
	OnChange(BrightValue, 0);

	waitKey(0);

}