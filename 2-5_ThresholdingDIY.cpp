#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//img = imread("C:\\OpenCV331\\00_images\\lena.jpg");

//練習 : 利用Pixel Accress 方法
//嘗試寫一個自己的 閾值分析

int main()
{
	//載入待處理圖片
	Mat imgSrc = imread("lena.jpg");

	//灰階圖
	Mat imgGray;	

	//目標影像(二值圖) : 保持原影像尺寸, 但僅用一通道即可
	Mat imgWB(imgSrc.size().height, imgSrc.size().width, CV_8UC1);

	if (imgSrc.empty())
	{
		cout << "影像載入失敗" << endl;
		return -1;
	}

	cvtColor(imgSrc, imgGray, COLOR_BGR2GRAY);

	imshow("winImg", imgSrc);		//顯示來源影像
	imshow("winGray", imgGray);		//看一下灰階化的結果


	int colNumber = imgGray.cols;	//取得影像 寬度
	int rowNumber = imgGray.rows;	//取得影像 高度

	
	int thrd = 128;		//自己先定義一個門檻值
	int grayValue = 0;
	for (int i = 0; i<rowNumber; i++)
	{
		for (int j = 0; j<colNumber; j++)
		{
			//判斷灰階圖的門檻值
			//grayValue = imgGray. ?????   (取出該pixel的灰階值)

			
			//二值圖給值 Value
			//imgWB.at<uchar>(i, j) = ????;

		}
	}


	//最後的二值圖
	imshow("winWB", imgWB);		

	waitKey(0);
	return 0;
}
