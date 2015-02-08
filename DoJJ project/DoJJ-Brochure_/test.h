#ifndef TEST_H
#define TEST_H

#include <QDialog>

namespace Ui {
class test;
}

class test : public QDialog
{
    Q_OBJECT

public:
    explicit test(QWidget *parent = 0);
    ~test();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::test *ui;
};

#endif // TEST_H
