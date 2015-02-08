#include "firstdialog.h"
#include "ui_firstdialog.h"

FirstDialog::FirstDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstDialog)
{
    editPermission = false;
    ui->setupUi(this);
}

FirstDialog::~FirstDialog()
{
    delete ui;
}

void FirstDialog::editText()
{
        ui->help_CreateAnAccount->setReadOnly(false);
}
