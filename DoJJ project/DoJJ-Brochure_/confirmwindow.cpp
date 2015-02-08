#include "confirmwindow.h"
#include "ui_confirmwindow.h"
#include "responsewindow.h"

confirmWindow::confirmWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::confirmWindow)
{
    ui->setupUi(this);
}

confirmWindow::confirmWindow(QWidget *parent, QString inText, WindowType type) :
    QMainWindow(parent),
    ui(new Ui::confirmWindow)
{
    ui->setupUi(this);

    QString text;

    switch(type)
    {
        case PURCHASE_CONFIRM : text = "Confirm purchase of " + inText + " dollars?";
    }

    ui->text->setText(text);
    ui->text->setWordWrap(true);
    ui->text->setAlignment(Qt::AlignCenter);

}

confirmWindow::~confirmWindow()
{
    delete ui;
}

void confirmWindow::on_confirm_clicked()
{
    this->close();
    responseWindow* response = new responseWindow(NULL, PURCHASE);
    response->show();
}

void confirmWindow::on_cancel_clicked()
{
    this->close();
}
