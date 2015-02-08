#include "AdminWindow.h"
#include "newactivatedlist.h"
#include "customerclass.h"
#include "customerlistclass.h"
#include "ui_AdminWindow.h"
#include "Header.h"
#include "customeraddressbook.h"

AdminWindow::AdminWindow(QWidget *parent, CustomerList &list) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{

    /***********************************************************
     * This should be used in all windows except main window!
     ***********************************************************/
    connect(this, SIGNAL(customerListChanged(CustomerList*)), parent, SLOT(updateCustomerList(CustomerList*)));

    customerList = list;
    viewList = new NewActivatedList(this, customerList);
    ui->setupUi(this);
    ui->graphicsView->setStyleSheet("background-image: url(:/Resources/guest.jpg)");
}
AdminWindow::~AdminWindow()
{
	// POINTERS IN CUSTOMER LIST
	customerList.ClearList();
	delete viewList;
	delete ui;
}

void AdminWindow::on_back_button_clicked()
{
    this->hide();
}
void AdminWindow::on_view_activated_customers_clicked()
{
    viewList->show();
}
void AdminWindow::on_modify_help_options_clicked()
{
    emit clicked();
}
void AdminWindow::on_actionHelp_triggered()
{
    emit clicked();
}
void AdminWindow::updateCustomerList(CustomerList *list)
{
	// Notifies the AdminWindow list changed and returns list
    customerList = *list;
    emit customerListChanged(&customerList);

}

