#include <opencv2/opencv.hpp>
#include <time.h>

using namespace std;
using namespace cv;

//img = imread("C:\\OpenCV331\\00_images\\lena.jpg");

int genColorValue()
{
	//生成 0 ~ 255 間的亂數
	srand( time(NULL) );
	int  min = 0;
	int  max = 255;

	int  genValue = 0.0;

	genValue = (max - min) * rand() / (RAND_MAX + 1.0) + min;
		
	return genValue;
}

int main()
{

	//Color Image
	Mat imgColor = imread("lena.jpg");

	//Gray Image

	//step1. 建立一個灰階圖的空間 (Mat Buffer)
	Mat imgGray;

	//step2. 將彩色圖轉成灰階圖 (cvtColor)
	cvtColor(imgColor, imgGray, CV_BGR2GRAY);

	//step3. 確認一下灰階圖的狀態 (imshow)
	imshow("imgGray", imgGray);


	int colNumber = imgColor.cols;	//取得影像寬度
	int rowNumber = imgColor.rows;	//取得影像高度

	int i, j;
	int colorValue;
	colorValue = genColorValue();

	for (int k = 0; k< 5000; k++)
	{
		i = rand() % rowNumber;
		j = rand() % colNumber;

		//在灰階圖上加入雜訊/雪花點
		imgColor.at<Vec3b>(i, j) = 120;
	}

	imshow("imgColorNew", imgColor);

	//step4. 確認新的灰階圖狀態 (imshow)


	waitKey(0);


	return 0;
}
