#include "adminlogin.h"
#include "ui_adminlogin.h"
#include "irobotadmin.h"
#include "responsewindow.h"
#include "usertypewindow.h"
#include "sortedlist.h"
#include "customer.h"
#include "admin.h"
#include <QString>
//#include "BigHead.h"

adminLogin::adminLogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminLogin)
{
    // Creates the UI
    ui->setupUi(this);
    this->setWindowTitle("Admin Login");
}

adminLogin::~adminLogin()
{
    // Destroys the UI
    delete ui;
}

void adminLogin::on_authLogin_clicked()
{
    QString username;
    QString password;
    Admin*  admin = new Admin("NAN");

    // Gets text from lineEdit object in the GUI
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();

    // Checks if the text input by the user matches the admin login credentials
    if(username == "admin" && (password == "admin" || password == "anthonysux"))
    {
        this->close();

        admin->SetName("Admin");

        // Declares new admin portal window
        irobotAdmin* adminPortal;
        adminPortal = new irobotAdmin(NULL, admin);
        // Displays window
        adminPortal->show();

        // Declares new response window
        responseWindow* response;
        response = new responseWindow(NULL, LOGIN_SUCCESSFUL);
        // Displays window
        response->show();
    }
    else
    {
        // Declares new response window
        responseWindow* response;
        response = new responseWindow(NULL, LOGIN_FAILED);
        // Displays window
        response->show();
    }
}

void adminLogin::on_cancelLogin_clicked()
{
    // Closes current window
    this->close();

    // Declares new login window
    UserTypeWindow* userWindow;
    userWindow = new UserTypeWindow();
    // Displays new window
    userWindow->show();
}
