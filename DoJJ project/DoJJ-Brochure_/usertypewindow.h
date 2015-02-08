#ifndef USERTYPEWINDOW_H
#define USERTYPEWINDOW_H

#include "customer.h"
#include "sortedlist.h"
#include <QString>
#include <QMainWindow>

namespace Ui {
class UserTypeWindow;
}

class UserTypeWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Default constructor
    explicit UserTypeWindow(QWidget *parent = 0);
    // Destructor
    ~UserTypeWindow();

private slots:
    // Function triggered when the user goes to File->Quit
    void on_actionQuit_triggered();

    // Function triggered when admin login button is pressed
    void on_adminButton_clicked();

    // Function triggered when returning user login button is pressed
    void on_customerButton_clicked();

    // Function triggered when guest login button is pressed
    void on_guestButton_clicked();

private:
    Ui::UserTypeWindow *ui;

};

#endif // USERTYPEWINDOW_H
