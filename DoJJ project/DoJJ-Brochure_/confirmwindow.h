#ifndef CONFIRMWINDOW_H
#define CONFIRMWINDOW_H

#include <QMainWindow>

enum WindowType
{
    PURCHASE_CONFIRM,
    REMOVE
};

namespace Ui {
class confirmWindow;
}

class confirmWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit confirmWindow(QWidget *parent = 0);
    explicit confirmWindow(QWidget *parent, QString inText, WindowType type);
    ~confirmWindow();

private slots:
    void on_confirm_clicked();

    void on_cancel_clicked();

private:
    Ui::confirmWindow *ui;
};

#endif // CONFIRMWINDOW_H
