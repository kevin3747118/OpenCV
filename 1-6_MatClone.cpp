#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//img = imread("C:\\OpenCV331\\00_images\\lena.jpg");

int main()
{
	Mat img1(240, 320, CV_8U, Scalar(255));

	Mat img2, img3, img4;

	img2 = img1;
	img1.copyTo(img3);
	img4 = img1.clone();

	imshow("SrcImg1", img1);
	imshow("SrcImg2", img2);
	imshow("SrcImg3", img3);
	imshow("SrcImg4", img4);

//	printf("address of img1¡G%p\n", &img1);
//	printf("address of img2¡G%p\n", &img2);
//	printf("address of img3¡G%p\n", &img3);
//	printf("address of img4¡G%p\n", &img4);

	waitKey(0);

	return 0;
}
