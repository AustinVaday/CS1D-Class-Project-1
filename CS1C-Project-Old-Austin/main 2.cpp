#include "AdminWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdminWindow w;
    w.show();

    return a.exec();
}
