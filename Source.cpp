#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat img;

	//img = imread("lena.jpg");
	img = imread("C:\\Users\\User\\Downloads\\00_images-20180721T013810Z-001\\00_images\\fruits.jpg", 0);

	if (img.empty())
	{
		cout << "Can not load file(image)!" << endl;

		system("pause");
		return -1;
	}

	//建立視窗
	namedWindow("@@", WINDOW_NORMAL);

	//顯示圖像
	imshow("@@", img);

	//save pic to local
	//imwrite("saveImage.png", img);

	//等待時間 or 按鍵盤任意鍵
	waitKey(0);


	return 0;
}
