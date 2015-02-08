#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QWidget>
#include "admin.h"
#include "usertypewindow.h"

namespace Ui {
class userLogin;
}

class userLogin : public QWidget
{
    Q_OBJECT

public:
    // Default constructor
    explicit userLogin(QWidget *parent = 0);
    // Destructor
    ~userLogin();

private slots:
    // Function triggered when login button is pressed
    void on_login_clicked();

    // Function triggered when cancel button is pressed
    void on_cancel_clicked();

private:
    Ui::userLogin *ui;
};

#endif // USERLOGIN_H
