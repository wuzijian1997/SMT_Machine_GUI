/********************************************************************************
** Form generated from reading UI file 'demoQtGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMOQTGUI_H
#define UI_DEMOQTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_demoQtGUIClass
{
public:
    QWidget *centralWidget;
    QLineEdit *componentLineEdit_1;
    QLabel *componentLabel_1;
    QLabel *componentLabel_2;
    QLineEdit *componentLineEdit_2;
    QLabel *componentLabel_3;
    QLineEdit *componentLineEdit_3;
    QLabel *componentLabel_4;
    QLineEdit *componentLineEdit_4;
    QLabel *calculateLabel;
    QLabel *componentLabel;
    QPushButton *xyPushButton_1;
    QPushButton *xyPushButton_2;
    QPushButton *xyPushButton_3;
    QPushButton *xyPushButton_4;
    QLineEdit *componentLineEdit;
    QLabel *xyLabel;
    QPushButton *xyPushButton;
    QPushButton *movePushButton;
    QLabel *imageLabel;
    QLabel *readFileLabel;
    QLineEdit *readFileLineEdit;
    QPushButton *readFilePushButton;
    QLabel *rowNumLabel;
    QTextBrowser *textBrowser;
    QPushButton *displayTextPushButton;
    QLabel *originalImageLabel1;
    QLabel *originalImageLabel2;
    QLabel *cameraLabel1;
    QLabel *cameraLabel2;
    QPushButton *openCameraPushButton1;
    QPushButton *closeCameraPushButton1;
    QPushButton *takePhotoPushButton1;
    QPushButton *newWindowPushButton1;
    QLabel *textRowNumberLabel;
    QLabel *machineCoordinateLabel;
    QPushButton *newWindowPushButton2;
    QPushButton *openCameraPushButton2;
    QPushButton *closeCameraPushButton2;
    QPushButton *takePhotoPushButton2;
    QPushButton *positionPushButton1;
    QPushButton *positionPushButton2;
    QPushButton *positionPushButton3;
    QPushButton *positionPushButton4;
    QPushButton *openSerialPushButton;
    QComboBox *portBox;
    QTextBrowser *serialOutputTextBrowser;
    QPushButton *resetPushButton;
    QPushButton *autoPickPushButton;
    QLabel *fileCoordinateLabel1;
    QLabel *fileCoordinateLabel2;
    QLabel *fileCoordinateLabel3;
    QLabel *fileCoordinateLabel4;
    QLabel *fileCoordinateLabel;
    QLabel *homographyLabel;
    QLabel *componentLabel_8;
    QLineEdit *componentLineEdit_9;
    QPushButton *xyPushButton_9;
    QLineEdit *componentLineEdit_7;
    QLabel *fileCoordinateLabel7;
    QLabel *componentLabel_9;
    QPushButton *xyPushButton_7;
    QPushButton *xyPushButton_6;
    QPushButton *xyPushButton_8;
    QLineEdit *componentLineEdit_6;
    QLabel *componentLabel_7;
    QLineEdit *componentLineEdit_8;
    QLabel *fileCoordinateLabel6;
    QLabel *fileCoordinateLabel8;
    QLabel *componentLabel_6;
    QLabel *fileCoordinateLabel9;
    QLineEdit *componentLineEdit_5;
    QLabel *componentLabel_5;
    QPushButton *xyPushButton_5;
    QLabel *fileCoordinateLabel5;
    QPushButton *positionPushButton5;
    QPushButton *positionPushButton6;
    QPushButton *positionPushButton7;
    QPushButton *positionPushButton8;
    QPushButton *positionPushButton9;
    QLabel *savePhotoLabel1;
    QLabel *savePhotoLabel2;
    QComboBox *pointNumberBox;
    QLabel *pointNumberLabel;
    QPushButton *calcAllComponentsPushButton;
    QPushButton *takeAllPicturesPushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *demoQtGUIClass)
    {
        if (demoQtGUIClass->objectName().isEmpty())
            demoQtGUIClass->setObjectName(QStringLiteral("demoQtGUIClass"));
        demoQtGUIClass->setWindowModality(Qt::WindowModal);
        demoQtGUIClass->resize(1306, 846);
        demoQtGUIClass->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        centralWidget = new QWidget(demoQtGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        componentLineEdit_1 = new QLineEdit(centralWidget);
        componentLineEdit_1->setObjectName(QStringLiteral("componentLineEdit_1"));
        componentLineEdit_1->setGeometry(QRect(80, 180, 51, 21));
        componentLabel_1 = new QLabel(centralWidget);
        componentLabel_1->setObjectName(QStringLiteral("componentLabel_1"));
        componentLabel_1->setGeometry(QRect(30, 180, 72, 15));
        componentLabel_2 = new QLabel(centralWidget);
        componentLabel_2->setObjectName(QStringLiteral("componentLabel_2"));
        componentLabel_2->setGeometry(QRect(30, 220, 72, 15));
        componentLineEdit_2 = new QLineEdit(centralWidget);
        componentLineEdit_2->setObjectName(QStringLiteral("componentLineEdit_2"));
        componentLineEdit_2->setGeometry(QRect(80, 220, 51, 21));
        componentLabel_3 = new QLabel(centralWidget);
        componentLabel_3->setObjectName(QStringLiteral("componentLabel_3"));
        componentLabel_3->setGeometry(QRect(30, 260, 72, 15));
        componentLineEdit_3 = new QLineEdit(centralWidget);
        componentLineEdit_3->setObjectName(QStringLiteral("componentLineEdit_3"));
        componentLineEdit_3->setGeometry(QRect(80, 260, 51, 21));
        componentLabel_4 = new QLabel(centralWidget);
        componentLabel_4->setObjectName(QStringLiteral("componentLabel_4"));
        componentLabel_4->setGeometry(QRect(30, 300, 72, 15));
        componentLineEdit_4 = new QLineEdit(centralWidget);
        componentLineEdit_4->setObjectName(QStringLiteral("componentLineEdit_4"));
        componentLineEdit_4->setGeometry(QRect(80, 300, 51, 21));
        calculateLabel = new QLabel(centralWidget);
        calculateLabel->setObjectName(QStringLiteral("calculateLabel"));
        calculateLabel->setGeometry(QRect(30, 440, 101, 16));
        componentLabel = new QLabel(centralWidget);
        componentLabel->setObjectName(QStringLiteral("componentLabel"));
        componentLabel->setGeometry(QRect(140, 440, 72, 15));
        xyPushButton_1 = new QPushButton(centralWidget);
        xyPushButton_1->setObjectName(QStringLiteral("xyPushButton_1"));
        xyPushButton_1->setGeometry(QRect(250, 180, 93, 28));
        xyPushButton_2 = new QPushButton(centralWidget);
        xyPushButton_2->setObjectName(QStringLiteral("xyPushButton_2"));
        xyPushButton_2->setGeometry(QRect(250, 220, 93, 28));
        xyPushButton_3 = new QPushButton(centralWidget);
        xyPushButton_3->setObjectName(QStringLiteral("xyPushButton_3"));
        xyPushButton_3->setGeometry(QRect(250, 260, 93, 28));
        xyPushButton_4 = new QPushButton(centralWidget);
        xyPushButton_4->setObjectName(QStringLiteral("xyPushButton_4"));
        xyPushButton_4->setGeometry(QRect(250, 300, 93, 28));
        componentLineEdit = new QLineEdit(centralWidget);
        componentLineEdit->setObjectName(QStringLiteral("componentLineEdit"));
        componentLineEdit->setGeometry(QRect(190, 435, 41, 21));
        xyLabel = new QLabel(centralWidget);
        xyLabel->setObjectName(QStringLiteral("xyLabel"));
        xyLabel->setGeometry(QRect(30, 470, 72, 15));
        xyPushButton = new QPushButton(centralWidget);
        xyPushButton->setObjectName(QStringLiteral("xyPushButton"));
        xyPushButton->setGeometry(QRect(250, 430, 93, 28));
        movePushButton = new QPushButton(centralWidget);
        movePushButton->setObjectName(QStringLiteral("movePushButton"));
        movePushButton->setGeometry(QRect(350, 430, 93, 28));
        imageLabel = new QLabel(centralWidget);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setGeometry(QRect(340, 470, 72, 15));
        readFileLabel = new QLabel(centralWidget);
        readFileLabel->setObjectName(QStringLiteral("readFileLabel"));
        readFileLabel->setGeometry(QRect(30, 510, 61, 16));
        readFileLineEdit = new QLineEdit(centralWidget);
        readFileLineEdit->setObjectName(QStringLiteral("readFileLineEdit"));
        readFileLineEdit->setGeometry(QRect(100, 510, 311, 21));
        readFilePushButton = new QPushButton(centralWidget);
        readFilePushButton->setObjectName(QStringLiteral("readFilePushButton"));
        readFilePushButton->setGeometry(QRect(560, 500, 93, 28));
        rowNumLabel = new QLabel(centralWidget);
        rowNumLabel->setObjectName(QStringLiteral("rowNumLabel"));
        rowNumLabel->setGeometry(QRect(490, 500, 51, 31));
        rowNumLabel->setFrameShape(QFrame::Box);
        rowNumLabel->setFrameShadow(QFrame::Raised);
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(30, 540, 621, 71));
        textBrowser->setFrameShadow(QFrame::Raised);
        displayTextPushButton = new QPushButton(centralWidget);
        displayTextPushButton->setObjectName(QStringLiteral("displayTextPushButton"));
        displayTextPushButton->setGeometry(QRect(30, 620, 93, 28));
        originalImageLabel1 = new QLabel(centralWidget);
        originalImageLabel1->setObjectName(QStringLiteral("originalImageLabel1"));
        originalImageLabel1->setGeometry(QRect(690, 30, 571, 311));
        originalImageLabel1->setContextMenuPolicy(Qt::NoContextMenu);
        originalImageLabel1->setFrameShape(QFrame::Box);
        originalImageLabel1->setFrameShadow(QFrame::Plain);
        originalImageLabel2 = new QLabel(centralWidget);
        originalImageLabel2->setObjectName(QStringLiteral("originalImageLabel2"));
        originalImageLabel2->setGeometry(QRect(690, 410, 571, 301));
        originalImageLabel2->setFrameShape(QFrame::Box);
        cameraLabel1 = new QLabel(centralWidget);
        cameraLabel1->setObjectName(QStringLiteral("cameraLabel1"));
        cameraLabel1->setGeometry(QRect(690, 10, 72, 15));
        cameraLabel2 = new QLabel(centralWidget);
        cameraLabel2->setObjectName(QStringLiteral("cameraLabel2"));
        cameraLabel2->setGeometry(QRect(690, 390, 72, 15));
        openCameraPushButton1 = new QPushButton(centralWidget);
        openCameraPushButton1->setObjectName(QStringLiteral("openCameraPushButton1"));
        openCameraPushButton1->setGeometry(QRect(690, 350, 81, 28));
        closeCameraPushButton1 = new QPushButton(centralWidget);
        closeCameraPushButton1->setObjectName(QStringLiteral("closeCameraPushButton1"));
        closeCameraPushButton1->setGeometry(QRect(980, 350, 81, 28));
        takePhotoPushButton1 = new QPushButton(centralWidget);
        takePhotoPushButton1->setObjectName(QStringLiteral("takePhotoPushButton1"));
        takePhotoPushButton1->setGeometry(QRect(790, 350, 51, 28));
        newWindowPushButton1 = new QPushButton(centralWidget);
        newWindowPushButton1->setObjectName(QStringLiteral("newWindowPushButton1"));
        newWindowPushButton1->setGeometry(QRect(860, 350, 111, 28));
        textRowNumberLabel = new QLabel(centralWidget);
        textRowNumberLabel->setObjectName(QStringLiteral("textRowNumberLabel"));
        textRowNumberLabel->setGeometry(QRect(420, 510, 72, 15));
        machineCoordinateLabel = new QLabel(centralWidget);
        machineCoordinateLabel->setObjectName(QStringLiteral("machineCoordinateLabel"));
        machineCoordinateLabel->setGeometry(QRect(410, 470, 241, 21));
        machineCoordinateLabel->setFrameShape(QFrame::Box);
        machineCoordinateLabel->setFrameShadow(QFrame::Raised);
        newWindowPushButton2 = new QPushButton(centralWidget);
        newWindowPushButton2->setObjectName(QStringLiteral("newWindowPushButton2"));
        newWindowPushButton2->setGeometry(QRect(860, 720, 121, 28));
        openCameraPushButton2 = new QPushButton(centralWidget);
        openCameraPushButton2->setObjectName(QStringLiteral("openCameraPushButton2"));
        openCameraPushButton2->setGeometry(QRect(690, 720, 93, 28));
        closeCameraPushButton2 = new QPushButton(centralWidget);
        closeCameraPushButton2->setObjectName(QStringLiteral("closeCameraPushButton2"));
        closeCameraPushButton2->setGeometry(QRect(990, 720, 93, 28));
        takePhotoPushButton2 = new QPushButton(centralWidget);
        takePhotoPushButton2->setObjectName(QStringLiteral("takePhotoPushButton2"));
        takePhotoPushButton2->setGeometry(QRect(790, 720, 51, 28));
        positionPushButton1 = new QPushButton(centralWidget);
        positionPushButton1->setObjectName(QStringLiteral("positionPushButton1"));
        positionPushButton1->setGeometry(QRect(30, 50, 93, 28));
        positionPushButton2 = new QPushButton(centralWidget);
        positionPushButton2->setObjectName(QStringLiteral("positionPushButton2"));
        positionPushButton2->setGeometry(QRect(140, 50, 93, 28));
        positionPushButton3 = new QPushButton(centralWidget);
        positionPushButton3->setObjectName(QStringLiteral("positionPushButton3"));
        positionPushButton3->setGeometry(QRect(250, 50, 93, 28));
        positionPushButton4 = new QPushButton(centralWidget);
        positionPushButton4->setObjectName(QStringLiteral("positionPushButton4"));
        positionPushButton4->setGeometry(QRect(350, 50, 93, 28));
        openSerialPushButton = new QPushButton(centralWidget);
        openSerialPushButton->setObjectName(QStringLiteral("openSerialPushButton"));
        openSerialPushButton->setGeometry(QRect(30, 10, 93, 28));
        portBox = new QComboBox(centralWidget);
        portBox->setObjectName(QStringLiteral("portBox"));
        portBox->setGeometry(QRect(140, 10, 87, 31));
        serialOutputTextBrowser = new QTextBrowser(centralWidget);
        serialOutputTextBrowser->setObjectName(QStringLiteral("serialOutputTextBrowser"));
        serialOutputTextBrowser->setGeometry(QRect(30, 120, 631, 51));
        resetPushButton = new QPushButton(centralWidget);
        resetPushButton->setObjectName(QStringLiteral("resetPushButton"));
        resetPushButton->setGeometry(QRect(250, 10, 93, 28));
        autoPickPushButton = new QPushButton(centralWidget);
        autoPickPushButton->setObjectName(QStringLiteral("autoPickPushButton"));
        autoPickPushButton->setGeometry(QRect(350, 10, 93, 28));
        fileCoordinateLabel1 = new QLabel(centralWidget);
        fileCoordinateLabel1->setObjectName(QStringLiteral("fileCoordinateLabel1"));
        fileCoordinateLabel1->setGeometry(QRect(140, 180, 101, 21));
        fileCoordinateLabel1->setFrameShape(QFrame::Box);
        fileCoordinateLabel1->setFrameShadow(QFrame::Raised);
        fileCoordinateLabel2 = new QLabel(centralWidget);
        fileCoordinateLabel2->setObjectName(QStringLiteral("fileCoordinateLabel2"));
        fileCoordinateLabel2->setGeometry(QRect(140, 220, 101, 21));
        fileCoordinateLabel2->setFrameShape(QFrame::Box);
        fileCoordinateLabel2->setFrameShadow(QFrame::Raised);
        fileCoordinateLabel3 = new QLabel(centralWidget);
        fileCoordinateLabel3->setObjectName(QStringLiteral("fileCoordinateLabel3"));
        fileCoordinateLabel3->setGeometry(QRect(140, 260, 101, 21));
        fileCoordinateLabel3->setFrameShape(QFrame::Box);
        fileCoordinateLabel3->setFrameShadow(QFrame::Raised);
        fileCoordinateLabel4 = new QLabel(centralWidget);
        fileCoordinateLabel4->setObjectName(QStringLiteral("fileCoordinateLabel4"));
        fileCoordinateLabel4->setGeometry(QRect(140, 300, 101, 21));
        fileCoordinateLabel4->setFrameShape(QFrame::Box);
        fileCoordinateLabel4->setFrameShadow(QFrame::Raised);
        fileCoordinateLabel = new QLabel(centralWidget);
        fileCoordinateLabel->setObjectName(QStringLiteral("fileCoordinateLabel"));
        fileCoordinateLabel->setGeometry(QRect(100, 470, 221, 21));
        fileCoordinateLabel->setFrameShape(QFrame::Box);
        fileCoordinateLabel->setFrameShadow(QFrame::Raised);
        homographyLabel = new QLabel(centralWidget);
        homographyLabel->setObjectName(QStringLiteral("homographyLabel"));
        homographyLabel->setGeometry(QRect(350, 340, 311, 31));
        homographyLabel->setFrameShape(QFrame::Box);
        homographyLabel->setFrameShadow(QFrame::Raised);
        componentLabel_8 = new QLabel(centralWidget);
        componentLabel_8->setObjectName(QStringLiteral("componentLabel_8"));
        componentLabel_8->setGeometry(QRect(350, 260, 72, 15));
        componentLineEdit_9 = new QLineEdit(centralWidget);
        componentLineEdit_9->setObjectName(QStringLiteral("componentLineEdit_9"));
        componentLineEdit_9->setGeometry(QRect(400, 300, 51, 21));
        xyPushButton_9 = new QPushButton(centralWidget);
        xyPushButton_9->setObjectName(QStringLiteral("xyPushButton_9"));
        xyPushButton_9->setGeometry(QRect(570, 300, 93, 28));
        componentLineEdit_7 = new QLineEdit(centralWidget);
        componentLineEdit_7->setObjectName(QStringLiteral("componentLineEdit_7"));
        componentLineEdit_7->setGeometry(QRect(400, 220, 51, 21));
        fileCoordinateLabel7 = new QLabel(centralWidget);
        fileCoordinateLabel7->setObjectName(QStringLiteral("fileCoordinateLabel7"));
        fileCoordinateLabel7->setGeometry(QRect(460, 220, 101, 21));
        fileCoordinateLabel7->setFrameShape(QFrame::Box);
        fileCoordinateLabel7->setFrameShadow(QFrame::Raised);
        componentLabel_9 = new QLabel(centralWidget);
        componentLabel_9->setObjectName(QStringLiteral("componentLabel_9"));
        componentLabel_9->setGeometry(QRect(350, 300, 72, 15));
        xyPushButton_7 = new QPushButton(centralWidget);
        xyPushButton_7->setObjectName(QStringLiteral("xyPushButton_7"));
        xyPushButton_7->setGeometry(QRect(570, 220, 93, 28));
        xyPushButton_6 = new QPushButton(centralWidget);
        xyPushButton_6->setObjectName(QStringLiteral("xyPushButton_6"));
        xyPushButton_6->setGeometry(QRect(570, 180, 93, 28));
        xyPushButton_8 = new QPushButton(centralWidget);
        xyPushButton_8->setObjectName(QStringLiteral("xyPushButton_8"));
        xyPushButton_8->setGeometry(QRect(570, 260, 93, 28));
        componentLineEdit_6 = new QLineEdit(centralWidget);
        componentLineEdit_6->setObjectName(QStringLiteral("componentLineEdit_6"));
        componentLineEdit_6->setGeometry(QRect(400, 180, 51, 21));
        componentLabel_7 = new QLabel(centralWidget);
        componentLabel_7->setObjectName(QStringLiteral("componentLabel_7"));
        componentLabel_7->setGeometry(QRect(350, 220, 72, 15));
        componentLineEdit_8 = new QLineEdit(centralWidget);
        componentLineEdit_8->setObjectName(QStringLiteral("componentLineEdit_8"));
        componentLineEdit_8->setGeometry(QRect(400, 260, 51, 21));
        fileCoordinateLabel6 = new QLabel(centralWidget);
        fileCoordinateLabel6->setObjectName(QStringLiteral("fileCoordinateLabel6"));
        fileCoordinateLabel6->setGeometry(QRect(460, 180, 101, 21));
        fileCoordinateLabel6->setFrameShape(QFrame::Box);
        fileCoordinateLabel6->setFrameShadow(QFrame::Raised);
        fileCoordinateLabel8 = new QLabel(centralWidget);
        fileCoordinateLabel8->setObjectName(QStringLiteral("fileCoordinateLabel8"));
        fileCoordinateLabel8->setGeometry(QRect(460, 260, 101, 21));
        fileCoordinateLabel8->setFrameShape(QFrame::Box);
        fileCoordinateLabel8->setFrameShadow(QFrame::Raised);
        componentLabel_6 = new QLabel(centralWidget);
        componentLabel_6->setObjectName(QStringLiteral("componentLabel_6"));
        componentLabel_6->setGeometry(QRect(350, 180, 72, 15));
        fileCoordinateLabel9 = new QLabel(centralWidget);
        fileCoordinateLabel9->setObjectName(QStringLiteral("fileCoordinateLabel9"));
        fileCoordinateLabel9->setGeometry(QRect(460, 300, 101, 21));
        fileCoordinateLabel9->setFrameShape(QFrame::Box);
        fileCoordinateLabel9->setFrameShadow(QFrame::Raised);
        componentLineEdit_5 = new QLineEdit(centralWidget);
        componentLineEdit_5->setObjectName(QStringLiteral("componentLineEdit_5"));
        componentLineEdit_5->setGeometry(QRect(80, 340, 51, 21));
        componentLabel_5 = new QLabel(centralWidget);
        componentLabel_5->setObjectName(QStringLiteral("componentLabel_5"));
        componentLabel_5->setGeometry(QRect(30, 340, 72, 15));
        xyPushButton_5 = new QPushButton(centralWidget);
        xyPushButton_5->setObjectName(QStringLiteral("xyPushButton_5"));
        xyPushButton_5->setGeometry(QRect(250, 340, 93, 28));
        fileCoordinateLabel5 = new QLabel(centralWidget);
        fileCoordinateLabel5->setObjectName(QStringLiteral("fileCoordinateLabel5"));
        fileCoordinateLabel5->setGeometry(QRect(140, 340, 101, 21));
        fileCoordinateLabel5->setFrameShape(QFrame::Box);
        fileCoordinateLabel5->setFrameShadow(QFrame::Raised);
        positionPushButton5 = new QPushButton(centralWidget);
        positionPushButton5->setObjectName(QStringLiteral("positionPushButton5"));
        positionPushButton5->setGeometry(QRect(460, 50, 93, 28));
        positionPushButton6 = new QPushButton(centralWidget);
        positionPushButton6->setObjectName(QStringLiteral("positionPushButton6"));
        positionPushButton6->setGeometry(QRect(560, 50, 93, 28));
        positionPushButton7 = new QPushButton(centralWidget);
        positionPushButton7->setObjectName(QStringLiteral("positionPushButton7"));
        positionPushButton7->setGeometry(QRect(30, 90, 93, 28));
        positionPushButton8 = new QPushButton(centralWidget);
        positionPushButton8->setObjectName(QStringLiteral("positionPushButton8"));
        positionPushButton8->setGeometry(QRect(140, 90, 93, 28));
        positionPushButton9 = new QPushButton(centralWidget);
        positionPushButton9->setObjectName(QStringLiteral("positionPushButton9"));
        positionPushButton9->setGeometry(QRect(250, 90, 93, 28));
        savePhotoLabel1 = new QLabel(centralWidget);
        savePhotoLabel1->setObjectName(QStringLiteral("savePhotoLabel1"));
        savePhotoLabel1->setGeometry(QRect(740, 10, 521, 16));
        savePhotoLabel2 = new QLabel(centralWidget);
        savePhotoLabel2->setObjectName(QStringLiteral("savePhotoLabel2"));
        savePhotoLabel2->setGeometry(QRect(750, 390, 521, 16));
        pointNumberBox = new QComboBox(centralWidget);
        pointNumberBox->setObjectName(QStringLiteral("pointNumberBox"));
        pointNumberBox->setGeometry(QRect(620, 10, 31, 31));
        pointNumberLabel = new QLabel(centralWidget);
        pointNumberLabel->setObjectName(QStringLiteral("pointNumberLabel"));
        pointNumberLabel->setGeometry(QRect(460, 20, 151, 21));
        calcAllComponentsPushButton = new QPushButton(centralWidget);
        calcAllComponentsPushButton->setObjectName(QStringLiteral("calcAllComponentsPushButton"));
        calcAllComponentsPushButton->setGeometry(QRect(450, 430, 93, 28));
        takeAllPicturesPushButton = new QPushButton(centralWidget);
        takeAllPicturesPushButton->setObjectName(QStringLiteral("takeAllPicturesPushButton"));
        takeAllPicturesPushButton->setGeometry(QRect(550, 430, 93, 28));
        demoQtGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(demoQtGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1306, 26));
        demoQtGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(demoQtGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        demoQtGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(demoQtGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        demoQtGUIClass->setStatusBar(statusBar);

        retranslateUi(demoQtGUIClass);

        QMetaObject::connectSlotsByName(demoQtGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *demoQtGUIClass)
    {
        demoQtGUIClass->setWindowTitle(QApplication::translate("demoQtGUIClass", "demoQtGUI", Q_NULLPTR));
        componentLabel_1->setText(QApplication::translate("demoQtGUIClass", "\345\205\203\344\273\2661", Q_NULLPTR));
        componentLabel_2->setText(QApplication::translate("demoQtGUIClass", "\345\205\203\344\273\2662", Q_NULLPTR));
        componentLabel_3->setText(QApplication::translate("demoQtGUIClass", "\345\205\203\344\273\2663", Q_NULLPTR));
        componentLabel_4->setText(QApplication::translate("demoQtGUIClass", "\345\205\203\344\273\2664", Q_NULLPTR));
        calculateLabel->setText(QApplication::translate("demoQtGUIClass", "\345\205\266\344\273\226\345\205\203\344\273\266\345\235\220\346\240\207\357\274\232", Q_NULLPTR));
        componentLabel->setText(QApplication::translate("demoQtGUIClass", "\345\205\203\344\273\266\345\217\267", Q_NULLPTR));
        xyPushButton_1->setText(QApplication::translate("demoQtGUIClass", "\347\211\251\347\220\206\345\235\220\346\240\207", Q_NULLPTR));
        xyPushButton_2->setText(QApplication::translate("demoQtGUIClass", "\347\211\251\347\220\206\345\235\220\346\240\207", Q_NULLPTR));
        xyPushButton_3->setText(QApplication::translate("demoQtGUIClass", "\347\211\251\347\220\206\345\235\220\346\240\207", Q_NULLPTR));
        xyPushButton_4->setText(QApplication::translate("demoQtGUIClass", "\347\211\251\347\220\206\345\235\220\346\240\207", Q_NULLPTR));
        xyLabel->setText(QApplication::translate("demoQtGUIClass", "\347\211\251\347\220\206\345\235\220\346\240\207", Q_NULLPTR));
        xyPushButton->setText(QApplication::translate("demoQtGUIClass", "\346\237\245\347\234\213\345\235\220\346\240\207", Q_NULLPTR));
        movePushButton->setText(QApplication::translate("demoQtGUIClass", "\347\247\273\345\212\250", Q_NULLPTR));
        imageLabel->setText(QApplication::translate("demoQtGUIClass", "\346\234\272\345\231\250\345\235\220\346\240\207", Q_NULLPTR));
        readFileLabel->setText(QApplication::translate("demoQtGUIClass", "\350\257\273\345\217\226\346\226\207\344\273\266", Q_NULLPTR));
        readFilePushButton->setText(QApplication::translate("demoQtGUIClass", "\350\257\273\345\217\226\346\226\207\344\273\266", Q_NULLPTR));
        rowNumLabel->setText(QString());
        displayTextPushButton->setText(QApplication::translate("demoQtGUIClass", "\345\261\225\347\244\272\346\226\207\346\234\254", Q_NULLPTR));
        originalImageLabel1->setText(QString());
        originalImageLabel2->setText(QString());
        cameraLabel1->setText(QApplication::translate("demoQtGUIClass", "\347\233\270\346\234\2721", Q_NULLPTR));
        cameraLabel2->setText(QApplication::translate("demoQtGUIClass", "\347\233\270\346\234\2722", Q_NULLPTR));
        openCameraPushButton1->setText(QApplication::translate("demoQtGUIClass", "\346\211\223\345\274\200\347\233\270\346\234\2721", Q_NULLPTR));
        closeCameraPushButton1->setText(QApplication::translate("demoQtGUIClass", "\345\205\263\351\227\255\347\233\270\346\234\2721", Q_NULLPTR));
        takePhotoPushButton1->setText(QApplication::translate("demoQtGUIClass", "\346\213\215\347\205\2471", Q_NULLPTR));
        newWindowPushButton1->setText(QApplication::translate("demoQtGUIClass", "\346\211\223\345\274\200\347\233\270\346\234\2721\345\233\276\345\203\217", Q_NULLPTR));
        textRowNumberLabel->setText(QApplication::translate("demoQtGUIClass", "\346\226\207\344\273\266\350\241\214\346\225\260", Q_NULLPTR));
        machineCoordinateLabel->setText(QString());
        newWindowPushButton2->setText(QApplication::translate("demoQtGUIClass", "\346\211\223\345\274\200\347\233\270\346\234\2722\345\233\276\345\203\217", Q_NULLPTR));
        openCameraPushButton2->setText(QApplication::translate("demoQtGUIClass", "\346\211\223\345\274\200\347\233\270\346\234\2722", Q_NULLPTR));
        closeCameraPushButton2->setText(QApplication::translate("demoQtGUIClass", "\345\205\263\351\227\255\347\233\270\346\234\2722", Q_NULLPTR));
        takePhotoPushButton2->setText(QApplication::translate("demoQtGUIClass", "\346\213\215\347\205\2472", Q_NULLPTR));
        positionPushButton1->setText(QApplication::translate("demoQtGUIClass", "\344\275\215\347\275\2561", Q_NULLPTR));
        positionPushButton2->setText(QApplication::translate("demoQtGUIClass", "\344\275\215\347\275\2562", Q_NULLPTR));
        positionPushButton3->setText(QApplication::translate("demoQtGUIClass", "\344\275\215\347\275\2563", Q_NULLPTR));
        positionPushButton4->setText(QApplication::translate("demoQtGUIClass", "\344\275\215\347\275\2564", Q_NULLPTR));
        openSerialPushButton->setText(QApplication::translate("demoQtGUIClass", "Open Port", Q_NULLPTR));
        resetPushButton->setText(QApplication::translate("demoQtGUIClass", "\345\244\215\344\275\215", Q_NULLPTR));
        autoPickPushButton->setText(QApplication::translate("demoQtGUIClass", "\350\207\252\345\212\250\346\213\276\345\217\226", Q_NULLPTR));
        fileCoordinateLabel1->setText(QString());
        fileCoordinateLabel2->setText(QString());
        fileCoordinateLabel3->setText(QString());
        fileCoordinateLabel4->setText(QString());
        fileCoordinateLabel->setText(QString());
        homographyLabel->setText(QApplication::translate("demoQtGUIClass", "Homography", Q_NULLPTR));
        componentLabel_8->setText(QApplication::translate("demoQtGUIClass", "\345\205\203\344\273\2668", Q_NULLPTR));
        xyPushButton_9->setText(QApplication::translate("demoQtGUIClass", "\347\211\251\347\220\206\345\235\220\346\240\207", Q_NULLPTR));
        fileCoordinateLabel7->setText(QString());
        componentLabel_9->setText(QApplication::translate("demoQtGUIClass", "\345\205\203\344\273\2669", Q_NULLPTR));
        xyPushButton_7->setText(QApplication::translate("demoQtGUIClass", "\347\211\251\347\220\206\345\235\220\346\240\207", Q_NULLPTR));
        xyPushButton_6->setText(QApplication::translate("demoQtGUIClass", "\347\211\251\347\220\206\345\235\220\346\240\207", Q_NULLPTR));
        xyPushButton_8->setText(QApplication::translate("demoQtGUIClass", "\347\211\251\347\220\206\345\235\220\346\240\207", Q_NULLPTR));
        componentLabel_7->setText(QApplication::translate("demoQtGUIClass", "\345\205\203\344\273\2667", Q_NULLPTR));
        fileCoordinateLabel6->setText(QString());
        fileCoordinateLabel8->setText(QString());
        componentLabel_6->setText(QApplication::translate("demoQtGUIClass", "\345\205\203\344\273\2666", Q_NULLPTR));
        fileCoordinateLabel9->setText(QString());
        componentLabel_5->setText(QApplication::translate("demoQtGUIClass", "\345\205\203\344\273\2665", Q_NULLPTR));
        xyPushButton_5->setText(QApplication::translate("demoQtGUIClass", "\347\211\251\347\220\206\345\235\220\346\240\207", Q_NULLPTR));
        fileCoordinateLabel5->setText(QString());
        positionPushButton5->setText(QApplication::translate("demoQtGUIClass", "\344\275\215\347\275\2565", Q_NULLPTR));
        positionPushButton6->setText(QApplication::translate("demoQtGUIClass", "\344\275\215\347\275\2566", Q_NULLPTR));
        positionPushButton7->setText(QApplication::translate("demoQtGUIClass", "\344\275\215\347\275\2567", Q_NULLPTR));
        positionPushButton8->setText(QApplication::translate("demoQtGUIClass", "\344\275\215\347\275\2568", Q_NULLPTR));
        positionPushButton9->setText(QApplication::translate("demoQtGUIClass", "\344\275\215\347\275\2569", Q_NULLPTR));
        savePhotoLabel1->setText(QString());
        savePhotoLabel2->setText(QString());
        pointNumberBox->clear();
        pointNumberBox->insertItems(0, QStringList()
         << QApplication::translate("demoQtGUIClass", "9", Q_NULLPTR)
         << QApplication::translate("demoQtGUIClass", "4", Q_NULLPTR)
        );
        pointNumberLabel->setText(QApplication::translate("demoQtGUIClass", "\350\256\241\347\256\227\345\215\225\345\272\224\347\237\251\351\230\265\346\211\200\351\234\200\347\202\271\346\225\260", Q_NULLPTR));
        calcAllComponentsPushButton->setText(QApplication::translate("demoQtGUIClass", "\345\205\250\351\203\250\350\256\241\347\256\227", Q_NULLPTR));
        takeAllPicturesPushButton->setText(QApplication::translate("demoQtGUIClass", "\345\205\250\351\203\250\346\213\215\347\205\247", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class demoQtGUIClass: public Ui_demoQtGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMOQTGUI_H
