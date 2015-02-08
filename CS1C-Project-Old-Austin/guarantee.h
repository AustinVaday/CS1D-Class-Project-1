#ifndef GUARANTEE_H
#define GUARANTEE_H

#include <QDialog>

namespace Ui {
class Guarantee;
}

class Guarantee : public QDialog
{
    Q_OBJECT

public:
    explicit Guarantee(QWidget *parent = 0);
    ~Guarantee();

private:
    Ui::Guarantee *ui;
};

#endif // GUARANTEE_H
