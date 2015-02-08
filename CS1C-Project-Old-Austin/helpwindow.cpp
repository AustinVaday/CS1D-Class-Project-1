#include "helpwindow.h"
#include "ui_helpwindow.h"
#include "firstdialog.h"
#include "orderproduct.h"
#include "requestbrochure.h"
#include "loginhelp.h"
#include "navigatingapp.h"

HelpWindow::HelpWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
    edit = false;
}

HelpWindow::~HelpWindow()
{
    delete ui;
}


void HelpWindow::on_CreatingAnAccount_clicked()
{
    FirstDialog button;

    if(edit)
    {
        button.editText();
    }


    button.setModal(true);
    button.exec();

}



void HelpWindow::on_HowToOrderAProduct_clicked()
{
    OrderProduct buttonPush;

    if(edit)
    {
       buttonPush.editText();
    }

    buttonPush.setModal(true);
    buttonPush.exec();

}


void HelpWindow::on_RequestingABrochure_clicked()
{
    RequestBrochure buttonPush;

    if(edit)
    {
       buttonPush.editText();
    }

    buttonPush.setModal(true);
    buttonPush.exec();
}

void HelpWindow::on_LoginHelp_clicked()
{
    LoginHelp buttonPush;

    if(edit)
    {
        buttonPush.editText();
    }

    buttonPush.setModal(true);
    buttonPush.exec();
}

void HelpWindow::on_NavigatingApp_clicked()
{
    NavigatingApp buttonPush;

    if(edit)
    {
       buttonPush.editText();
    }

    buttonPush.setModal(true);
    buttonPush.exec();

}

void HelpWindow::editText()
{
    edit = true;
}
