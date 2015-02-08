#include "find.h"
#include "ui_find.h"
#include <QString>
#include <QMessageBox>

Find::Find(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Find)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();
}

Find::~Find()
{
    delete ui;
}

void Find::on_buttonBox_accepted()
{
    QString text = ui->lineEdit->text();
    if (text.isEmpty())
    {
         QMessageBox::information(this, tr("Empty Field"),
             tr("Please enter a name."));
         return;
     }
    else
     {
         findText = text;
         ui->lineEdit->clear();
     }
}

QString Find::return_searched_name()
{
    return findText;
}
