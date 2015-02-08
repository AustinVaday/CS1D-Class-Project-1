#include "errorlogin.h"
#include "ui_errorlogin.h"

ErrorLogin::ErrorLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorLogin)
{
    ui->setupUi(this);
}

ErrorLogin::~ErrorLogin()
{
    delete ui;
}
