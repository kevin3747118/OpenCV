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

	//�]�p�@�� function 
	//�i�H�C�X�v�� (Mat Buffer) ���Ҧ��ݩ�
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
	printf("cols(�v���e): %d \n", srcMat.cols);
	printf("rows(�v����): %d \n", srcMat.rows);
	printf("Image channels: %d \n", srcMat.channels());
	printf("Image dims: %d \n", srcMat.dims);
	printf("Image depth: %d \n", srcMat.depth());	//CV_xU
	printf("=============================== \n");

	//imshow("MatImg", srcMat);
	return 0;
}

