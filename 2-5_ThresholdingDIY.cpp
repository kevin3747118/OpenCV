#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//img = imread("C:\\OpenCV331\\00_images\\lena.jpg");

//�m�� : �Q��Pixel Accress ��k
//���ռg�@�Ӧۤv�� �H�Ȥ��R

int main()
{
	//���J�ݳB�z�Ϥ�
	Mat imgSrc = imread("lena.jpg");

	//�Ƕ���
	Mat imgGray;	

	//�ؼмv��(�G�ȹ�) : �O����v���ؤo, ���ȥΤ@�q�D�Y�i
	Mat imgWB(imgSrc.size().height, imgSrc.size().width, CV_8UC1);

	if (imgSrc.empty())
	{
		cout << "�v�����J����" << endl;
		return -1;
	}

	cvtColor(imgSrc, imgGray, COLOR_BGR2GRAY);

	imshow("winImg", imgSrc);		//��ܨӷ��v��
	imshow("winGray", imgGray);		//�ݤ@�U�Ƕ��ƪ����G


	int colNumber = imgGray.cols;	//���o�v�� �e��
	int rowNumber = imgGray.rows;	//���o�v�� ����

	
	int thrd = 128;		//�ۤv���w�q�@�Ӫ��e��
	int grayValue = 0;
	for (int i = 0; i<rowNumber; i++)
	{
		for (int j = 0; j<colNumber; j++)
		{
			//�P�_�Ƕ��Ϫ����e��
			//grayValue = imgGray. ?????   (���X��pixel���Ƕ���)

			
			//�G�ȹϵ��� Value
			//imgWB.at<uchar>(i, j) = ????;

		}
	}


	//�̫᪺�G�ȹ�
	imshow("winWB", imgWB);		

	waitKey(0);
	return 0;
}
