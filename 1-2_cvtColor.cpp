#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat img;
	Mat imgGray;

	img = imread("saveImage.png");
	//img = imread("C:\\OpenCV331\\00_images\\lena.jpg");

	if (img.empty())
	{
		cout << "Can not load file(image)!" << endl;

		system("pause");
		return -1;
	}


	namedWindow("SrcImg", WINDOW_AUTOSIZE);

	cvtColor(img, imgGray, CV_BGR2GRAY);
	imshow("SrcImg", imgGray);


	waitKey(0);
	

	return 0;
}
