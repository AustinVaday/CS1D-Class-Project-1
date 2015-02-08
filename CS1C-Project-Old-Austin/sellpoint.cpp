#include "sellpoint.h"
#include "ui_sellpoint.h"

SellPoint::SellPoint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SellPoint)
{
    ui->setupUi(this);
}

SellPoint::~SellPoint()
{
    delete ui;
}
