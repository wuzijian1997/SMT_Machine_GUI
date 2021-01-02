#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_demoQtGUI.h"
#include "new_window.h"

#include <QtWidgets/QMainWindow>
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QGraphicsScene>  
#include <QGraphicsView>                //graphicsview类
#include <qfiledialog.h>                //getopenfilename 类申明
#include <qlabel.h>                     //label类
#include <qtimer.h>
#include <qimage.h>
#include <QSerialPort>
#include <QSerialPortInfo>

#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>  //opencv申明
#include <opencv2\imgproc\types_c.h>

using namespace cv;
using namespace std;

class demoQtGUI : public QMainWindow
{
    Q_OBJECT

public:
    demoQtGUI(QWidget *parent = Q_NULLPTR);

private:
    Ui::demoQtGUIClass ui;
    void open();
    QTimer* timer;
    QImage* img;
    Mat showimage;
    Mat image;
    VideoCapture capture;
    QLabel* originalImageLabel1;
    QLabel* originalImageLabel2;
    QImage Mat2QImage(cv::Mat cvImg);
    map<string, vector<double>> getCoordinateFromFile(string fileName);
    void File2MachineCoordinate(double fileCoordinateX, double fileCoordinateY);
    // 定义了一个子窗口类的私有成员
    new_window* newWindow;
    // 定义了一个全局串口类对象
    QSerialPort* serial;
    // 文件中获取的物理坐标
    double fileCoordinateX;
    double fileCoordinateY;
    double fileCoordinateX1;
    double fileCoordinateY1;
    double fileCoordinateX2;
    double fileCoordinateY2;
    double fileCoordinateX3;
    double fileCoordinateY3;
    double fileCoordinateX4;
    double fileCoordinateY4;
    double fileCoordinateX5;
    double fileCoordinateY5;
    double fileCoordinateX6;
    double fileCoordinateY6;
    double fileCoordinateX7;
    double fileCoordinateY7;
    double fileCoordinateX8;
    double fileCoordinateY8;
    double fileCoordinateX9;
    double fileCoordinateY9;
    double fileRotationAngle;
    double fileRotationAngle1;
    double fileRotationAngle2;
    double fileRotationAngle3;
    double fileRotationAngle4;
    double fileRotationAngle5;
    double fileRotationAngle6;
    double fileRotationAngle7;
    double fileRotationAngle8;
    double fileRotationAngle9;
    // 通过机器坐标计算得到的单应矩阵
    Mat machineH;
    // 通过图像坐标计算得到的单应矩阵
    Mat imageH;
    // 机器坐标
    double machineCoordinateX;
    double machineCoordinateY;
    // map用于存放所有元件的文件坐标和机器坐标
    map<string, vector<double>> processedMap;
    // 读串口函数状态变量
    int readStatus;

private slots:
    void on_readFilePushButton_clicked();
    void on_displayTextPushButton_clicked();
    void on_openCameraPushButton1_clicked();
    int getFrame();
    void on_closeCameraPushButton1_clicked();
    void on_takePhotoPushButton1_clicked();
    void on_newWindowPushButton1_clicked();
    // sendSignal(QString)对应的slot
    // void showImageCoordinate(QString);
    // 从new_window接受数据,并计算H
    // void calculateHomography(vector<Point2f>);
    void calcMachineHomography(vector<Point2f>);
    void on_openSerialPushButton_clicked();
    void readSerialData();
    void on_resetPushButton_clicked();
    void on_positionPushButton1_clicked();
    void on_positionPushButton2_clicked();
    void on_positionPushButton3_clicked();
    void on_positionPushButton4_clicked();
    void on_positionPushButton5_clicked();
    void on_positionPushButton6_clicked();
    void on_positionPushButton7_clicked();
    void on_positionPushButton8_clicked();
    void on_positionPushButton9_clicked();
    void on_autoPickPushButton_clicked();
    void on_xyPushButton_1_clicked();
    void on_xyPushButton_2_clicked();
    void on_xyPushButton_3_clicked();
    void on_xyPushButton_4_clicked();
    void on_xyPushButton_5_clicked();
    void on_xyPushButton_6_clicked();
    void on_xyPushButton_7_clicked();
    void on_xyPushButton_8_clicked();
    void on_xyPushButton_9_clicked();
    void on_xyPushButton_clicked();
    void on_movePushButton_clicked();
    // 设置计算单应矩阵的点数
    void changeEnablePositionBtn();
    void on_calcAllComponentsPushButton_clicked();
    void on_takeAllPicturesPushButton_clicked();

signals:
    void sendStringCoordinate(QString); 
    void sendMachineCoordinate(vector<Point2f>);
    void sendCurrentPointNumber(int);
};
