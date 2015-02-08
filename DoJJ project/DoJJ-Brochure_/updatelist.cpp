#include "updatelist.h"
#include "ui_updatelist.h"
#include "custinfoprompt.h"
//#include "BigHead.h"

UpdateList::UpdateList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateList)
{
    ui->setupUi(this);
}

UpdateList::~UpdateList()
{
    delete ui;
}

void UpdateList::on_AddCustomer_clicked()
{
    CustInfoPrompt* update;
    update = new CustInfoPrompt();
    // Displays new window
    update->show();
}

void UpdateList::on_RemoveCust_clicked()
{
//    bool found;
//    found = Customer.Remove(/*Typed in Info*/);

//    if(found)
//    {
//        /*update list showing GUI*/
//        this->close();
//    }
//    else
//    {
//        /*Do not close window, clear texted typed in*/
//    }
}
