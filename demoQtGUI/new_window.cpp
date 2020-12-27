#include "new_window.h"
#include "demoQtGUI.h"
#include <QMouseEvent>
#include <QPainter>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
using namespace cv;

new_window::new_window(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
}

new_window::~new_window()
{
}

void new_window::on_showImagePushButton_clicked()
{
	//clickNumber = 0;
	QImage img_child;
	img_child.load("G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\newPicture.bmp");
	ui.displayPictureLabel->setPixmap(QPixmap::fromImage(img_child));
	cropIdentifier = 0;
}
void new_window::on_clearClickNumberPushButton_clicked()
{
	clickNumber = 0;
}
void new_window::mousePressEvent(QMouseEvent* event)
{	
	if (clickNumber == 0)
	{
		if (cropIdentifier == 0)
		{
			// (x, y)为以label为坐标原点，label控件中鼠标位置
			// event->x()为以窗口左上角为坐标原点的鼠标位置；ui.label->x()为控件label左上角在窗口中的位置
			float x = (event->x()) - (ui.displayPictureLabel->x());
			float y = (event->y()) - (ui.displayPictureLabel->y());
			// 将x，y通过signal传递
			ui.mouseLabel->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			ui.imageLabel1->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			// 将buf中的数据通过signal传递
			// QString buf = "(" + QString::number(x) + "," + QString::number(y) + ")";
			// emit sendStringCoordinate(buf);
			Point2f imageCoordinate1 = Point2f(x, y);
			srcPoints.push_back(imageCoordinate1);
			// 图像坐标转换成将机器坐标
			// machineX, machineY为拍摄该图片时对应的机器坐标
			// Position 1
			int machineX = 0x00025D86;
			int machineY = 0x00024342;
			Point2f machineCoordinate1 = image2machine(x, y, machineX, machineY);
			machinePoints.push_back(machineCoordinate1);
			// 在图片上将鼠标点击的位置画出来
			QString fileName = "G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\newPicture.bmp";
			paintClickedPoint(fileName, x, y);
		}
		else if (cropIdentifier == 1)
		{
			float cropx = event->x() - (ui.displayPictureLabel->x());
			float cropy = event->y() - (ui.displayPictureLabel->y());
			float x = 640 + 0.25 * ((event->x()) - (ui.displayPictureLabel->x()) - 640);
			float y = 480 + 0.25 * ((event->y()) - (ui.displayPictureLabel->y()) - 480);
			ui.mouseLabel->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			ui.imageLabel1->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			Point2f imageCoordinate1 = Point2f(x, y);
			srcPoints.push_back(imageCoordinate1);
			int machineX = 0x00025D86;
			int machineY = 0x00024342;
			Point2f machineCoordinate1 = image2machine(x, y, machineX, machineY);
			machinePoints.push_back(machineCoordinate1);
			QString fileName = "G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\cropPicture.bmp";
			paintClickedPoint(fileName, cropx, cropy);
		}
	}
	if (clickNumber == 1)
	{
		if (cropIdentifier == 0)
		{
			float x = (event->x()) - (ui.displayPictureLabel->x());
			float y = (event->y()) - (ui.displayPictureLabel->y());
			ui.mouseLabel->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			ui.imageLabel2->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			Point2f imageCoordinate2 = Point2f(x, y);
			srcPoints.push_back(imageCoordinate2);
			// Position 2
			int machineX = 0x0002AD86;
			int machineY = 0x00024342;
			Point2f machineCoordinate2 = image2machine(x, y, machineX, machineY);
			machinePoints.push_back(machineCoordinate2);
			QString fileName = "G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\newPicture.bmp";
			paintClickedPoint(fileName, x, y);
		}
		else if (cropIdentifier == 1)
		{
			float cropx = event->x() - (ui.displayPictureLabel->x());
			float cropy = event->y() - (ui.displayPictureLabel->y());
			float x = 640 + 0.25 * ((event->x()) - (ui.displayPictureLabel->x()) - 640);
			float y = 480 + 0.25 * ((event->y()) - (ui.displayPictureLabel->y()) - 480);
			ui.mouseLabel->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			ui.imageLabel2->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			Point2f imageCoordinate2 = Point2f(x, y);
			srcPoints.push_back(imageCoordinate2);
			int machineX = 0x0002AD86;
			int machineY = 0x00024342;
			Point2f machineCoordinate2 = image2machine(x, y, machineX, machineY);
			machinePoints.push_back(machineCoordinate2);
			QString fileName = "G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\cropPicture.bmp";
			paintClickedPoint(fileName, cropx, cropy);
		}
	}
	if (clickNumber == 2)
	{
		if (cropIdentifier == 0)
		{
			float x = (event->x()) - (ui.displayPictureLabel->x());
			float y = (event->y()) - (ui.displayPictureLabel->y());
			ui.mouseLabel->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			ui.imageLabel3->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			Point2f imageCoordinate3 = Point2f(x, y);
			srcPoints.push_back(imageCoordinate3);
			// position 3
			int machineX = 0x0002AD86;
			int machineY = 0x0001E342;
			Point2f machineCoordinate3 = image2machine(x, y, machineX, machineY);
			machinePoints.push_back(machineCoordinate3);
			QString fileName = "G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\newPicture.bmp";
			paintClickedPoint(fileName, x, y);
		}
		else if (cropIdentifier == 1)
		{
			float cropx = event->x() - (ui.displayPictureLabel->x());
			float cropy = event->y() - (ui.displayPictureLabel->y());
			float x = 640 + 0.25 * ((event->x()) - (ui.displayPictureLabel->x()) - 640);
			float y = 480 + 0.25 * ((event->y()) - (ui.displayPictureLabel->y()) - 480);
			ui.mouseLabel->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			ui.imageLabel3->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			Point2f imageCoordinate3 = Point2f(x, y);
			srcPoints.push_back(imageCoordinate3);
			int machineX = 0x0002AD86;
			int machineY = 0x0001E342;
			Point2f machineCoordinate3 = image2machine(x, y, machineX, machineY);
			machinePoints.push_back(machineCoordinate3);
			QString fileName = "G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\cropPicture.bmp";
			paintClickedPoint(fileName, cropx, cropy);
		}
	}
	if (clickNumber == 3)
	{
		if (cropIdentifier == 0)
		{
			float x = (event->x()) - (ui.displayPictureLabel->x());
			float y = (event->y()) - (ui.displayPictureLabel->y());
			ui.mouseLabel->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			ui.imageLabel4->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			Point2f imageCoordinate4 = Point2f(x, y);
			srcPoints.push_back(imageCoordinate4);
			// position 4
			int machineX = 0x00025D86;
			int machineY = 0x0001E342;
			Point2f machineCoordinate4 = image2machine(x, y, machineX, machineY);
			machinePoints.push_back(machineCoordinate4);
			QString fileName = "G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\newPicture.bmp";
			paintClickedPoint(fileName, x, y);
		}
		else if (cropIdentifier == 1)
		{
			float cropx = event->x() - (ui.displayPictureLabel->x());
			float cropy = event->y() - (ui.displayPictureLabel->y());
			float x = 640 + 0.25 * ((event->x()) - (ui.displayPictureLabel->x()) - 640);
			float y = 480 + 0.25 * ((event->y()) - (ui.displayPictureLabel->y()) - 480);
			ui.mouseLabel->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			ui.imageLabel4->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			Point2f imageCoordinate4 = Point2f(x, y);
			srcPoints.push_back(imageCoordinate4);
			// position 4
			int machineX = 0x00025D86;
			int machineY = 0x0001E342;
			Point2f machineCoordinate4 = image2machine(x, y, machineX, machineY);
			machinePoints.push_back(machineCoordinate4);
			QString fileName = "G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\cropPicture.bmp";
			paintClickedPoint(fileName, cropx, cropy);
		}
	}
	if (clickNumber == 4)
	{
		if (cropIdentifier == 0)
		{
			float x = (event->x()) - (ui.displayPictureLabel->x());
			float y = (event->y()) - (ui.displayPictureLabel->y());
			ui.mouseLabel->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			ui.imageLabel5->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			Point2f imageCoordinate5 = Point2f(x, y);
			srcPoints.push_back(imageCoordinate5);
			// position 5
			int machineX = 0x0001ED86;
			int machineY = 0x0001E342;
			Point2f machineCoordinate5 = image2machine(x, y, machineX, machineY);
			machinePoints.push_back(machineCoordinate5);
			QString fileName = "G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\newPicture.bmp";
			paintClickedPoint(fileName, x, y);
		}
		else if (cropIdentifier == 1)
		{
			float cropx = event->x() - (ui.displayPictureLabel->x());
			float cropy = event->y() - (ui.displayPictureLabel->y());
			float x = 640 + 0.25 * ((event->x()) - (ui.displayPictureLabel->x()) - 640);
			float y = 480 + 0.25 * ((event->y()) - (ui.displayPictureLabel->y()) - 480);
			ui.mouseLabel->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			ui.imageLabel5->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			Point2f imageCoordinate5 = Point2f(x, y);
			srcPoints.push_back(imageCoordinate5);
			// position 5
			int machineX = 0x0001ED86;
			int machineY = 0x0001E342;
			Point2f machineCoordinate5 = image2machine(x, y, machineX, machineY);
			machinePoints.push_back(machineCoordinate5);
			QString fileName = "G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\cropPicture.bmp";
			paintClickedPoint(fileName, cropx, cropy);
		}
	}
	if (clickNumber == 5)
	{
		if (cropIdentifier == 0)
		{
			float x = (event->x()) - (ui.displayPictureLabel->x());
			float y = (event->y()) - (ui.displayPictureLabel->y());
			ui.mouseLabel->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			ui.imageLabel6->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			Point2f imageCoordinate6 = Point2f(x, y);
			srcPoints.push_back(imageCoordinate6);
			// position 6
			int machineX = 0x0001ED86;
			int machineY = 0x00024342;
			Point2f machineCoordinate6 = image2machine(x, y, machineX, machineY);
			machinePoints.push_back(machineCoordinate6);
			QString fileName = "G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\newPicture.bmp";
			paintClickedPoint(fileName, x, y);
		}
		else if (cropIdentifier == 1)
		{
			float cropx = event->x() - (ui.displayPictureLabel->x());
			float cropy = event->y() - (ui.displayPictureLabel->y());
			float x = 640 + 0.25 * ((event->x()) - (ui.displayPictureLabel->x()) - 640);
			float y = 480 + 0.25 * ((event->y()) - (ui.displayPictureLabel->y()) - 480);
			ui.mouseLabel->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			ui.imageLabel6->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			Point2f imageCoordinate6 = Point2f(x, y);
			srcPoints.push_back(imageCoordinate6);
			// position 6
			int machineX = 0x0001ED86;
			int machineY = 0x00024342;
			Point2f machineCoordinate6 = image2machine(x, y, machineX, machineY);
			machinePoints.push_back(machineCoordinate6);
			QString fileName = "G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\cropPicture.bmp";
			paintClickedPoint(fileName, cropx, cropy);
		}
	}
	if (clickNumber == 6)
	{
		if (cropIdentifier == 0)
		{
			float x = (event->x()) - (ui.displayPictureLabel->x());
			float y = (event->y()) - (ui.displayPictureLabel->y());
			ui.mouseLabel->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			ui.imageLabel7->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			Point2f imageCoordinate7 = Point2f(x, y);
			srcPoints.push_back(imageCoordinate7);
			// position 7
			int machineX = 0x0001FD86;
			int machineY = 0x0002A342;
			Point2f machineCoordinate7 = image2machine(x, y, machineX, machineY);
			machinePoints.push_back(machineCoordinate7);
			QString fileName = "G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\newPicture.bmp";
			paintClickedPoint(fileName, x, y);
		}
		else if (cropIdentifier == 1)
		{
			float cropx = event->x() - (ui.displayPictureLabel->x());
			float cropy = event->y() - (ui.displayPictureLabel->y());
			float x = 640 + 0.25 * ((event->x()) - (ui.displayPictureLabel->x()) - 640);
			float y = 480 + 0.25 * ((event->y()) - (ui.displayPictureLabel->y()) - 480);
			ui.mouseLabel->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			ui.imageLabel7->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			Point2f imageCoordinate7 = Point2f(x, y);
			srcPoints.push_back(imageCoordinate7);
			// position 7
			int machineX = 0x0001FD86;
			int machineY = 0x0002A342;
			Point2f machineCoordinate7 = image2machine(x, y, machineX, machineY);
			machinePoints.push_back(machineCoordinate7);
			QString fileName = "G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\cropPicture.bmp";
			paintClickedPoint(fileName, cropx, cropy);
		}
	}
	if (clickNumber == 7)
	{
		if (cropIdentifier == 0)
		{
			float x = (event->x()) - (ui.displayPictureLabel->x());
			float y = (event->y()) - (ui.displayPictureLabel->y());
			ui.mouseLabel->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			ui.imageLabel8->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			Point2f imageCoordinate8 = Point2f(x, y);
			srcPoints.push_back(imageCoordinate8);
			// position 8
			int machineX = 0x00023D86;
			int machineY = 0x0002A342;
			Point2f machineCoordinate8 = image2machine(x, y, machineX, machineY);
			machinePoints.push_back(machineCoordinate8);
			QString fileName = "G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\newPicture.bmp";
			paintClickedPoint(fileName, x, y);
		}
		else if (cropIdentifier == 1)
		{
			float cropx = event->x() - (ui.displayPictureLabel->x());
			float cropy = event->y() - (ui.displayPictureLabel->y());
			float x = 640 + 0.25 * ((event->x()) - (ui.displayPictureLabel->x()) - 640);
			float y = 480 + 0.25 * ((event->y()) - (ui.displayPictureLabel->y()) - 480);
			ui.mouseLabel->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			ui.imageLabel8->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			Point2f imageCoordinate8 = Point2f(x, y);
			srcPoints.push_back(imageCoordinate8);
			// position 8
			int machineX = 0x00023D86;
			int machineY = 0x0002A342;
			Point2f machineCoordinate8 = image2machine(x, y, machineX, machineY);
			machinePoints.push_back(machineCoordinate8);
			QString fileName = "G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\cropPicture.bmp";
			paintClickedPoint(fileName, cropx, cropy);
		}
	}
	if (clickNumber == 8)
	{
		if (cropIdentifier == 0)
		{
			float x = (event->x()) - (ui.displayPictureLabel->x());
			float y = (event->y()) - (ui.displayPictureLabel->y());
			ui.mouseLabel->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			ui.imageLabel9->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			Point2f imageCoordinate9 = Point2f(x, y);
			srcPoints.push_back(imageCoordinate9);
			// position 9
			int machineX = 0x0002AD86;
			int machineY = 0x0002B342;
			Point2f machineCoordinate9 = image2machine(x, y, machineX, machineY);
			machinePoints.push_back(machineCoordinate9);
			QString fileName = "G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\newPicture.bmp";
			paintClickedPoint(fileName, x, y);
		}
		else if (cropIdentifier == 1)
		{
			float cropx = event->x() - (ui.displayPictureLabel->x());
			float cropy = event->y() - (ui.displayPictureLabel->y());
			float x = 640 + 0.25 * ((event->x()) - (ui.displayPictureLabel->x()) - 640);
			float y = 480 + 0.25 * ((event->y()) - (ui.displayPictureLabel->y()) - 480);
			ui.mouseLabel->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			ui.imageLabel9->setText("(" + QString::number(x) + "," + QString::number(y) + ")");
			Point2f imageCoordinate9 = Point2f(x, y);
			srcPoints.push_back(imageCoordinate9);
			// position 9
			int machineX = 0x0002AD86;
			int machineY = 0x0002B342;
			Point2f machineCoordinate9 = image2machine(x, y, machineX, machineY);
			machinePoints.push_back(machineCoordinate9);
			QString fileName = "G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\cropPicture.bmp";
			paintClickedPoint(fileName, cropx, cropy);
		}
	}
	clickNumber++;
	if ((clickNumber == 4) && (currentPoint == 4))
	{
		//emit sendImageCoordinate(srcPoints);
		emit sendMachineCoordinate(machinePoints);
	}
	if ((clickNumber == 9) && (currentPoint == 9))
	{
		//emit sendImageCoordinate(srcPoints);
		emit sendMachineCoordinate(machinePoints);
	}
}
void new_window::paintClickedPoint(QString fileName, float pointx, float pointy)
{
	QPixmap pix;
	pix.load(fileName);
	pix = pix.scaled(ui.displayPictureLabel->width(), ui.displayPictureLabel->height());
	QPainter painter(&pix);
	QPen pen;
	pen.setColor(Qt::red);
	pen.setWidth(3);
	painter.setPen(pen);
	painter.drawEllipse(QPoint(pointx, pointy), 1, 1);
	ui.displayPictureLabel->setPixmap(pix);
	pix.save(fileName);
}
Point new_window::image2machine(float imagex, float imagey, int machinex, int machiney)
{
	float imageMidPointX = 640;
	float imageMidPointY = 480;
	float imageDiffX = imageMidPointX - imagex;
	float imageDiffY = imageMidPointY - imagey;
	// 图像坐标与机器坐标之间的转换关系为：x图像坐标与图像中心差值乘53.55，y图像坐标与图像中心差值乘53
	//int machineDiffX = round(-53.55 * imageDiffX);
	int machineDiffX = round(-55 * imageDiffX);
	int machineDiffY = round(55 * imageDiffY);
	// 转换为机器坐标
	int machineXCoordinate = machinex + machineDiffX;
	int machineYCoordinate = machiney + machineDiffY;
	Point machineCoordinate = Point(machineXCoordinate, machineYCoordinate);
	return machineCoordinate;
}
void new_window::recvCurrentPointNumber(int currentPointNum)
{
	ui.pointNumLabel->setText(QString::fromLocal8Bit("请点击") + QString::number(currentPointNum) + QString::fromLocal8Bit("个点"));
	currentPoint = currentPointNum;
}
void new_window::on_cropPushButton_clicked()
{
	Mat originalPicture = imread("G:\\Qt_adjust\\demoQtGUI\\demoQtGUI\\newPicture.bmp");
	cropPicture = originalPicture(Rect(480, 360, 320, 240));
	imwrite("cropPicture.bmp", cropPicture);
	QImage smallPicture = Mat2QImage(cropPicture);
	ui.displayPictureLabel->setScaledContents(true);
	ui.displayPictureLabel->setPixmap(QPixmap::fromImage(smallPicture));
	cropIdentifier = 1;
}
QImage new_window::Mat2QImage(Mat cvImg)
{
	Mat cvRgbImg;
	cvtColor(cvImg, cvRgbImg, CV_BGR2RGB);
    cv::resize(cropPicture, cropPicture, Size(320, 240));
	QImage dstImage((const uchar*)cvRgbImg.data, cvRgbImg.cols, cvRgbImg.rows, cvRgbImg.step, QImage::Format_RGB888);
	dstImage.bits();
	return dstImage;
}