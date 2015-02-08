#include "signupwindow.h"
#include "ui_signupwindow.h"
#include <QDebug>
#include <QMessageBox>
#include "customerlistclass.h"
SignUpWindow::SignUpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);

    ui->NameEdit->setFocus(Qt::OtherFocusReason);


}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

void SignUpWindow::on_buttonBox_accepted(Customer& customer, bool & properFields)
{
    /* AUSTIN VADAY HAS CHANGED THE BELOW CODE IN THIS METHOD */

    QString name = ui->NameEdit->text();
    QString email = ui->EmailEdit->text();
    QString addL1 = ui->AddressLine1Edit->text();
    QString addL2 = ui->AddressLine1Edit_2->text();
    QString pass = ui->PasswordEdit->text();

    properFields = false;
        if (name.isEmpty())
        {

            QMessageBox::information(this, tr("Empty Field"),
                       tr("Please enter in a name."));

        }
        else if (email.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                       tr("Please enter in an email address."));

        }
        else if (addL1.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                       tr("Please enter in an ID number."));
        }
        else if(addL2.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                       tr("Please enter in an ID number."));
        }
        else if (pass.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                       tr("Please enter in a password."));
        }
        else
         {

            customer.setAccountAccess(false);
//            customer.setAccountNum(idString.toLong());
            customer.setEmail(email);
            customer.setPassword(pass);
            customer.setUserName(name);
            customer.setAddressLine1(addL1);
            customer.setAddressLine2(addL2);
//            customer.setAdd

            properFields = true;

        }
}
