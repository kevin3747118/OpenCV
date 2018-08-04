#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//ROI 左上角點 (x,y)
Point ROI_LTpt(-1, -1);      

//ROI 右下角點 (x,y)
Point ROI_RBpt(-1, -1);

Mat imgSrc;	//Source Image
Mat imgCpy;	//Copy Image
Mat imgROI;	//ROI Image

enum DrawMode 
{
	Status_Clear,		//清除
	Status_onDraw,		//繪製中
	Status_DrawDone		//繪製完成
}; 

DrawMode statusDraw = Status_Clear;

void onMouse(int Event, int x, int y, int flags, void* param);

int main()
{
	imgSrc = imread("baboon.jpg");

	if (imgSrc.empty())
	{
		cout << "影像載入失敗" << endl;
		return -1;
	}
	imshow("SrcImg", imgSrc);
	
	namedWindow("SrcImg", 0);
	setMouseCallback("SrcImg", onMouse, NULL);

	while (true) 
	{
		//使用 ESC 退出
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
		//cout << "左鍵按下" << endl;
		break;

	case CV_EVENT_MOUSEMOVE:   
		ROI_RBpt.x = x;
		ROI_RBpt.y = y;
		//cout << "滑鼠移動" << endl;
		break;

	case CV_EVENT_LBUTTONUP:  
		ROI_RBpt.x = x;
		ROI_RBpt.y = y;
		statusDraw = Status_Clear;
		//cout << "左鍵放開" << endl;
		break;
	}

	//繪製四邊形
	if (statusDraw == Status_onDraw && ROI_LTpt.x != -1 && ROI_RBpt.x != -1) 
	{
		imgSrc.copyTo(imgCpy);
		rectangle(imgCpy, Rect(ROI_LTpt, ROI_RBpt), Scalar(0, 0, 255), 2);
		imshow("SrcImg", imgCpy);
	}

	// 複製 ROI
	if (Event == CV_EVENT_LBUTTONUP)
	{
		destroyWindow("ROI");
		try 
		{
			//從這裡開始 : 

			//Step1. 設定 ROI 區域
			//Rect ROIarea(起始X, 起始Y, 位移量X, 位移量Y);
			
			//Step2. 使用 copyTo : 將 ROI 區域 複製到 imgROI
			//imgSrc(ROI 區域).copyTo(目標圖片空間);

			//Step3. 使用 imshow 檢視 imgROI
			//imshow("視窗名稱", imgROI);
		}
		catch (Exception exception)
		{
			//座標確認
			cout << exception.msg << endl;
		}
	}

}
