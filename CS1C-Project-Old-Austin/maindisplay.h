#ifndef MAINDISPLAY_H
#define MAINDISPLAY_H

#include <QFrame>

namespace Ui {
class MainDisplay;
}

class MainDisplay : public QFrame
{
    Q_OBJECT

public:
    explicit MainDisplay(QWidget *parent = 0);
    ~MainDisplay();

private:
    Ui::MainDisplay *ui;
};

#endif // MAINDISPLAY_H
