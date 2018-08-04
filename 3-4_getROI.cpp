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

	int srcX = 100;
	int srcY = 20;

	int offsetX = 200;
	int offsetY = 300;


	//[��k1] �ϥ� Rect : Rect(x, y, w/cols, h/rows)
	//Mat imgROI_1 = imgSrc(Rect(�_�lX, �_�lY, �첾�qX, �첾�qY));
	//imshow("ROI_1", imgROI_1);	//��ܿ�w�� ROI


	//[��k2] �ϥ� Range : (y, h/rows) (x, w/cols)
	//Mat imgROI_2 = imgSrc(Range(srcY, srcY + offsetY), Range(srcX, srcX + offsetX));
	//imshow("ROI_2", imgROI_2);	//��ܿ�w�� ROI

	
	//�e�ӯx�ή� for ����
	rectangle(imgSrc,
		Point(srcX, srcY),
		Point(srcX + offsetX, srcY + offsetY),
		Scalar(0, 255, 0), 5, 4);


	//��ܨӷ��v��
	imshow("SrcImg", imgSrc);


	//�O�s ROI �v��
	//imwrite("ROI.bmp", imgROI_1);


	waitKey(0);
	return 0;
}