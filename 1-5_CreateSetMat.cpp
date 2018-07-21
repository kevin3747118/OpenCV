#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat img1;
	img1.create(300, 400, CV_8UC1);

	//img1 = Scalar::all(255);

	int row = img1.;	//圖片高度 from img1
	int col = img1.;	//圖片寬度 from img1

	Size imgSize = Size(col, row);

	Mat img2(imgSize.height, imgSize.width, CV_8UC3, Scalar(0, 0, 255));
	Mat img3(imgSize, CV_8UC3, Scalar(0, 255, 255));

	imshow("SrcImg1", img1);
	imshow("SrcImg2", img2);
	imshow("SrcImg3", img3);

	waitKey(0);

	return 0;
}
