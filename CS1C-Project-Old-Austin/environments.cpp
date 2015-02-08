#include "environments.h"
#include "ui_environments.h"

Environments::Environments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Environments)
{
    ui->setupUi(this);
}

Environments::~Environments()
{
    delete ui;
}
