#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat img;

	img = imread("lena.jpg");
	//img = imread("C:\\OpenCV331\\00_images\\lena.jpg");

	if (img.empty())
	{
		cout << "Can not load file(image)!" << endl;

		system("pause");
		return -1;
	}

	//建立視窗
	namedWindow("SrcImg", WINDOW_AUTOSIZE);

	//顯示圖像
	imshow("SrcImg", img);

	//等待時間 or 按鍵盤任意鍵
	waitKey(0);
	

	return 0;
}
