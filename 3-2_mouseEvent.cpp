#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


Point pt;

void OnMouse(int event, int x, int y, int flags, void* param)
{
	Mat imgEvent = *(Mat*) param;

	switch(event)
	{
		case CV_EVENT_LBUTTONDOWN:
			pt.x = x;
			pt.y = y;
			printf("(x,y) = (%3d,%3d)\n", x, y);
			break;

		case CV_EVENT_LBUTTONUP:
			//step2. 畫線 : 起點用 pt 終點用目前 的 x,y
			//line(imgEvent, 起點, Point(終點x, 終點y), Scalar(0, 255, 0), 2, 8);

			//step3. 畫矩形 : 起點用 pt 終點用目前 的 x,y
			//rectangle(imgEvent, 起點, Point(終點x, 終點y), Scalar(0, 255, 0), 2, 8);

			break;

		default:
			break;
	}

	if(event == CV_EVENT_RBUTTONDOWN)
	{
		cout<<"Mouse down"<<endl;

		//Step1. 畫圓 : 用目前的 x,y 當圓心
		//circle(imgEvent, Point(圓心X, 圓心Y), 80, Scalar(255, 255, 0), 2, 8);
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

	while(1)
	{
		imshow("MouseEvent", img);
		
		if(waitKey(10) == 27)	//ESC 退出 
			break;
	}

//	imshow("DrawAPI", drawImg);
	waitKey(0);

}