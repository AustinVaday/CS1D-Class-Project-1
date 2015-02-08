#include "maintplan.h"
#include "ui_maintplan.h"

MaintPlan::MaintPlan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MaintPlan)
{
    ui->setupUi(this);
}

MaintPlan::~MaintPlan()
{
    delete ui;
}
