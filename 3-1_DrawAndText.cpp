#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main()
{
	//Step1. 建立一個畫布(三通道彩色圖) : 512x512 & 黑底色
	//Mat drawImg(影像高, 影像寬, CV_8UC3, Scalar(給B值, 給G值, 給R值));

	
	//---------------------------------------------//

	//Step2. 畫直線 : 起點(100,10) --> 終點(320, 100) & 綠色 & 線粗為 8 & 4連通
	//line(drawImg, Point(給X值, 給Y值), Point(給X值, 給Y值), Scalar(給B值, 給G值, 給R值), 線粗大小, 幾連通);
	

	//---------------------------------------------//

	//Step3. 繪製圓(空心) : 圓心(150, 150) & 半徑100 & 顏色任選 & 線粗為 4 & 8連通
	//circle(目標圖片, Point(圓心X, 圓心Y), 半徑大小, Scalar(給B值, 給G值, 給R值), 線粗大小, 幾連通); 
	
	
	//畫一個實心的圓 thickness : CV_FILLED 或 負值
	//circle(目標圖片, Point(圓心X, 圓心Y), 半徑大小, Scalar(給B值, 給G值, 給R值), thickness, 幾連通); 

	
	//---------------------------------------------//

	//Step4. 畫矩形 : 起點左上(10,10) --> 終點右下(240, 200) & 顏色任選(128, 255, 0) & 線粗任選 & 8連通
	//rectangle(目標圖片, Point(左上X, 左上Y), Point(右下X, 右下Y), Scalar(給B值, 給G值, 給R值), 線粗大小, 幾連通);
	
	
	//Step5. 畫矩形填充的四邊形(實心) thickness : CV_FILLED 或 負值
	//rectangle(drawImg, Rect(起點X, 起點Y, 起點X+W, 起點Y+H), Scalar(給B值, 給G值, 給R值), thickness, 8);


	//---------------------------------------------//

	//Step6. [補充] 繪製橢圓
	//ellipse(drawImg, Point(150, 150), Size(100, 50), 45, 0, 360, Scalar(0, 255, 0), 2, 8);
	
	//Step7. 變數給值方式
	/*
		Point center(300, 300);
		Size axes(40, 80);
		double angle = 90;
		int lineWidth = 5;

		ellipse(drawImg, center, axes, angle, 0, 360, Scalar(255, 0, 0), 4);
	*/

	//---------------------------------------------//

/*
	//Step8. 繪製多邊形 
	const int NPT = 5;

	Point points[1][NPT];
		points[0][0] = Point(230, 270);
		points[0][1] = Point(240, 220);
		points[0][2] = Point(310, 255);
		points[0][3] = Point(334, 326);
		points[0][4] = Point(228, 346);

	const Point* pts[1] = { points[0] };
	
	bool bClosed = true;	//可以是非封閉多邊形
	polylines(drawImg, pts, &NPT, 1, bClosed, Scalar(255, 128, 0), 6);
*/

	//---------------------------------------------//

/*
	//Step9. 文字處理
	int lineWidth = 2;
	double fontScale = 1;
	const Scalar whiteColor(255, 255, 255), pinkColor(230, 130, 255);

	//putText(drawImg, string("ITtraining"), Point(100, 440), CV_FONT_HERSHEY_COMPLEX, 字體大小, 字體顏色, 幾連通);
	//putText(drawImg, string("OpenCV"), Point(200, 480), CV_FONT_HERSHEY_COMPLEX, 字體大小, 字體顏色, 幾連通);
*/


	imshow("DrawAPI", drawImg);
	waitKey(0);

}