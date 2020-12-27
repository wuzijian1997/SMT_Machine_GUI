#include "demoQtGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    demoQtGUI w;
    w.show();
    return a.exec();
}
