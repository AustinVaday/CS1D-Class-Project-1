#ifndef CUSTOMERACCOUNTWINDOW_H
#define CUSTOMERACCOUNTWINDOW_H

#include <QWidget>

namespace Ui {
class CustomerAccountWindow;
}

class CustomerAccountWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CustomerAccountWindow(QWidget *parent = 0);
    ~CustomerAccountWindow();

private:
    Ui::CustomerAccountWindow *ui;
};

#endif // CUSTOMERACCOUNTWINDOW_H
