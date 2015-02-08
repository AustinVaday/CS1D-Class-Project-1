#include "customeraccountwindow.h"
#include "ui_customeraccountwindow.h"

CustomerAccountWindow::CustomerAccountWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomerAccountWindow)
{
    ui->setupUi(this);
}

CustomerAccountWindow::~CustomerAccountWindow()
{
    delete ui;
}
