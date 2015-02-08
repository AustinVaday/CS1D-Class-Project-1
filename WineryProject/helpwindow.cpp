#include "helpwindow.h"
#include "ui_helpwindow.h"

HelpWindow::HelpWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Help Options");

}

HelpWindow::~HelpWindow()
{
    delete ui;
}

// just a demo
void HelpWindow::on_nextTextButton_clicked()
{
    int index = ui->stackedWidget->currentIndex();

    if (index == 3)
    {
        index = 0;
    }
    else
    {
        index = index + 1;
    }
    ui->stackedWidget->setCurrentIndex(index);



}

void HelpWindow::on_nextTextButton_2_clicked()
{
    ui->page_7->show();
}
