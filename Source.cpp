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

	//�إߵ���
	namedWindow("@@", WINDOW_NORMAL);

	//��ܹϹ�
	imshow("@@", img);

	//save pic to local
	//imwrite("saveImage.png", img);

	//���ݮɶ� or ����L���N��
	waitKey(0);


	return 0;
}
