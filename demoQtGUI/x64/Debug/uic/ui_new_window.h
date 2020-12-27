/********************************************************************************
** Form generated from reading UI file 'new_window.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_WINDOW_H
#define UI_NEW_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_window
{
public:
    QLabel *displayPictureLabel;
    QPushButton *showImagePushButton;
    QLabel *mouseLabel;
    QLabel *imageLabel1;
    QLabel *imageLabel2;
    QLabel *imageLabel3;
    QLabel *imageLabel4;
    QPushButton *clearClickNumberPushButton;
    QLabel *pointNumLabel;
    QLabel *imageLabel5;
    QLabel *imageLabel7;
    QLabel *imageLabel6;
    QLabel *imageLabel8;
    QLabel *imageLabel9;
    QPushButton *cropPushButton;

    void setupUi(QWidget *new_window)
    {
        if (new_window->objectName().isEmpty())
            new_window->setObjectName(QStringLiteral("new_window"));
        new_window->resize(1497, 1034);
        displayPictureLabel = new QLabel(new_window);
        displayPictureLabel->setObjectName(QStringLiteral("displayPictureLabel"));
        displayPictureLabel->setGeometry(QRect(30, 30, 1280, 960));
        displayPictureLabel->setFrameShape(QFrame::Box);
        displayPictureLabel->setFrameShadow(QFrame::Plain);
        displayPictureLabel->setLineWidth(3);
        showImagePushButton = new QPushButton(new_window);
        showImagePushButton->setObjectName(QStringLiteral("showImagePushButton"));
        showImagePushButton->setGeometry(QRect(1350, 140, 93, 28));
        mouseLabel = new QLabel(new_window);
        mouseLabel->setObjectName(QStringLiteral("mouseLabel"));
        mouseLabel->setGeometry(QRect(1320, 500, 151, 21));
        mouseLabel->setFrameShape(QFrame::Box);
        mouseLabel->setFrameShadow(QFrame::Sunken);
        imageLabel1 = new QLabel(new_window);
        imageLabel1->setObjectName(QStringLiteral("imageLabel1"));
        imageLabel1->setGeometry(QRect(1340, 220, 111, 21));
        imageLabel1->setFrameShape(QFrame::Box);
        imageLabel1->setFrameShadow(QFrame::Raised);
        imageLabel2 = new QLabel(new_window);
        imageLabel2->setObjectName(QStringLiteral("imageLabel2"));
        imageLabel2->setGeometry(QRect(1340, 250, 111, 21));
        imageLabel2->setFrameShape(QFrame::Box);
        imageLabel2->setFrameShadow(QFrame::Raised);
        imageLabel3 = new QLabel(new_window);
        imageLabel3->setObjectName(QStringLiteral("imageLabel3"));
        imageLabel3->setGeometry(QRect(1340, 280, 111, 21));
        imageLabel3->setFrameShape(QFrame::Box);
        imageLabel3->setFrameShadow(QFrame::Raised);
        imageLabel4 = new QLabel(new_window);
        imageLabel4->setObjectName(QStringLiteral("imageLabel4"));
        imageLabel4->setGeometry(QRect(1340, 310, 111, 21));
        imageLabel4->setFrameShape(QFrame::Box);
        imageLabel4->setFrameShadow(QFrame::Raised);
        clearClickNumberPushButton = new QPushButton(new_window);
        clearClickNumberPushButton->setObjectName(QStringLiteral("clearClickNumberPushButton"));
        clearClickNumberPushButton->setGeometry(QRect(1340, 180, 111, 31));
        pointNumLabel = new QLabel(new_window);
        pointNumLabel->setObjectName(QStringLiteral("pointNumLabel"));
        pointNumLabel->setGeometry(QRect(1340, 100, 111, 31));
        pointNumLabel->setFrameShape(QFrame::Box);
        pointNumLabel->setFrameShadow(QFrame::Raised);
        imageLabel5 = new QLabel(new_window);
        imageLabel5->setObjectName(QStringLiteral("imageLabel5"));
        imageLabel5->setGeometry(QRect(1340, 340, 111, 21));
        imageLabel5->setFrameShape(QFrame::Box);
        imageLabel5->setFrameShadow(QFrame::Raised);
        imageLabel7 = new QLabel(new_window);
        imageLabel7->setObjectName(QStringLiteral("imageLabel7"));
        imageLabel7->setGeometry(QRect(1340, 400, 111, 21));
        imageLabel7->setFrameShape(QFrame::Box);
        imageLabel7->setFrameShadow(QFrame::Raised);
        imageLabel6 = new QLabel(new_window);
        imageLabel6->setObjectName(QStringLiteral("imageLabel6"));
        imageLabel6->setGeometry(QRect(1340, 370, 111, 21));
        imageLabel6->setFrameShape(QFrame::Box);
        imageLabel6->setFrameShadow(QFrame::Raised);
        imageLabel8 = new QLabel(new_window);
        imageLabel8->setObjectName(QStringLiteral("imageLabel8"));
        imageLabel8->setGeometry(QRect(1340, 430, 111, 21));
        imageLabel8->setFrameShape(QFrame::Box);
        imageLabel8->setFrameShadow(QFrame::Raised);
        imageLabel9 = new QLabel(new_window);
        imageLabel9->setObjectName(QStringLiteral("imageLabel9"));
        imageLabel9->setGeometry(QRect(1340, 460, 111, 21));
        imageLabel9->setFrameShape(QFrame::Box);
        imageLabel9->setFrameShadow(QFrame::Raised);
        cropPushButton = new QPushButton(new_window);
        cropPushButton->setObjectName(QStringLiteral("cropPushButton"));
        cropPushButton->setGeometry(QRect(1350, 530, 93, 28));

        retranslateUi(new_window);

        QMetaObject::connectSlotsByName(new_window);
    } // setupUi

    void retranslateUi(QWidget *new_window)
    {
        new_window->setWindowTitle(QApplication::translate("new_window", "new_window", Q_NULLPTR));
        displayPictureLabel->setText(QString());
        showImagePushButton->setText(QApplication::translate("new_window", "\346\230\276\347\244\272\345\233\276\347\211\207", Q_NULLPTR));
        mouseLabel->setText(QApplication::translate("new_window", "\345\210\232\346\211\215\351\200\211\344\270\255\347\232\204\345\233\276\345\203\217\345\235\220\346\240\207", Q_NULLPTR));
        imageLabel1->setText(QString());
        imageLabel2->setText(QString());
        imageLabel3->setText(QString());
        imageLabel4->setText(QString());
        clearClickNumberPushButton->setText(QApplication::translate("new_window", "\351\274\240\346\240\207\350\256\241\346\225\260\346\270\205\351\233\266", Q_NULLPTR));
        pointNumLabel->setText(QApplication::translate("new_window", "\350\256\241\347\256\227\346\211\200\351\234\200\347\202\271\346\225\260", Q_NULLPTR));
        imageLabel5->setText(QString());
        imageLabel7->setText(QString());
        imageLabel6->setText(QString());
        imageLabel8->setText(QString());
        imageLabel9->setText(QString());
        cropPushButton->setText(QApplication::translate("new_window", "crop", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class new_window: public Ui_new_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_WINDOW_H
