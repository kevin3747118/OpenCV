#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//img = imread("C:\\OpenCV331\\00_images\\lena.jpg");

int main()
{

	//Gray Image
	Mat imgGray(240, 320, CV_8UC1);
	imgGray = Scalar::all(0);

	//Color Image
	Mat imgColor(240, 320, CV_8UC3, Scalar(255, 0, 0));

	imshow("imgGray", imgGray);
	imshow("imgColor", imgColor);

	int colNumber = imgGray.cols;	//取得影像寬度
	int rowNumber = imgGray.rows;	//取得影像高度


	for (int i = 0; i<100; i++)
	{
		for (int j = 0; j<100; j++)
		{
			//Gray Value
			imgGray.at<uchar>(i, j) = 128;

			//Color Value
			imgColor.at<Vec3b>(i, j)[0] = 255;		// B Color
			imgColor.at<Vec3b>(i, j)[1] = 0;		// G Color
			imgColor.at<Vec3b>(i, j)[2] = 255;		// R Color
		}
	}

	imshow("imgGrayNew", imgGray);
	imshow("imgColorNew", imgColor);

	waitKey(0);

	return 0;
}
