#include <opencv2/opencv.hpp>
#include <time.h>

using namespace std;
using namespace cv;

//img = imread("C:\\OpenCV331\\00_images\\lena.jpg");

int genColorValue()
{
	//�ͦ� 0 ~ 255 �����ü�
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

	//step1. �إߤ@�ӦǶ��Ϫ��Ŷ� (Mat Buffer)
	Mat imgGray;

	//step2. �N�m����ন�Ƕ��� (cvtColor)
	cvtColor(imgColor, imgGray, CV_BGR2GRAY);

	//step3. �T�{�@�U�Ƕ��Ϫ����A (imshow)
	imshow("imgGray", imgGray);


	int colNumber = imgColor.cols;	//���o�v���e��
	int rowNumber = imgColor.rows;	//���o�v������

	int i, j;
	int colorValue;
	colorValue = genColorValue();

	for (int k = 0; k< 5000; k++)
	{
		i = rand() % rowNumber;
		j = rand() % colNumber;

		//�b�Ƕ��ϤW�[�J���T/�����I
		imgColor.at<Vec3b>(i, j) = 120;
	}

	imshow("imgColorNew", imgColor);

	//step4. �T�{�s���Ƕ��Ϫ��A (imshow)


	waitKey(0);


	return 0;
}
