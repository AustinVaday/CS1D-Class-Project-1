#include "guestwindow.h"
#include "ui_guestwindow.h"

GuestWindow::GuestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuestWindow)
{
    ui->setupUi(this);
}

GuestWindow::~GuestWindow()
{
    delete ui;
}


void GuestWindow::on_guaranteeButton_clicked()
{

    Guarantee gWindow;

    gWindow.setModal(true);
    gWindow.exec();

}

void GuestWindow::on_sellButton_clicked()
{
    SellPoint sellWindow;

    sellWindow.setModal(true);
    sellWindow.exec();
}

void GuestWindow::on_EnviroButton_clicked()
{
    Environments eWindow;

    eWindow.setModal(true);
    eWindow.exec();
}

void GuestWindow::on_ConceptOps_clicked()
{
    ConceptOfOps OpWindow;

    OpWindow.setModal(true);
    OpWindow.exec();
}
