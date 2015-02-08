#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include "sortedlist.h"
#include "customer.h"
#include "admin.h"
#include <QString>
#include <QMainWindow>

namespace Ui {
class adminLogin;
}

class adminLogin : public QMainWindow
{
    Q_OBJECT

public:
    // Default constructor
    explicit adminLogin(QWidget *parent = 0);
    // Destructor
    ~adminLogin();

private slots:
    // Function triggered when login button is pressed
    void on_authLogin_clicked();

    // Function triggered when cancel button is pressed
    void on_cancelLogin_clicked();

private:
    Ui::adminLogin *ui;
    Admin* admin;
};

#endif // ADMINLOGIN_H
