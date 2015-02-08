#include "usertypewindow.h"
#include "ui_usertypewindow.h"
#include "adminlogin.h"
#include "userlogin.h"
#include "irobotuser.h"
#include "customer.h"
#include "sortedList.h"
#include <QString>
#include <QFile>
#include <QMessageBox>
//#include "BigHead.h"

UserTypeWindow::UserTypeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserTypeWindow)
{
    // Creates UI
    ui->setupUi(this);
    this->setWindowTitle("iRobot - The Bomb");
}


UserTypeWindow::~UserTypeWindow()
{
    // Destroys UI
    delete ui;
}

void UserTypeWindow::on_actionQuit_triggered()
{
    // Closes current window
    this->close();
}

void UserTypeWindow::on_adminButton_clicked()
{
    // Hides current window
    this->hide();

    // Declares new admin login window
    adminLogin* loginWindow;
    loginWindow = new adminLogin(NULL);
    // Displays new window
    loginWindow->show();
}

void UserTypeWindow::on_customerButton_clicked()
{
    // Hides current window
    this->hide();

    // Declares new user login window
    userLogin* loginWindow;
    loginWindow = new userLogin(NULL);
    // Displays new window
    loginWindow->show();
}

void UserTypeWindow::on_guestButton_clicked()
{
    // Hides current window
    this->hide();

    User* user = new User("NAN");
    user->SetName("Guest");

    // Declares new user portal window
    iRobotUser* mainWindow;
    mainWindow = new iRobotUser(NULL, user);
    // Displays new window
    mainWindow->show();
}
