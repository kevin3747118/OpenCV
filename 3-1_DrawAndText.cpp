#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main()
{
	//Step1. �إߤ@�ӵe��(�T�q�D�m���) : 512x512 & �©���
	//Mat drawImg(�v����, �v���e, CV_8UC3, Scalar(��B��, ��G��, ��R��));

	
	//---------------------------------------------//

	//Step2. �e���u : �_�I(100,10) --> ���I(320, 100) & ��� & �u�ʬ� 8 & 4�s�q
	//line(drawImg, Point(��X��, ��Y��), Point(��X��, ��Y��), Scalar(��B��, ��G��, ��R��), �u�ʤj�p, �X�s�q);
	

	//---------------------------------------------//

	//Step3. ø�s��(�Ť�) : ���(150, 150) & �b�|100 & �C����� & �u�ʬ� 4 & 8�s�q
	//circle(�ؼйϤ�, Point(���X, ���Y), �b�|�j�p, Scalar(��B��, ��G��, ��R��), �u�ʤj�p, �X�s�q); 
	
	
	//�e�@�ӹ�ߪ��� thickness : CV_FILLED �� �t��
	//circle(�ؼйϤ�, Point(���X, ���Y), �b�|�j�p, Scalar(��B��, ��G��, ��R��), thickness, �X�s�q); 

	
	//---------------------------------------------//

	//Step4. �e�x�� : �_�I���W(10,10) --> ���I�k�U(240, 200) & �C�����(128, 255, 0) & �u�ʥ��� & 8�s�q
	//rectangle(�ؼйϤ�, Point(���WX, ���WY), Point(�k�UX, �k�UY), Scalar(��B��, ��G��, ��R��), �u�ʤj�p, �X�s�q);
	
	
	//Step5. �e�x�ζ�R���|���(���) thickness : CV_FILLED �� �t��
	//rectangle(drawImg, Rect(�_�IX, �_�IY, �_�IX+W, �_�IY+H), Scalar(��B��, ��G��, ��R��), thickness, 8);


	//---------------------------------------------//

	//Step6. [�ɥR] ø�s���
	//ellipse(drawImg, Point(150, 150), Size(100, 50), 45, 0, 360, Scalar(0, 255, 0), 2, 8);
	
	//Step7. �ܼƵ��Ȥ覡
	/*
		Point center(300, 300);
		Size axes(40, 80);
		double angle = 90;
		int lineWidth = 5;

		ellipse(drawImg, center, axes, angle, 0, 360, Scalar(255, 0, 0), 4);
	*/

	//---------------------------------------------//

/*
	//Step8. ø�s�h��� 
	const int NPT = 5;

	Point points[1][NPT];
		points[0][0] = Point(230, 270);
		points[0][1] = Point(240, 220);
		points[0][2] = Point(310, 255);
		points[0][3] = Point(334, 326);
		points[0][4] = Point(228, 346);

	const Point* pts[1] = { points[0] };
	
	bool bClosed = true;	//�i�H�O�D�ʳ��h���
	polylines(drawImg, pts, &NPT, 1, bClosed, Scalar(255, 128, 0), 6);
*/

	//---------------------------------------------//

/*
	//Step9. ��r�B�z
	int lineWidth = 2;
	double fontScale = 1;
	const Scalar whiteColor(255, 255, 255), pinkColor(230, 130, 255);

	//putText(drawImg, string("ITtraining"), Point(100, 440), CV_FONT_HERSHEY_COMPLEX, �r��j�p, �r���C��, �X�s�q);
	//putText(drawImg, string("OpenCV"), Point(200, 480), CV_FONT_HERSHEY_COMPLEX, �r��j�p, �r���C��, �X�s�q);
*/


	imshow("DrawAPI", drawImg);
	waitKey(0);

}