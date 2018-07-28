#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//img = imread("C:\\OpenCV331\\00_images\\lena.jpg");

int main()
{
	//Color Image
	Mat imgColor = imread("baboon200.jpg");

	//imshow("imgColor", imgColor);

	int colNumber = imgColor.cols;	//取得影像寬度
	int rowNumber = imgColor.rows;	//取得影像高度

	int i, j;
	for (int k = 0; k< 3000; k++)
	{
		i = rand() % rowNumber;
		j = rand() % colNumber;

		imgColor.at<Vec3b>(i, j)[0] = 0;
		imgColor.at<Vec3b>(i, j)[1] = 0;
		imgColor.at<Vec3b>(i, j)[2] = 0;

	}

	//imshow("imgColorNew", imgColor);
	imwrite("baboon200.jpg", imgColor);

	waitKey(0);

	return 0;
}
