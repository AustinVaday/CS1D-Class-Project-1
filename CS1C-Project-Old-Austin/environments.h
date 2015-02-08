#ifndef ENVIRONMENTS_H
#define ENVIRONMENTS_H

#include <QDialog>

namespace Ui {
class Environments;
}

class Environments : public QDialog
{
    Q_OBJECT

public:
    explicit Environments(QWidget *parent = 0);
    ~Environments();

private:
    Ui::Environments *ui;
};

#endif // ENVIRONMENTS_H
