#ifndef IROBOTUSER_H
#define IROBOTUSER_H

#include "sortedlist.h"
#include "customer.h"
#include "admin.h"
#include <QString>
#include <QMainWindow>

namespace Ui {
class iRobotUser;
}

class iRobotUser : public QMainWindow
{
    Q_OBJECT

public:
    // Default constructor
    explicit iRobotUser(QWidget *parent = 0);
    explicit iRobotUser(QWidget *parent, User* newUser);
    // Destructor
    ~iRobotUser();

private slots:
    // Function triggered when logout action is pressed
    void on_actionLog_out_triggered();

    // Function triggered when quit action is pressed
    void on_actionQuit_triggered();

    // Function triggered when requestBrochure button is pressed
    void on_requestBrochure_clicked();

    // Function triggered when printBrochure button is pressed
    void on_printBrochure_clicked();

    // Function triggered when addTestimonial button is pressed
    void on_addTestimonial_clicked();

    // Function triggered when purchase button is pressed
    void on_purchase_clicked();

    // Function triggered when contactUs button is pressed
    void on_contactus_clicked();

    // Function triggered when help action is pressed
    void on_actionUser_Guide_triggered();

    QString WordWrap(QString bigString, int lineLimit);

    void on_pushButton_clicked();

    void on_requestAccount_clicked();

private:
    Ui::iRobotUser *ui;
    User* user;
    SortedList<Customer<QString>,QString> customerList;
    SortedList<testiInfo, QString> testiList;
};

#endif // IROBOTUSER_H
