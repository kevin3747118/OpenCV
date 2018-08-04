#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//ROI ���W���I (x,y)
Point ROI_LTpt(-1, -1);      

//ROI �k�U���I (x,y)
Point ROI_RBpt(-1, -1);

Mat imgSrc;	//Source Image
Mat imgCpy;	//Copy Image
Mat imgROI;	//ROI Image

enum DrawMode 
{
	Status_Clear,		//�M��
	Status_onDraw,		//ø�s��
	Status_DrawDone		//ø�s����
}; 

DrawMode statusDraw = Status_Clear;

void onMouse(int Event, int x, int y, int flags, void* param);

int main()
{
	imgSrc = imread("baboon.jpg");

	if (imgSrc.empty())
	{
		cout << "�v�����J����" << endl;
		return -1;
	}
	imshow("SrcImg", imgSrc);
	
	namedWindow("SrcImg", 0);
	setMouseCallback("SrcImg", onMouse, NULL);

	while (true) 
	{
		//�ϥ� ESC �h�X
		if (cvWaitKey(33) == 27) 
		{
			break;
		}
	}

	waitKey(0);
	return 0;
}



void onMouse(int Event, int x, int y, int flags, void* param) 
{
	switch (Event)
	{
	case CV_EVENT_LBUTTONDOWN: 
		ROI_LTpt.x = x;
		ROI_LTpt.y = y;
		ROI_RBpt.x = -1;
		ROI_RBpt.y = -1;
		statusDraw = Status_onDraw;
		//cout << "������U" << endl;
		break;

	case CV_EVENT_MOUSEMOVE:   
		ROI_RBpt.x = x;
		ROI_RBpt.y = y;
		//cout << "�ƹ�����" << endl;
		break;

	case CV_EVENT_LBUTTONUP:  
		ROI_RBpt.x = x;
		ROI_RBpt.y = y;
		statusDraw = Status_Clear;
		//cout << "�����}" << endl;
		break;
	}

	//ø�s�|���
	if (statusDraw == Status_onDraw && ROI_LTpt.x != -1 && ROI_RBpt.x != -1) 
	{
		imgSrc.copyTo(imgCpy);
		rectangle(imgCpy, Rect(ROI_LTpt, ROI_RBpt), Scalar(0, 0, 255), 2);
		imshow("SrcImg", imgCpy);
	}

	// �ƻs ROI
	if (Event == CV_EVENT_LBUTTONUP)
	{
		destroyWindow("ROI");
		try 
		{
			//�q�o�̶}�l : 

			//Step1. �]�w ROI �ϰ�
			//Rect ROIarea(�_�lX, �_�lY, �첾�qX, �첾�qY);
			
			//Step2. �ϥ� copyTo : �N ROI �ϰ� �ƻs�� imgROI
			//imgSrc(ROI �ϰ�).copyTo(�ؼйϤ��Ŷ�);

			//Step3. �ϥ� imshow �˵� imgROI
			//imshow("�����W��", imgROI);
		}
		catch (Exception exception)
		{
			//�y�нT�{
			cout << exception.msg << endl;
		}
	}

}
