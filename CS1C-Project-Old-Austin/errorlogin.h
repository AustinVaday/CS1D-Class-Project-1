#ifndef ERRORLOGIN_H
#define ERRORLOGIN_H

#include <QDialog>

namespace Ui {
class ErrorLogin;
}

class ErrorLogin : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorLogin(QWidget *parent = 0);
    ~ErrorLogin();

private:
    Ui::ErrorLogin *ui;
};

#endif // ERRORLOGIN_H
