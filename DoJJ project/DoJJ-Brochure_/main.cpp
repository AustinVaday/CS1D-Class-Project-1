#include "usertypewindow.h"
#include "sortedlist.h"
#include "customer.h"
#include "test.h"
#include <QApplication>
#include <QString>
#include <QFile>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Declares main window
    test w;
    // Shows window
    w.show();

    return a.exec();
}
