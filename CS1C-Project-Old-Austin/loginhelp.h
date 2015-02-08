#ifndef LOGINHELP_H
#define LOGINHELP_H

#include <QDialog>

namespace Ui {
class LoginHelp;
}

class LoginHelp : public QDialog
{
    Q_OBJECT

public:
    explicit LoginHelp(QWidget *parent = 0);
    ~LoginHelp();


    void editText();

private:
    Ui::LoginHelp *ui;
};

#endif // LOGINHELP_H
