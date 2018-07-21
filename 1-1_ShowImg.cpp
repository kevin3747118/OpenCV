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

	//�إߵ���
	namedWindow("SrcImg", WINDOW_AUTOSIZE);

	//��ܹϹ�
	imshow("SrcImg", img);

	//���ݮɶ� or ����L���N��
	waitKey(0);
	

	return 0;
}
