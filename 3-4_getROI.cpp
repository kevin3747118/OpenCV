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

	int srcX = 100;
	int srcY = 20;

	int offsetX = 200;
	int offsetY = 300;


	//[方法1] 使用 Rect : Rect(x, y, w/cols, h/rows)
	//Mat imgROI_1 = imgSrc(Rect(起始X, 起始Y, 位移量X, 位移量Y));
	//imshow("ROI_1", imgROI_1);	//顯示選定的 ROI


	//[方法2] 使用 Range : (y, h/rows) (x, w/cols)
	//Mat imgROI_2 = imgSrc(Range(srcY, srcY + offsetY), Range(srcX, srcX + offsetX));
	//imshow("ROI_2", imgROI_2);	//顯示選定的 ROI

	
	//畫個矩形框 for 驗證
	rectangle(imgSrc,
		Point(srcX, srcY),
		Point(srcX + offsetX, srcY + offsetY),
		Scalar(0, 255, 0), 5, 4);


	//顯示來源影像
	imshow("SrcImg", imgSrc);


	//保存 ROI 影像
	//imwrite("ROI.bmp", imgROI_1);


	waitKey(0);
	return 0;
}