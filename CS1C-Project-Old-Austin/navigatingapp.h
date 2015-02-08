#ifndef NAVIGATINGAPP_H
#define NAVIGATINGAPP_H

#include <QDialog>

namespace Ui {
class NavigatingApp;
}

class NavigatingApp : public QDialog
{
    Q_OBJECT

public:
    explicit NavigatingApp(QWidget *parent = 0);
    ~NavigatingApp();

    void editText();

private:
    Ui::NavigatingApp *ui;
};

#endif // NAVIGATINGAPP_H
