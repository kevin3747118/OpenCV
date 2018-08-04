#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main()
{
	Mat imgSrc = imread("baboon.jpg");
	
	if (imgSrc.empty())
	{
		cout << "�v�����J����" << endl;
		return -1;
	}

	//��ܨӷ��v��
	imshow("SrcImg", imgSrc);

/*
	//�إߨ̭ӥ��ª��v�� : �ϥΨӷ��Ϫ��j�p
	Mat maskImg = Mat::zeros(imgSrc.size(), CV_8UC1);
	//�˵��B�n
	imshow("maskImg", maskImg);
	//�O�s mask �v��
	imwrite("mask.jpg", maskImg);
*/

	Mat maskImg = imread("mask.jpg");
	
	//�˵��B�n
	imshow("maskImg", maskImg);

	//==== �Q�ξB�n�Ӱ��ǳB�z ====/
	
	//�v���ƻs
	Mat imgCpyAll;
	imgSrc.copyTo(imgCpyAll);
	imshow("imgCpyAll", imgCpyAll);


	//�a���B�n���v���ƻs
	Mat imgCpyMask;	
	imgSrc.copyTo(imgCpyMask, /*��J�B�n*/ );
	imshow("imgCpyMask", imgCpyMask);

	// why ���� ????


	waitKey(0);
	return 0;
}





//threshold(maskImg, maskImg, 150, 255, THRESH_BINARY);