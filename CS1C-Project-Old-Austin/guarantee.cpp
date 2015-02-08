#include "guarantee.h"
#include "ui_guarantee.h"

Guarantee::Guarantee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Guarantee)
{
    ui->setupUi(this);
}

Guarantee::~Guarantee()
{
    delete ui;
}
