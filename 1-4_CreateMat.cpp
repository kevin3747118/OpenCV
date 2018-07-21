#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat img1(240, 320, CV_8U);
	Mat img2(240, 320, CV_8U, Scalar(100));
	Mat img3(240, 320, CV_8UC3, Scalar(255, 0, 0));

	imshow("SrcImg1", img1);
	imshow("SrcImg2", img2);
	imshow("SrcImg3", img3);

	waitKey(0);


	return 0;
}
