#pragma once

#include <QWidget>
#include "ui_new_window.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <vector>
#include <String>
#include <sstream>

using namespace std;
using namespace cv;

class new_window : public QWidget
{
	Q_OBJECT

public:
	new_window(QWidget* parent = Q_NULLPTR);
	~new_window();

private:
	Ui::new_window ui;
	int clickNumber;
	vector<Point2f> srcPoints;
	vector<Point2f> machinePoints;
	Point image2machine(float imagex, float imagey, int machinex, int machiney);
	int currentPoint;
	QImage Mat2QImage(Mat cvImg);
	Mat cropPicture;
	int cropIdentifier;
	void paintClickedPoint(QString fileName, float pointx, float pointy);

private slots:
	void on_showImagePushButton_clicked();
	void on_clearClickNumberPushButton_clicked();
	void recvCurrentPointNumber(int);
	void on_cropPushButton_clicked();

signals:
	void sendMachineCoordinate(vector<Point2f>);

protected:
	void mousePressEvent(QMouseEvent* event);
};
