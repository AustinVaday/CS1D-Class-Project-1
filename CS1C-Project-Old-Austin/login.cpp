#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    ui->lineEdit_username->setFocus();
}

Login::~Login()
{
    delete ui;
}



void Login::on_buttonBox_loginPress_accepted(QString& user, QString& password)
{
    user     = ui->lineEdit_username->text();

    qDebug() << "first Test" << user;

    password     = ui->lineEdit_password->text();
}

//void Login::on_pushButton_login_clicked(QString& user, QString& password)
//{
//        user     = ui->lineEdit_username->text();
//        user     = ui->lineEdit_username->text();

//}

bool Login::on_buttonBox_loginPress_rejected()
{
    return true;
}
