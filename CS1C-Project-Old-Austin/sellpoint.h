#ifndef SELLPOINT_H
#define SELLPOINT_H

#include <QDialog>

namespace Ui {
class SellPoint;
}

class SellPoint : public QDialog
{
    Q_OBJECT

public:
    explicit SellPoint(QWidget *parent = 0);
    ~SellPoint();

private:
    Ui::SellPoint *ui;
};

#endif // SELLPOINT_H
