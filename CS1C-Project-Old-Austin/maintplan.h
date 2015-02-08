#ifndef MAINTPLAN_H
#define MAINTPLAN_H

#include <QDialog>

namespace Ui {
class MaintPlan;
}

class MaintPlan : public QDialog
{
    Q_OBJECT

public:
    explicit MaintPlan(QWidget *parent = 0);
    ~MaintPlan();

private:
    Ui::MaintPlan *ui;
};

#endif // MAINTPLAN_H
