#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QDialog>
#include "customerlistclass.h"

namespace Ui {
class SignUpWindow;
}

class SignUpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SignUpWindow(QWidget *parent = 0);
    ~SignUpWindow();

public slots:
    void on_buttonBox_accepted(Customer& customer, bool& properField);

private:
    Ui::SignUpWindow *ui;
};

#endif // SIGNUPWINDOW_H
