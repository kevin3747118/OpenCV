#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat img;

	img = imread("saveImage.png");
	//img = imread("lena.jpg", CV_LOAD_IMAGE_COLOR);
	//img = imread("C:\\OpenCV331\\00_images\\lena.jpg");

	if (img.empty())
	{
		cout << "Can not load file(image)!" << endl;

		system("pause");
		return -1;
	}

	//取得影像資訊
	printf("影像長度 : %d \n", img.cols);
	printf("影像寬度 : %d \n", img.rows);
	printf("影像通道數 : %d \n", img.channels());


	namedWindow("SrcImg", WINDOW_AUTOSIZE);


	while (true) {
		imshow("SrcImg", img);
		if (cvWaitKey(10) == 27) {
			break;
		}
	}


	return 0;
}
