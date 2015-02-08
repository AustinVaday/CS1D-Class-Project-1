#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

signals:
    void adminChanged(bool);
    void customerChanged(bool);

private slots:
    void on_submitButton_accepted();
    void textChangedSlot(const QString &newString);

private:
    Ui::LoginWindow *ui;

};

#endif // LOGINWINDOW_H
