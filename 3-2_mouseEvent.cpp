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
			//step2. �e�u : �_�I�� pt ���I�Υثe �� x,y
			//line(imgEvent, �_�I, Point(���Ix, ���Iy), Scalar(0, 255, 0), 2, 8);

			//step3. �e�x�� : �_�I�� pt ���I�Υثe �� x,y
			//rectangle(imgEvent, �_�I, Point(���Ix, ���Iy), Scalar(0, 255, 0), 2, 8);

			break;

		default:
			break;
	}

	if(event == CV_EVENT_RBUTTONDOWN)
	{
		cout<<"Mouse down"<<endl;

		//Step1. �e�� : �Υثe�� x,y ����
		//circle(imgEvent, Point(���X, ���Y), 80, Scalar(255, 255, 0), 2, 8);
	}

	if (event == CV_EVENT_MBUTTONDOWN)
	{
		cout << "Clean" << endl;

		//�N��i image �񺡶¦�
		imgEvent = Scalar::all(0);  
	}

}

int main()
{
	Mat img(512, 512, CV_8UC3, Scalar(0, 0, 0));
	
	//�ŧi�@�Ө㦳�W�٪� windows
	namedWindow("MouseEvent", CV_WINDOW_AUTOSIZE);
	
	//�N�I�s�禡�̪��b���w�� windows �W
	setMouseCallback("MouseEvent", OnMouse, &img);

	while(1)
	{
		imshow("MouseEvent", img);
		
		if(waitKey(10) == 27)	//ESC �h�X 
			break;
	}

//	imshow("DrawAPI", drawImg);
	waitKey(0);

}