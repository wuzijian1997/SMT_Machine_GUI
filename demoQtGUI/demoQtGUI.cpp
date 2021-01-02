// Project: SMT Machine GUI
// Version: Development 1.2
// Author: ZijianWu wuapply6@163.com
// Affiliation: Vision Measuring and Learning Lab, Automation Engineering School, UESTC 
// Date: 2021/01/02
// Note: Realise complete Batch Process Function.
#include "demoQtGUI.h"
#include <Eigen/Dense>
#include <QMessageBox>
#include <QLineEdit>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/core/eigen.hpp>
#include <iostream>
#include <vector>
#include <qdir.h>
#include <QTextStream>
#include <QDebug>
#include <QTimer>
#include <QObject>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>

using namespace cv;
using namespace std;
using namespace Eigen;

demoQtGUI::demoQtGUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	// QTimer 计时器
	timer = new QTimer(this);
	// img用于保存获得的摄像头图像为IQmage类型
	img = new QImage();
	// 超时就读取当前摄像头信息
	connect(timer, SIGNAL(timeout()), this, SLOT(getFrame()));
	// 获取当前可用的串口
	foreach(const QSerialPortInfo & info, QSerialPortInfo::availablePorts())
	{
		ui.portBox->addItem(info.portName());
	}
	serial = new QSerialPort(this);
	// 设置用几个点计算单应矩阵
	QString strPointNumber = ui.pointNumberBox->currentText();
	int pointNumber;
	pointNumber = strPointNumber.toInt();
	if (pointNumber == 4)
	{
		ui.positionPushButton5->setEnabled(false);
		ui.positionPushButton6->setEnabled(false);
		ui.positionPushButton7->setEnabled(false);
		ui.positionPushButton8->setEnabled(false);
		ui.positionPushButton9->setEnabled(false);
		ui.xyPushButton_5->setEnabled(false);
		ui.xyPushButton_6->setEnabled(false);
		ui.xyPushButton_7->setEnabled(false);
		ui.xyPushButton_8->setEnabled(false);
		ui.xyPushButton_9->setEnabled(false);
	}
	connect(ui.pointNumberBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeEnablePositionBtn()));
}
void demoQtGUI::on_readFilePushButton_clicked()
{
	// QString filePath = ui.readfilePushButton->text();
	// QFile类 提供了一个用于读／写文件的接口，它可以用来读／写文本文件、二进制文件和 Qt 资源的 I/O 设备
	// QFile file(filePath);
	QFile file("DPPB_0915_XY.txt");
	// QIODevice类 是Qt所有I/O设备的基础类，为QFIle等类提供一个抽象接口
	// QIODevice::Text 以文本方式打开文件
	if (!file.open(QFile::ReadOnly | QIODevice::Text))
	{
		qDebug() << file.errorString();
	}
	else
	{
		// 创建文件输出流in
		QTextStream in(&file);
		// 行数计数器
		int num = 0;
		while (!in.atEnd())
		{
			QString oneLine = in.readLine();
			num++;
		}
		ui.rowNumLabel->setText(QString::number(num));
		file.close();
	}
}
void demoQtGUI::on_displayTextPushButton_clicked()
{
	QFile file("DPPB_0915_XY.txt");
	bool ok = file.open(QIODevice::ReadOnly);
	if (ok)
	{
		QTextStream in(&file); {
			ui.textBrowser->setText(in.readAll());
			file.close();
		}
	}
}
void demoQtGUI::on_openCameraPushButton1_clicked()
{
	capture.open(1);
	capture.set(CAP_PROP_FRAME_WIDTH, 1280);
	capture.set(CAP_PROP_FRAME_HEIGHT, 960);
	timer->start(20);
	ui.savePhotoLabel1->setText("Camera opened! Now take a picture!");
}
void demoQtGUI::on_closeCameraPushButton1_clicked()
{
	timer->stop(); // stop getting frame
	ui.originalImageLabel1->clear();
	capture.release();
	ui.savePhotoLabel1->setText("Camera closed!");
}
void demoQtGUI::on_takePhotoPushButton1_clicked()
{
	capture.open(1);  // open camera（拍照时不一定正在拍摄，如果不加，没点打开摄像头会崩）
	capture.set(CAP_PROP_FRAME_WIDTH, 1280);
	capture.set(CAP_PROP_FRAME_HEIGHT, 960);
	capture >> showimage;
	line(showimage, Point(0, 480), Point(1280, 480), Scalar(255, 255, 0), 1);
	line(showimage, Point(640, 0), Point(640, 960), Scalar(255, 255, 0), 1);
	circle(showimage, Point(640, 480), 1, Scalar(255, 255, 0));
	QImage img = Mat2QImage(showimage);
	img.save("newPicture.bmp");
	ui.savePhotoLabel1->setText("Picture saved sucessfully!");
	// ui.processedimageLabel->setScaledContents(true);
	// ui.processedimageLabel->setPixmap(QPixmap::fromImage(img));
}
int demoQtGUI::getFrame()
{
	capture >> showimage;
	// 相机USB中断保护，通过提取相机的色调，连接时色调为0，中断时色调为先为13后变成-1
	double lightCapHue = capture.get(CAP_PROP_HUE);
	if (lightCapHue != 0)
	{
		timer->stop();
		ui.originalImageLabel1->clear();
		capture.release();
		ui.savePhotoLabel1->setText("Camera closed!");
		QString errorTitle = "error";
		QString errorContent = "Camera connection is broken! Please reopen the camera.";
		QMessageBox::critical(this, errorTitle, errorContent);
		return -1;
	}
	// 将图像从OpenCV格式转换成Qt格式
	QImage img = Mat2QImage(showimage);
	// setScaledContents() 实现图像自适应
	ui.originalImageLabel1->setScaledContents(true);
	// setPixmap()
	ui.originalImageLabel1->setPixmap(QPixmap::fromImage(img));
}
QImage demoQtGUI::Mat2QImage(Mat cvImg)
{
	Mat cvRgbImg;
	cvtColor(cvImg, cvRgbImg, CV_BGR2RGB);
	cv::resize(showimage, showimage, Size(1280, 960));
	QImage dstImage((const uchar*)cvRgbImg.data, cvRgbImg.cols, cvRgbImg.rows, cvRgbImg.step, QImage::Format_RGB888);
	dstImage.bits();
	return dstImage;
}
void demoQtGUI::on_newWindowPushButton1_clicked() 
{
	newWindow = new new_window;
	newWindow->show();
	// 从子窗口传过来的信号函数会被槽函数接受
	connect(newWindow, SIGNAL(sendMachineCoordinate(vector<Point2f>)), this, SLOT(calcMachineHomography(vector<Point2f>)));
	connect(this, SIGNAL(sendCurrentPointNumber(int)), newWindow, SLOT(recvCurrentPointNumber(int)));
}
void demoQtGUI::on_openSerialPushButton_clicked()
{
	if (ui.openSerialPushButton->text() == tr("Open Port"))
	{
		ui.openSerialPushButton->setText(tr("Colse Port"));
		serial->setPortName(ui.portBox->currentText());
		if (serial->open(QIODevice::ReadWrite))
		{
			ui.serialOutputTextBrowser->setText("Port opened");
			// Set Baud Rate
			serial->setBaudRate(QSerialPort::Baud115200);
			// Set Data Bits
			serial->setDataBits(QSerialPort::Data8);
			// Set Parity Bits
			serial->setParity(QSerialPort::NoParity);
			// Set Stop Bits
			serial->setStopBits(QSerialPort::OneStop);
			// Set Flow Control
			serial->setFlowControl(QSerialPort::NoFlowControl);
			// Link signal and slot
			connect(serial, SIGNAL(readyRead()), this, SLOT(readSerialData()));
		}
		else
		{
			ui.serialOutputTextBrowser->setText("Open failed");
		}
	}
	else
	{
		ui.openSerialPushButton->setText(tr("Open Port"));
		serial->close();
		ui.serialOutputTextBrowser->setText("Port colsed");
	}
}
void demoQtGUI::readSerialData()
{
	QByteArray buf;
	buf = serial->readAll();
	if (!buf.isEmpty())
	{
		QString str = ui.serialOutputTextBrowser->toPlainText();
		str += tr(buf);
		ui.serialOutputTextBrowser->clear();
		ui.serialOutputTextBrowser->append(str);
	}
}
void demoQtGUI::on_resetPushButton_clicked()
{
	QByteArray writedata;
	writedata[0] = 0xAA;
	writedata[1] = 0xAA;
	writedata[2] = 0x52;
	writedata[3] = 0x52;
	writedata[4] = 0x00;
	serial->write(writedata);
}
void demoQtGUI::on_positionPushButton1_clicked()
{
	QByteArray writedata;
	writedata[0] = 0xAA;
	writedata[1] = 0xAA;
	writedata[2] = 0x56;
	writedata[3] = 0x56;
	// Speed
	writedata[4] = 0x08;
	// R260
	// X Coordinate from low to high
	writedata[5] = 0x86;
	writedata[6] = 0x5D;
	writedata[7] = 0x02;
	writedata[8] = 0x00;
	// Y Coordinate from low to high
	writedata[9] = 0x42;
	writedata[10] = 0x43;
	writedata[11] = 0x02;
	writedata[12] = 0x00;
	writedata[13] = 0x00;
	serial->write(writedata);
}
void demoQtGUI::on_positionPushButton2_clicked()
{
	QByteArray writedata;
	writedata[0] = 0xAA;
	writedata[1] = 0xAA;
	writedata[2] = 0x56;
	writedata[3] = 0x56;
	// Speed
	writedata[4] = 0x08;
	// F14
	// X Coordinate from low to high
	writedata[5] = 0x86;
	writedata[6] = 0xAD;
	writedata[7] = 0x02;
	writedata[8] = 0x00;
	// Y Coordinate from low to high
	writedata[9] = 0x42;
	writedata[10] = 0x43;
	writedata[11] = 0x02;
	writedata[12] = 0x00;
	writedata[13] = 0x00;
	serial->write(writedata);
}
void demoQtGUI::on_positionPushButton3_clicked()
{
	QByteArray writedata;
	writedata[0] = 0xAA;
	writedata[1] = 0xAA;
	writedata[2] = 0x56;
	writedata[3] = 0x56;
	// speed
	writedata[4] = 0x08;
	// C115
	// X Coordinate from low to high
	writedata[5] = 0x86;
	writedata[6] = 0xAD;
	writedata[7] = 0x02;
	writedata[8] = 0x00;
	// Y Coordinate from low to high
	writedata[9] = 0x42;
	writedata[10] = 0xE3;
	writedata[11] = 0x01;
	writedata[12] = 0x00;
	writedata[13] = 0x00;
	serial->write(writedata);
}
void demoQtGUI::on_positionPushButton4_clicked()
{
	QByteArray writedata;
	writedata[0] = 0xAA;
	writedata[1] = 0xAA;
	writedata[2] = 0x56;
	writedata[3] = 0x56;
	// speed
	writedata[4] = 0x08;
	// U10
	// X Coordinate from low to high
	writedata[5] = 0x86;
	writedata[6] = 0x5D;
	writedata[7] = 0x02;
	writedata[8] = 0x00;
	// Y Coordinate from low to high
	writedata[9] = 0x42;
	writedata[10] = 0xE3;
	writedata[11] = 0x01;
	writedata[12] = 0x00;
	writedata[13] = 0x00;
	serial->write(writedata);
}
void demoQtGUI::on_positionPushButton5_clicked()
{
	QByteArray writedata;
	writedata[0] = 0xAA;
	writedata[1] = 0xAA;
	writedata[2] = 0x56;
	writedata[3] = 0x56;
	// speed
	writedata[4] = 0x08;
	// C112
	// X Coordinate from low to high
	writedata[5] = 0x86;
	writedata[6] = 0xED;
	writedata[7] = 0x01;
	writedata[8] = 0x00;
	// Y Coordinate from low to high
	writedata[9] = 0x42;
	writedata[10] = 0xE3;
	writedata[11] = 0x01;
	writedata[12] = 0x00;
	writedata[13] = 0x00;
	serial->write(writedata);
}
void demoQtGUI::on_positionPushButton6_clicked()
{
	QByteArray writedata;
	writedata[0] = 0xAA;
	writedata[1] = 0xAA;
	writedata[2] = 0x56;
	writedata[3] = 0x56;
	// speed
	writedata[4] = 0x08;
	// C105
	// X Coordinate from low to high
	writedata[5] = 0x86;
	writedata[6] = 0xED;
	writedata[7] = 0x01;
	writedata[8] = 0x00;
	// Y Coordinate from low to high
	writedata[9] = 0x42;
	writedata[10] = 0x43;
	writedata[11] = 0x02;
	writedata[12] = 0x00;
	writedata[13] = 0x00;
	serial->write(writedata);
}
void demoQtGUI::on_positionPushButton7_clicked()
{
	QByteArray writedata;
	writedata[0] = 0xAA;
	writedata[1] = 0xAA;
	writedata[2] = 0x56;
	writedata[3] = 0x56;
	// speed
	writedata[4] = 0x08;
	// R151
	// X Coordinate from low to high
	writedata[5] = 0x86;
	writedata[6] = 0xFD;
	writedata[7] = 0x01;
	writedata[8] = 0x00;
	// Y Coordinate from low to high
	writedata[9] = 0x42;
	writedata[10] = 0xA3;
	writedata[11] = 0x02;
	writedata[12] = 0x00;
	writedata[13] = 0x00;
	serial->write(writedata);
}
void demoQtGUI::on_positionPushButton8_clicked()
{
	QByteArray writedata;
	writedata[0] = 0xAA;
	writedata[1] = 0xAA;
	writedata[2] = 0x56;
	writedata[3] = 0x56;
	// speed
	writedata[4] = 0x08;
	// R165
	// X Coordinate from low to high
	writedata[5] = 0x86;
	writedata[6] = 0x3D;
	writedata[7] = 0x02;
	writedata[8] = 0x00;
	// Y Coordinate from low to high
	writedata[9] = 0x42;
	writedata[10] = 0xA3;
	writedata[11] = 0x02;
	writedata[12] = 0x00;
	writedata[13] = 0x00;
	serial->write(writedata);
}
void demoQtGUI::on_positionPushButton9_clicked()
{
	QByteArray writedata;
	writedata[0] = 0xAA;
	writedata[1] = 0xAA;
	writedata[2] = 0x56;
	writedata[3] = 0x56;
	// speed
	writedata[4] = 0x08;
	// F2
	// X Coordinate from low to high
	writedata[5] = 0x86;
	writedata[6] = 0xAD;
	writedata[7] = 0x02;
	writedata[8] = 0x00;
	// Y Coordinate from low to high
	writedata[9] = 0x42;
	writedata[10] = 0xB3;
	writedata[11] = 0x02;
	writedata[12] = 0x00;
	writedata[13] = 0x00;
	serial->write(writedata);
}
void demoQtGUI::on_autoPickPushButton_clicked()
{

}
void demoQtGUI::calcMachineHomography(vector<Point2f> machinePoints)
{
	if (ui.pointNumberBox->currentIndex() == 0)
	{
		Point2f fileCoordinate1 = Point2f(fileCoordinateX1, fileCoordinateY1);
		Point2f fileCoordinate2 = Point2f(fileCoordinateX2, fileCoordinateY2);
		Point2f fileCoordinate3 = Point2f(fileCoordinateX3, fileCoordinateY3);
		Point2f fileCoordinate4 = Point2f(fileCoordinateX4, fileCoordinateY4);
		Point2f fileCoordinate5 = Point2f(fileCoordinateX5, fileCoordinateY5);
		Point2f fileCoordinate6 = Point2f(fileCoordinateX6, fileCoordinateY6);
		Point2f fileCoordinate7 = Point2f(fileCoordinateX7, fileCoordinateY7);
		Point2f fileCoordinate8 = Point2f(fileCoordinateX8, fileCoordinateY8);
		Point2f fileCoordinate9 = Point2f(fileCoordinateX9, fileCoordinateY9);
		vector<Point2f> filePoints;
		filePoints.push_back(fileCoordinate1);
		filePoints.push_back(fileCoordinate2);
		filePoints.push_back(fileCoordinate3);
		filePoints.push_back(fileCoordinate4);
		filePoints.push_back(fileCoordinate5);
		filePoints.push_back(fileCoordinate6);
		filePoints.push_back(fileCoordinate7);
		filePoints.push_back(fileCoordinate8);
		filePoints.push_back(fileCoordinate9);
		// machineH = findHomography(machinePoints, filePoints);
		machineH = findHomography(filePoints, machinePoints);
		// 查看单应矩阵 machineH中的数据类型
		// int datatype = machineH.type();
		// ui.dataTypeLabel->setText(QString::number(datatype));
		double valueOfHomography[9] = { 0 };
		int n = 0;
		for (int j = 0; j < machineH.rows; j++)
		{
			for (int i = 0; i < machineH.cols; i++)
			{
				valueOfHomography[n] = machineH.at<double>(i, j);
				n++;
			}
		}
		ui.homographyLabel->setText(
			QString::number(valueOfHomography[0]) + ',' +
			QString::number(valueOfHomography[3]) + ',' +
			QString::number(valueOfHomography[6]) + ';' +
			QString::number(valueOfHomography[1]) + ',' +
			QString::number(valueOfHomography[4]) + ',' +
			QString::number(valueOfHomography[7]) + ';' +
			QString::number(valueOfHomography[2]) + ',' +
			QString::number(valueOfHomography[5]) + ',' +
			QString::number(valueOfHomography[8])
		);
	}
	else if (ui.pointNumberBox->currentIndex() == 1)
	{
		Point2f fileCoordinate1 = Point2f(fileCoordinateX1, fileCoordinateY1);
		Point2f fileCoordinate2 = Point2f(fileCoordinateX2, fileCoordinateY2);
		Point2f fileCoordinate3 = Point2f(fileCoordinateX3, fileCoordinateY3);
		Point2f fileCoordinate4 = Point2f(fileCoordinateX4, fileCoordinateY4);
		vector<Point2f> filePoints;
		filePoints.push_back(fileCoordinate1);
		filePoints.push_back(fileCoordinate2);
		filePoints.push_back(fileCoordinate3);
		filePoints.push_back(fileCoordinate4);
		// machineH = findHomography(machinePoints, filePoints);
		machineH = findHomography(filePoints, machinePoints);
		// 查看单应矩阵 machineH中的数据类型
		// int datatype = machineH.type();
		// ui.dataTypeLabel->setText(QString::number(datatype));

		double valueOfHomography[9] = { 0 };
		int n = 0;
		for (int j = 0; j < machineH.rows; j++)
		{
			for (int i = 0; i < machineH.cols; i++)
			{
				valueOfHomography[n] = machineH.at<double>(i, j);
				n++;
			}
		}
		ui.homographyLabel->setText(
			QString::number(valueOfHomography[0]) + ',' +
			QString::number(valueOfHomography[3]) + ',' +
			QString::number(valueOfHomography[6]) + ';' +
			QString::number(valueOfHomography[1]) + ',' +
			QString::number(valueOfHomography[4]) + ',' +
			QString::number(valueOfHomography[7]) + ';' +
			QString::number(valueOfHomography[2]) + ',' +
			QString::number(valueOfHomography[5]) + ',' +
			QString::number(valueOfHomography[8])
		);
	}
}
void demoQtGUI::on_xyPushButton_1_clicked()
{
	QString componentQString = ui.componentLineEdit_1->text();
	string componentString = componentQString.toStdString();
	string fileName = "DPPB_0915_XY.txt";
	map<string, vector<double>> m;
	m = getCoordinateFromFile(fileName);
	map<string, vector<double>>::iterator pos = m.find(componentString);
	fileCoordinateX1 = pos->second[0];
	fileCoordinateY1 = pos->second[1];
	fileRotationAngle1 = pos->second[2];
	ui.fileCoordinateLabel1->setText(QString::number(fileCoordinateX1, 'f', 3) + ',' + QString::number(fileCoordinateY1, 'f', 3));
}
void demoQtGUI::on_xyPushButton_2_clicked()
{
	QString componentQString = ui.componentLineEdit_2->text();
	string componentString = componentQString.toStdString();
	string fileName = "DPPB_0915_XY.txt";
	map<string, vector<double>> m;
	m = getCoordinateFromFile(fileName);
	map<string, vector<double>>::iterator pos = m.find(componentString);
	fileCoordinateX2 = pos->second[0];
	fileCoordinateY2 = pos->second[1];
	fileRotationAngle2 = pos->second[2];
	ui.fileCoordinateLabel2->setText(QString::number(fileCoordinateX2, 'f', 3) + ',' + QString::number(fileCoordinateY2, 'f', 3));
}
void demoQtGUI::on_xyPushButton_3_clicked()
{
	QString componentQString = ui.componentLineEdit_3->text();
	string componentString = componentQString.toStdString();
	string fileName = "DPPB_0915_XY.txt";
	map<string, vector<double>> m;
	m = getCoordinateFromFile(fileName);
	map<string, vector<double>>::iterator pos = m.find(componentString);
	fileCoordinateX3 = pos->second[0];
	fileCoordinateY3 = pos->second[1];
	fileRotationAngle3 = pos->second[2];
	ui.fileCoordinateLabel3->setText(QString::number(fileCoordinateX3, 'f', 3) + ',' + QString::number(fileCoordinateY3, 'f', 3));
}
void demoQtGUI::on_xyPushButton_4_clicked()
{
	QString componentQString = ui.componentLineEdit_4->text();
	string componentString = componentQString.toStdString();
	string fileName = "DPPB_0915_XY.txt";
	map<string, vector<double>> m;
	m = getCoordinateFromFile(fileName);
	map<string, vector<double>>::iterator pos = m.find(componentString);
	fileCoordinateX4 = pos->second[0];
	fileCoordinateY4 = pos->second[1];
	fileRotationAngle4 = pos->second[2];
	ui.fileCoordinateLabel4->setText(QString::number(fileCoordinateX4, 'f', 3) + ',' + QString::number(fileCoordinateY4, 'f', 3));
}
void demoQtGUI::on_xyPushButton_5_clicked()
{
	QString componentQString = ui.componentLineEdit_5->text();
	string componentString = componentQString.toStdString();
	string fileName = "DPPB_0915_XY.txt";
	map<string, vector<double>> m;
	m = getCoordinateFromFile(fileName);
	map<string, vector<double>>::iterator pos = m.find(componentString);
	fileCoordinateX5 = pos->second[0];
	fileCoordinateY5 = pos->second[1];
	fileRotationAngle5 = pos->second[2];
	ui.fileCoordinateLabel5->setText(QString::number(fileCoordinateX5, 'f', 3) + ',' + QString::number(fileCoordinateY5, 'f', 3));
}
void demoQtGUI::on_xyPushButton_6_clicked()
{
	QString componentQString = ui.componentLineEdit_6->text();
	string componentString = componentQString.toStdString();
	string fileName = "DPPB_0915_XY.txt";
	map<string, vector<double>> m;
	m = getCoordinateFromFile(fileName);
	map<string, vector<double>>::iterator pos = m.find(componentString);
	fileCoordinateX6 = pos->second[0];
	fileCoordinateY6 = pos->second[1];
	fileRotationAngle6 = pos->second[2];
	ui.fileCoordinateLabel6->setText(QString::number(fileCoordinateX6, 'f', 3) + ',' + QString::number(fileCoordinateY6, 'f', 3));
}
void demoQtGUI::on_xyPushButton_7_clicked()
{
	QString componentQString = ui.componentLineEdit_7->text();
	string componentString = componentQString.toStdString();
	string fileName = "DPPB_0915_XY.txt";
	map<string, vector<double>> m;
	m = getCoordinateFromFile(fileName);
	map<string, vector<double>>::iterator pos = m.find(componentString);
	fileCoordinateX7 = pos->second[0];
	fileCoordinateY7 = pos->second[1];
	fileRotationAngle7 = pos->second[2];
	ui.fileCoordinateLabel7->setText(QString::number(fileCoordinateX7, 'f', 3) + ',' + QString::number(fileCoordinateY7, 'f', 3));
}
void demoQtGUI::on_xyPushButton_8_clicked()
{
	QString componentQString = ui.componentLineEdit_8->text();
	string componentString = componentQString.toStdString();
	string fileName = "DPPB_0915_XY.txt";
	map<string, vector<double>> m;
	m = getCoordinateFromFile(fileName);
	map<string, vector<double>>::iterator pos = m.find(componentString);
	fileCoordinateX8 = pos->second[0];
	fileCoordinateY8 = pos->second[1];
	fileRotationAngle8 = pos->second[2];
	ui.fileCoordinateLabel8->setText(QString::number(fileCoordinateX8, 'f', 3) + ',' + QString::number(fileCoordinateY8, 'f', 3));
}
void demoQtGUI::on_xyPushButton_9_clicked()
{
	QString componentQString = ui.componentLineEdit_9->text();
	string componentString = componentQString.toStdString();
	string fileName = "DPPB_0915_XY.txt";
	map<string, vector<double>> m;
	m = getCoordinateFromFile(fileName);
	map<string, vector<double>>::iterator pos = m.find(componentString);
	fileCoordinateX9 = pos->second[0];
	fileCoordinateY9 = pos->second[1];
	fileRotationAngle9 = pos->second[2];
	ui.fileCoordinateLabel9->setText(QString::number(fileCoordinateX9, 'f', 3) + ',' + QString::number(fileCoordinateY9, 'f', 3));
}
void demoQtGUI::on_xyPushButton_clicked()
{
	QString componentQString = ui.componentLineEdit->text();
	string componentString = componentQString.toStdString();
	string fileName = "DPPB_0915_XY.txt";
	map<string, vector<double>> m;
	//m = getCoordinateFromFile(fileName, componentString);
	m = getCoordinateFromFile(fileName);
	map<string, vector<double>>::iterator pos = m.find(componentString);
	fileCoordinateX = pos->second[0];
	fileCoordinateY = pos->second[1];
	fileRotationAngle = pos->second[2];
	ui.fileCoordinateLabel->setText(QString::number(fileCoordinateX, 'f', 3) + ',' + QString::number(fileCoordinateY, 'f', 3));
	File2MachineCoordinate(fileCoordinateX, fileCoordinateY);
	ui.machineCoordinateLabel->setText(QString::number(machineCoordinateX) + ',' + QString::number(machineCoordinateY));
}
void demoQtGUI::on_movePushButton_clicked()
{
	QByteArray writedata;
	writedata[0] = 0xAA;
	writedata[1] = 0xAA;
	writedata[2] = 0x56;
	writedata[3] = 0x56;
	writedata[4] = 0x08;
	writedata[5] = (int)round(machineCoordinateX) & 0x000000ff;
	writedata[6] = (int)round(machineCoordinateX) >> 8 & 0x000000ff;
	writedata[7] = (int)round(machineCoordinateX) >> 16 & 0x000000ff;
	writedata[8] = (int)round(machineCoordinateX) >> 24 & 0x000000ff;
	writedata[9] = (int)round(machineCoordinateY) & 0x000000ff;
	writedata[10] = (int)round(machineCoordinateY) >> 8 & 0x000000ff;
	writedata[11] = (int)round(machineCoordinateY) >> 16 & 0x000000ff;
	writedata[12] = (int)round(machineCoordinateY) >> 24 & 0x000000ff;
	writedata[13] = 0x00;
	serial->write(writedata);
}
map<string, vector<double>> demoQtGUI::getCoordinateFromFile(string fileName)
{
	// 读取文件
	ifstream txtStream(fileName);
	// 存储读取的每行数据
	string line;
	// 存储元件名称
	string componentName;
	// 存储每行按空格分开的每一个数据
	double data;
	// 存储每行数据
	vector<double> lines;
	// 使用map实现对全部数据的存储
	map<string, vector<double>> dataMap;
	while (!txtStream.eof())
	{
		// getline逐行读取
		getline(txtStream, line);
		// 使用串流对string的输入输出
		stringstream stringIn(line);
		lines.clear();
		stringIn >> componentName;
		while (stringIn >> data) // 按空格分隔输出字符串
		{
			lines.push_back(data); // 存储一行字符串中按空格分开的每个数据
		}
		dataMap.insert(pair<string, vector<double>>(componentName, lines));
	}
	return dataMap;
}
void demoQtGUI::changeEnablePositionBtn()
{
	QString stringPointNumber = ui.pointNumberBox->currentText();
	int currentPointNumber;
	currentPointNumber = stringPointNumber.toInt();
	if (currentPointNumber == 4)
	{
		ui.positionPushButton5->setEnabled(false);
		ui.positionPushButton6->setEnabled(false);
		ui.positionPushButton7->setEnabled(false);
		ui.positionPushButton8->setEnabled(false);
		ui.positionPushButton9->setEnabled(false);
		ui.xyPushButton_5->setEnabled(false);
		ui.xyPushButton_6->setEnabled(false);
		ui.xyPushButton_7->setEnabled(false);
		ui.xyPushButton_8->setEnabled(false);
		ui.xyPushButton_9->setEnabled(false);
		ui.pointNumberLabel->setText(QString::fromLocal8Bit("请选择4个点计算"));
		emit sendCurrentPointNumber(currentPointNumber);
	}
	else if (currentPointNumber == 9)
	{
		ui.positionPushButton5->setEnabled(true);
		ui.positionPushButton6->setEnabled(true);
		ui.positionPushButton7->setEnabled(true);
		ui.positionPushButton8->setEnabled(true);
		ui.positionPushButton9->setEnabled(true);
		ui.xyPushButton_5->setEnabled(true);
		ui.xyPushButton_6->setEnabled(true);
		ui.xyPushButton_7->setEnabled(true);
		ui.xyPushButton_8->setEnabled(true);
		ui.xyPushButton_9->setEnabled(true);
		ui.pointNumberLabel->setText(QString::fromLocal8Bit("请选择9个点计算"));
		emit sendCurrentPointNumber(currentPointNumber);
	}
}
void demoQtGUI::on_calcAllComponentsPushButton_clicked()
{
	map<string, vector<double>> originMap;
	originMap = getCoordinateFromFile("DPPB_0915_XY.txt");
	map<string, vector<double>>::iterator iter;

	iter = originMap.find("UUNITS");
	iter = originMap.erase(iter);
	iter = originMap.begin();
	while (iter != originMap.end())
	{
		fileCoordinateX = iter->second[0];
		fileCoordinateY = iter->second[1];
		fileRotationAngle = iter->second[2];
		File2MachineCoordinate(fileCoordinateX, fileCoordinateY);
		vector<double> processedData;
		processedData.push_back(iter->second[0]);
		processedData.push_back(iter->second[1]);
		processedData.push_back(iter->second[2]);
		processedData.push_back(machineCoordinateX);
		processedData.push_back(machineCoordinateY);
		processedMap.insert(pair<string, vector<double>>(iter->first, processedData));
		iter++;
	}
	//ui.textBrowser->setText(QString::number(processedMap.size()));
	map<string, vector<double>>::iterator newIter;
	newIter = processedMap.begin();
	while (newIter != processedMap.end())
	{
		QString qs = QString::fromStdString(newIter->first);
		if (newIter->second.size() != 5)
		{
			ui.textBrowser->setText(qs + ',' + QString::number(newIter->second.size()));
		}
		newIter++;
	}
	newIter = processedMap.begin();
	ui.textBrowser->setText("Calculate all components' machine coordinate!" + QString::number(newIter->second[3]) + ',' + QString::number(newIter->second[4]));
}
void demoQtGUI::on_takeAllPicturesPushButton_clicked()
{
	map<string, vector<double>>::iterator iter;
	iter = processedMap.begin();

	//while (iter != processedMap.end())
	for (int i = 0; i < 2; i++)
	{
		QByteArray writedata;
		writedata[0] = 0xAA;
		writedata[1] = 0xAA;
		writedata[2] = 0x56;
		writedata[3] = 0x56;
		writedata[4] = 0x05;
		writedata[5] = (int)round(iter->second[3]) & 0x000000ff;
		writedata[6] = (int)round(iter->second[3]) >> 8 & 0x000000ff;
		writedata[7] = (int)round(iter->second[3]) >> 16 & 0x000000ff;
		writedata[8] = (int)round(iter->second[3]) >> 24 & 0x000000ff;
		writedata[9] = (int)round(iter->second[4]) & 0x000000ff;
		writedata[10] = (int)round(iter->second[4]) >> 8 & 0x000000ff;
		writedata[11] = (int)round(iter->second[4]) >> 16 & 0x000000ff;
		writedata[12] = (int)round(iter->second[4]) >> 24 & 0x000000ff;
		writedata[13] = 0x00;
		// 写串口
		serial->write(writedata);
		serial->waitForBytesWritten(5000);
		// 读串口
		while (serial->waitForReadyRead(5000))
		{
			readSerialData();
		}
		iter++;

		capture.open(1);
		capture.set(CAP_PROP_FRAME_WIDTH, 1280);
		capture.set(CAP_PROP_FRAME_HEIGHT, 960);
		timer->start(20);
		ui.savePhotoLabel1->setText("Camera opened! Now take a picture!");
		capture >> showimage;
		line(showimage, Point(0, 480), Point(1280, 480), Scalar(255, 255, 0), 1);
		line(showimage, Point(640, 0), Point(640, 960), Scalar(255, 255, 0), 1);
		circle(showimage, Point(640, 480), 1, Scalar(255, 255, 0));
		QImage tempImage = Mat2QImage(showimage);
		string imageName = iter->first;
		tempImage.save(QString::fromStdString(imageName), "BMP", -1);
		ui.savePhotoLabel1->setText(QString::fromStdString(imageName) + "'s picture saved sucessfully!");
		Sleep(1000);
	}
	//ui.savePhotoLabel1->setText("All components are photoed. Check them!");
}
void demoQtGUI::File2MachineCoordinate(double fileCoordinateX, double fileCoordinateY)
{
	Matrix<double, 3, 1> fileCoordinate;
	Matrix<double, 3, 1> machineCoordinate;
	Matrix<double, 3, 3> machineHomography;
	fileCoordinate <<
		fileCoordinateX,
		fileCoordinateY,
		1;
	cv2eigen(machineH, machineHomography);
	machineCoordinate = machineHomography * fileCoordinate;
	machineCoordinateX = machineCoordinate(0, 0);
	machineCoordinateY = machineCoordinate(1, 0);
}