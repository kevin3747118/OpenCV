#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//img = imread("C:\\OpenCV331\\00_images\\lena.jpg");
int showMatInfo(Mat& srcMat);

int main()
{
	Mat imgSrc;

	imgSrc = imread("fruits.jpg", 0);

	if (imgSrc.empty())
	{
		cout << "Can not load file(image)!" << endl;

		system("pause");
		return -1;
	}

	imshow("imgSrc", imgSrc);

	//設計一個 function 
	//可以列出影像 (Mat Buffer) 的所有屬性
	showMatInfo(imgSrc);


	waitKey(0);
	return 0;
}


int showMatInfo(Mat& srcMat)
{
	if (srcMat.empty())
	{
		printf("Mat buffer is empty ... ");
		return -1;
	}

	printf("Image(Mat) Infomation : \n");
	printf("=============================== \n");
	printf("cols(影像寬): %d \n", srcMat.cols);
	printf("rows(影像高): %d \n", srcMat.rows);
	printf("Image channels: %d \n", srcMat.channels());
	printf("Image dims: %d \n", srcMat.dims);
	printf("Image depth: %d \n", srcMat.depth());	//CV_xU
	printf("=============================== \n");

	//imshow("MatImg", srcMat);
	return 0;
}

