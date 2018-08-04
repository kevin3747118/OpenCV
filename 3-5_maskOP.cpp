#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int maskOP_color(Mat& srcImgColor, Mat& maskWB);


int main()
{
	Mat imgSrc = imread("uImageFish.jpg");
	
	if (imgSrc.empty())
	{
		cout << "�v�����J����" << endl;
		return -1;
	}
	
	Mat imgSrcGray;
	cvtColor(imgSrc, imgSrcGray, CV_BGR2GRAY);

	//��ܨӷ��v��
	imshow("SrcImg", imgSrc);

	Mat maskImg(imgSrcGray.rows, imgSrcGray.cols, CV_8UC1, Scalar(0, 0, 0));

	//�s�@�@�Ӿ��Ϊ��B�n
	ellipse(maskImg, Point(200, 200), Size(100, 150), 0, 0, 360, Scalar(255, 255, 255), -1, 8);
	
	//�˵��B�n
	imshow("maskImg", maskImg);  


	//==== �v�����X�B�� AND ====/
	Mat dstImg;
	bitwise_and(imgSrcGray, maskImg, dstImg);
	imshow("image AND", dstImg);



	///////////////////////////////////////////////////

	//�m��1 : �إߦۤv�� mask �B�n

	///////////////////////////////////////////////////




	//�m��2 : �g�@�� Function
	//�� mask ��m��v���@�B�n����
	//maskOP_color(imgSrc, maskImg);


	waitKey(0);
	return 0;
}


int maskOP_color(Mat& srcImgColor, Mat& maskWB)
{
	//Step1. �إߤ@�ӻP�ӷ��Ϥj�p�ۦP���T�q�D�v��
	Mat dstImgMaskOP(srcImgColor.rows, srcImgColor.cols, CV_8UC3, Scalar(0, 0, 0));

	//Step2. �o�v���� �e&��
	int rowNumber = srcImgColor.rows;	//���o�v�� ����
	int colNumber = srcImgColor.cols;	//���o�v�� �e��

	int grayValue = 0;

	//Pixel Access on Image
	for (int i = 0; i < rowNumber; i++)
	{
		for (int j = 0; j < colNumber; j++)
		{
			//Step3. Ū�� mask �� pixel �� 
			//grayValue =  ???.at<uchar>(i, j);

			if (grayValue == 255)	// mask ���B�� 255 ��
			{
				//Step4.
				//�N �ӷ��v����pixel �� �g�i �ت��Ϥ� (dstImgMaskOP)

				//[����] dstImgMaskOP.at<Vec3b>(i, j)[0] = ??
			}
		}
	}

	//��ܳB�z���G
	imshow("dstImgMaskOP", dstImgMaskOP);

	return 0;
}













//threshold(maskImg, maskImg, 150, 255, THRESH_BINARY);


/*
	//�إߨ̭ӥ��ª��v�� : �ϥΨӷ��Ϫ��j�p
	Mat maskImg = Mat::zeros(imgSrc.size(), CV_8UC1);
	//�˵��B�n
	imshow("maskImg", maskImg);
	//�O�s mask �v��
	imwrite("mask.jpg", maskImg);
*/

