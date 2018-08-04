#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int maskOP_color(Mat& srcImgColor, Mat& maskWB);


int main()
{
	Mat imgSrc = imread("uImageFish.jpg");
	
	if (imgSrc.empty())
	{
		cout << "影像載入失敗" << endl;
		return -1;
	}
	
	Mat imgSrcGray;
	cvtColor(imgSrc, imgSrcGray, CV_BGR2GRAY);

	//顯示來源影像
	imshow("SrcImg", imgSrc);

	Mat maskImg(imgSrcGray.rows, imgSrcGray.cols, CV_8UC1, Scalar(0, 0, 0));

	//製作一個橢圓形的遮罩
	ellipse(maskImg, Point(200, 200), Size(100, 150), 0, 0, 360, Scalar(255, 255, 255), -1, 8);
	
	//檢視遮罩
	imshow("maskImg", maskImg);  


	//==== 影像集合運算 AND ====/
	Mat dstImg;
	bitwise_and(imgSrcGray, maskImg, dstImg);
	imshow("image AND", dstImg);



	///////////////////////////////////////////////////

	//練習1 : 建立自己的 mask 遮罩

	///////////////////////////////////////////////////




	//練習2 : 寫一個 Function
	//用 mask 對彩色影像作遮罩提取
	//maskOP_color(imgSrc, maskImg);


	waitKey(0);
	return 0;
}


int maskOP_color(Mat& srcImgColor, Mat& maskWB)
{
	//Step1. 建立一個與來源圖大小相同的三通道影像
	Mat dstImgMaskOP(srcImgColor.rows, srcImgColor.cols, CV_8UC3, Scalar(0, 0, 0));

	//Step2. 得影像的 寬&高
	int rowNumber = srcImgColor.rows;	//取得影像 高度
	int colNumber = srcImgColor.cols;	//取得影像 寬度

	int grayValue = 0;

	//Pixel Access on Image
	for (int i = 0; i < rowNumber; i++)
	{
		for (int j = 0; j < colNumber; j++)
		{
			//Step3. 讀取 mask 的 pixel 值 
			//grayValue =  ???.at<uchar>(i, j);

			if (grayValue == 255)	// mask 此處為 255 時
			{
				//Step4.
				//將 來源影像的pixel 值 寫進 目的圖片 (dstImgMaskOP)

				//[提示] dstImgMaskOP.at<Vec3b>(i, j)[0] = ??
			}
		}
	}

	//顯示處理結果
	imshow("dstImgMaskOP", dstImgMaskOP);

	return 0;
}













//threshold(maskImg, maskImg, 150, 255, THRESH_BINARY);


/*
	//建立依個全黑的影像 : 使用來源圖的大小
	Mat maskImg = Mat::zeros(imgSrc.size(), CV_8UC1);
	//檢視遮罩
	imshow("maskImg", maskImg);
	//保存 mask 影像
	imwrite("mask.jpg", maskImg);
*/

