#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QWidget>

namespace Ui {
class HelpWindow;
}

class HelpWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HelpWindow(QWidget *parent = 0);
    ~HelpWindow();

private slots:
    void on_nextTextButton_clicked();

    void on_nextTextButton_2_clicked();

private:
    Ui::HelpWindow *ui;
};
//testing push

#endif // HELPWINDOW_H
