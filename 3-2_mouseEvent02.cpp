#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Point pt;

int srcPtSet = 0;

void OnMouse(int event, int x, int y, int flags, void* param)
{
	Mat imgEvent = *(Mat*)param;

	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
		pt.x = x;
		pt.y = y;

		srcPtSet = 1;

		break;

	case CV_EVENT_LBUTTONUP:
		line(imgEvent, pt, Point(x, y), Scalar(0, 255, 0), 2, 8);

		srcPtSet = 0;
		break;

case CV_EVENT_MOUSEMOVE:
	if (srcPtSet == 1)
	{
		imgEvent = Scalar::all(0);
		line(imgEvent, pt, Point(x, y), Scalar(0, 255, 0), 2, 8);
	}
		break;

	default:
		break;
	}

	if (event == CV_EVENT_RBUTTONDOWN)
	{
		cout << "Mouse down" << endl;
		circle(imgEvent, Point(x, y), 80, Scalar(255, 255, 0), 2, 8);
	}

	if (event == CV_EVENT_MBUTTONDOWN)
	{
		cout << "Clean" << endl;

		//將整張 image 填滿黑色
		imgEvent = Scalar::all(0);
	}

}

int main()
{
	Mat img(512, 512, CV_8UC3, Scalar(0, 0, 0));

	//宣告一個具有名稱的 windows
	namedWindow("MouseEvent", CV_WINDOW_AUTOSIZE);

	//將呼叫函式依附在指定的 windows 上
	setMouseCallback("MouseEvent", OnMouse, &img);

	while (1)
	{
		imshow("MouseEvent", img);

		if (waitKey(10) == 27)	//ESC 退出 
			break;
	}

	//	imshow("DrawAPI", drawImg);
	waitKey(0);

}