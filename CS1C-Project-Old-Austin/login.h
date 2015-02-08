#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QString>

#include <QDebug>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:



    explicit Login(QWidget *parent = 0);
    void on_buttonBox_loginPress_accepted(QString&, QString&);

    bool on_buttonBox_loginPress_rejected();
    ~Login();


private slots:



private:
    Ui::Login *ui;
};

#endif // LOGIN_H
