#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//img = imread("C:\\OpenCV331\\00_images\\lena.jpg");

int main()
{
	Mat img(240, 320, CV_8UC3, Scalar(200, 255, 0));
	imshow("imgSrc", img);

	//���o�v������
	int rowNum = img.rows;

	//���o�C�@ row ���`����
	int colNum = img.cols * img.channels();

	for (int i = 0; i<rowNum; i++)
	{
		//�����i�C�����a�}
		uchar* data = img.ptr<uchar>(i);

		//data[j] = 255;
		for (int j = 0; j<colNum; j++)
		{
			switch (j % 3)
			{
			case 0:  //B Color
				data[j] = 255;
				break;
			case 1:  //G Color
				data[j] = 0;
				break;
			case 2:  //R Color
				data[j] = 0;
				break;
			}
		}
	}

	imshow("imgDst", img);
	waitKey(0);
	
	return 0;
}
