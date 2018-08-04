#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main()
{
	Mat imgSrc = imread("baboon.jpg");
	
	if (imgSrc.empty())
	{
		cout << "影像載入失敗" << endl;
		return -1;
	}

	//顯示來源影像
	imshow("SrcImg", imgSrc);

/*
	//建立依個全黑的影像 : 使用來源圖的大小
	Mat maskImg = Mat::zeros(imgSrc.size(), CV_8UC1);
	//檢視遮罩
	imshow("maskImg", maskImg);
	//保存 mask 影像
	imwrite("mask.jpg", maskImg);
*/

	Mat maskImg = imread("mask.jpg");
	
	//檢視遮罩
	imshow("maskImg", maskImg);

	//==== 利用遮罩來做些處理 ====/
	
	//影像複製
	Mat imgCpyAll;
	imgSrc.copyTo(imgCpyAll);
	imshow("imgCpyAll", imgCpyAll);


	//帶有遮罩的影像複製
	Mat imgCpyMask;	
	imgSrc.copyTo(imgCpyMask, /*放入遮罩*/ );
	imshow("imgCpyMask", imgCpyMask);

	// why 毛邊 ????


	waitKey(0);
	return 0;
}





//threshold(maskImg, maskImg, 150, 255, THRESH_BINARY);