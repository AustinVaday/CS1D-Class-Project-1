#include "irobotadmin.h"
#include "ui_irobotadmin.h"
#include "usertypewindow.h"
#include "responsewindow.h"
#include "otherinfo.h"
#include "custinfoprompt.h"
#include "updatelist.h"
#include "TheUser.h"
#include "admin.h"
//#include "BigHead.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

irobotAdmin::irobotAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::irobotAdmin)
{
    // Creates UI
    ui->setupUi(this);
}

irobotAdmin::irobotAdmin(QWidget *parent, Admin* newAdmin) :
    QMainWindow(parent),
    ui(new Ui::irobotAdmin)
{
    // Creates UI
    ui->setupUi(this);
    this->setWindowTitle("Admin Portal");

    QFile testiFile("testi.txt");
    QTextStream testiInput(&testiFile);
    if(!testiFile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"Critical Failure","Testi has failed to load");
    }

     QFile       contactUsFile("ContactUs.txt");
     QTextStream contactUsInput(&contactUsFile);

     if(!contactUsFile.open(QIODevice::ReadOnly)) {
         QMessageBox::information(0,"Critical Failure","Contact us has failed to load");
     }

     testiInfo* building;
     building = new testiInfo;
     while(!testiInput.atEnd())
     {
         building->name = testiInput.readLine();
         building->message = testiInput.readLine();
         testiList.Add(*building,building->name);
         building = new testiInfo;
     }

     testiFile.close();
     testiInfo tempp;
     for(int i = 0; i<testiList.Size();i++)
     {
         tempp = testiList.operator [](i);
         ui->testiList->addItem(tempp.name);
     }

     contactUsInfo* buildList;
     buildList = new contactUsInfo;
     while(!contactUsInput.atEnd())
     {
         buildList->name = contactUsInput.readLine();
         buildList->message = contactUsInput.readLine();
         contactUsList.Add(*buildList,buildList->name);
         buildList = new contactUsInfo;
     }

    contactUsFile.close();
    contactUsInfo temp;
    for(int i = 0; i < contactUsList.Size();i++)
    {
        temp = contactUsList.operator [](i);
        ui->contactUsList->addItem(temp.name); //temp.name;
    }

    this->SetCustomerList();

    QStringList headers;
    headers << "Name" << "Address" << "Interest Level" << "Customer Importance" << "Brochure Status";

    ui->customerTable->setShowGrid(true);
    ui->customerTable->setColumnCount(5);
    ui->customerTable->setRowCount(0);
    ui->customerTable->setHorizontalHeaderLabels(headers);
    ui->customerTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->addTableItems();


    admin = newAdmin;
    row = 0;

    bool        brochure;
    bool        isKey;
    Interest    interestLevel;

    QFile       pendingAccFile("PendingAcc.txt");
    QTextStream pendingAccFileInput(&pendingAccFile);
    QString     customerInfo;
    QString     customerInfo2;

    if(!pendingAccFile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"Critical Failure","Pending accounts file has failed to load");
    }
    else
    {
        Customer<QString>* newNode = new Customer<QString>;

        while(!pendingAccFileInput.atEnd())
        {
            customerInfo = pendingAccFileInput.readLine();\
            newNode->SetCompName(customerInfo);

            customerInfo  = pendingAccFileInput.readLine();
            customerInfo2 = pendingAccFileInput.readLine();
            customerInfo += '\n' + customerInfo2;\
            newNode->SetAddress(customerInfo);

            customerInfo = pendingAccFileInput.readLine();\
            customerInfo = customerInfo.toLower();

            if(customerInfo == "very interested")
            {
                interestLevel = VERY;
            }
            else if(customerInfo == "somewhat interested")
            {
                interestLevel = SOMEWHAT;
            }
            else if(customerInfo == "not interested")
            {
                interestLevel = NOT;
            }
            else
            {
                interestLevel = NEVER_CALL;
            }
            newNode->SetInterest(interestLevel);

            customerInfo = pendingAccFileInput.readLine();\

            pendingCustomerList.Add(*newNode, newNode->GetCompName());

            newNode = new Customer<QString>;
        }
    }
    pendingAccFile.close();

    Customer<QString> temppp;
    for(int i = 0; i < pendingCustomerList.Size();i++)
    {
        temppp = pendingCustomerList.operator [](i);
        ui->listWidget_2->addItem(temppp.GetCompName());
    }

}

irobotAdmin::~irobotAdmin()
{
    ui->customerTable->setRowCount(0);
    // Destroys UI
    delete ui;
}

void irobotAdmin::on_actionLog_out_triggered()
{
    // Closes current window
    this->close();

    // Declares new login window
    UserTypeWindow* MainWindow;
    MainWindow = new UserTypeWindow();
    // Displays new window
    MainWindow->show();
}

void irobotAdmin::on_actionQuit_triggered()
{
    // Closes current window
    this->close();
}

void irobotAdmin::on_printList_clicked()
{
    // Declares new response window
    responseWindow* response;
    response = new responseWindow(NULL, PRINT_CUSTOMER_LIST);
    // Displays new window
    response->show();
}

void irobotAdmin::on_editList_clicked()
{
    CustInfoPrompt* update;
    update = new CustInfoPrompt(NULL, admin);
    connect(update, SIGNAL(changeSuccess()), this, SLOT(on_updateTable_triggered()));
    // Displays new window
    update->show();
}

void irobotAdmin::on_deleteMessage_clicked()
{
    if(ui->contactUsList->currentItem() != NULL)
    {
        QListWidgetItem *item = ui->contactUsList->currentItem();
        contactUsList.Remove(item->text());
        delete item;
        ui->contactUsText->clear();

        contactUsList.SaveContactMessages();

        responseWindow* response = new responseWindow(NULL, DELETE_MESSAGE);
        response->show();
    }
    else
    {
        responseWindow* response = new responseWindow(NULL, DELETE_FAILED);
        response->show();
    }
}

void irobotAdmin::on_approveTestimonial_clicked()
{
    if(ui->listWidget_2->currentItem() != NULL)
    {
        QListWidgetItem *item = ui->listWidget_2->currentItem();
        Customer<QString> temp = pendingCustomerList.SearchFor(item->text());
        customerList.Add(temp, temp.GetCompName());
        customerList.SaveCustList(customerList);
        emit on_updateTable_triggered();
        pendingCustomerList.Remove(item->text());
        delete item;
        ui->textBrowser_2->clear();

        pendingCustomerList.SavePendingCustList(pendingCustomerList);

        responseWindow* response = new responseWindow(NULL, ACCOUNT_APPROVED);
        response->show();
    }
    else
    {
        responseWindow* response = new responseWindow(NULL, NO_ITEM_SELECTED);
        response->show();
    }
}

void irobotAdmin::on_actionUser_Guide_triggered()
{
    // Declares new help window
    otherInfo* info;
    info = new otherInfo(NULL, HELP_ADMIN);
    // Displays new window
    info->show();
}

void irobotAdmin::DeleteRow()
{
    row--;
}

void irobotAdmin::AddRow()
{
    row++;
}

int irobotAdmin::GetRow()
{
    return row;
}

void irobotAdmin::addTableItems()
{
    static int row = 0;

    for(int index = 0; index < customerList.Size(); index++)
    {
        if(ui->customerTable->rowCount() < row + 1)
        {
            ui->customerTable->setRowCount(row + 1);
        }

        Customer<QString> item = customerList.operator [](index);

        QStringList itemList;
        itemList << item.GetCompName() << item.GetAddress() << item.GetInterest() << item.GetKey() << item.GetBrochureStat();

        for(int column = 0; column < 5; column++){
            QTableWidgetItem *newItem = new QTableWidgetItem(itemList.at(column));
            ui->customerTable->setItem(row, column, newItem);
        }
        row++;
    }
    row = 0;
}


void irobotAdmin::on_contactUsList_itemClicked(QListWidgetItem *item)
{
    contactUsInfo temp = contactUsList.SearchFor(item->text());
    ui->contactUsText->setText(temp.message);
    ui->testiList->setCurrentItem(item);
}

void irobotAdmin::on_listWidget_2_itemClicked(QListWidgetItem *item)
{
    Customer<QString> temp = pendingCustomerList.SearchFor(item->text());
    ui->textBrowser_2->setText(temp.GetCompName() + '\n' + temp.GetAddress() + '\n' + temp.GetInterest());
    ui->listWidget_2->setCurrentItem(item);
}

Ui::irobotAdmin* irobotAdmin::GetUI()
{
    return ui;
}


void irobotAdmin::on_testiList_itemClicked(QListWidgetItem *item)
{
    testiInfo temp = testiList.SearchFor(item->text());
    ui->testiText->setPlainText(temp.message);
    ui->testiList->setCurrentItem(item);
}

void irobotAdmin::on_approveButton_clicked()
{
    if(ui->testiList->currentItem() != NULL)
    {
        QListWidgetItem *item = ui->testiList->currentItem();
        testiInfo temp = testiList.SearchFor(item->text());
        bool found = customerList.SearchForBool(temp.name);

        if(found)
        {
            Customer<QString> custTemp = customerList.SearchFor(temp.name);
            customerList.Remove(custTemp.GetCompName());
            custTemp.SetTestimonial(ui->testiText->toPlainText());
            customerList.Add(custTemp,custTemp.GetCompName());
            customerList.SaveCustList(customerList);
            testiList.Remove(temp.name);
            testiList.SaveTestimonials();

            // Declares new response window
            responseWindow* response;
            response = new responseWindow(NULL, APPROVE_TESTIMONIAL);
            // Displays new window
            response->show();
        }
        else
        {
            testiList.Remove(temp.name);
            testiList.SaveTestimonials();
            responseWindow* response;
            response = new responseWindow(NULL, NON_EXISTING_ACCOUNT);
            // Displays new window
            response->show();
        }
        delete item;
        ui->testiText->clear();
    }
    else
    {
        // Declares new response window
        responseWindow* response;
        response = new responseWindow(NULL, TESTIMONIAL_FAILED);
        // Displays new window
        response->show();
    }
}

void irobotAdmin::on_denyButton_clicked()
{
    if(ui->testiList->currentItem() != NULL)
    {
        QListWidgetItem *item = ui->testiList->currentItem();
        testiList.Remove(item->text());
        delete item;
        ui->testiText->clear();
        testiList.SaveTestimonials();

        // Declares new response window
        responseWindow* response;
        response = new responseWindow(NULL, DENY_TESTIMONIAL);
        // Displays new window
        response->show();
    }
    else
    {
        // Declares new response window
        responseWindow* response;
        response = new responseWindow(NULL, TESTIMONIAL_FAILED);
        // Displays new window
        response->show();
    }
}

void irobotAdmin::SetCustomerList(){
    //CUSTOMER LIST READING FROM FILE
    bool        brochure;
    bool        isKey;
    Interest    interestLevel;

    QFile       customerFile("CustomerList.txt");
    QTextStream customerIn(&customerFile);
    QString     customerInfo;
    QString     customerInfo2;

    if(!customerFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(0,"Critical Failure","Customer file has failed to load");
    }
    else
    {
        Customer<QString>* newNode = new Customer<QString>;

        while(!customerIn.atEnd())
        {
            customerInfo = customerIn.readLine();
            QTextStream(stdout) << customerInfo << endl;
            newNode->SetCompName(customerInfo);

            customerInfo  = customerIn.readLine();
            customerInfo2 = customerIn.readLine();
            customerInfo += '\n' + customerInfo2;
            QTextStream(stdout) << customerInfo << endl;
            newNode->SetAddress(customerInfo);

            customerInfo = customerIn.readLine();
            QTextStream(stdout) << customerInfo << endl;
            customerInfo = customerInfo.toLower();

            if(customerInfo == "very interested")
            {
                interestLevel = VERY;
            }
            else if(customerInfo == "somewhat interested")
            {
                interestLevel = SOMEWHAT;
            }
            else if(customerInfo == "not interested")
            {
                interestLevel = NOT;
            }
            else
            {
                interestLevel = NEVER_CALL;
            }
            newNode->SetInterest(interestLevel);

            customerInfo = customerIn.readLine();
            QTextStream(stdout) << customerInfo << endl;
            customerInfo = customerInfo.toLower();

            if(customerInfo == "key")
            {
                isKey = true;
            }
            else
            {
                isKey = false;
            }
            newNode->SetKey(isKey);

            customerInfo = customerIn.readLine();
            QTextStream(stdout) << customerInfo << endl;
            customerInfo = customerInfo.toLower();

            if(customerInfo == "true")
            {
                brochure = true;
            }
            else
            {
                brochure = false;
            }
            newNode->SetBrochureStat(brochure);

            customerInfo = customerIn.readLine();
            QTextStream(stdout) << customerInfo << endl;
            newNode->SetTestimonial(customerInfo);

            customerInfo = customerIn.readLine();
            QTextStream(stdout) << customerInfo << endl;

            customerList.Add(*newNode, newNode->GetCompName());

            newNode = new Customer<QString>;
        }
    }

    customerFile.close();
}

void irobotAdmin::UpdateCustomerList()
{
    if(customerList.Size()!= 0){
        customerList.DeleteAll();
    }

    SetCustomerList();
}

void irobotAdmin::deleteTableItems()
{
    ui->customerTable->clear();
    for(int count = customerList.Size(); count > 0; count--)
    {
        ui->customerTable->removeRow(count);
    }
}

void irobotAdmin::on_updateTable_triggered()
{
    //Updates Table Items on screen
    deleteTableItems();
    UpdateCustomerList();

    QStringList headers;
    headers << "Name" << "Address" << "Interest Level" << "Customer Importance" << "Brochure Status";
    ui->customerTable->setHorizontalHeaderLabels(headers);

    addTableItems();
}

void irobotAdmin::on_approveTestimonial_2_clicked()
{
    if(ui->listWidget_2->currentItem() != NULL)
    {
        QListWidgetItem *item = ui->listWidget_2->currentItem();
        Customer<QString> temp = pendingCustomerList.SearchFor(item->text());
        emit on_updateTable_triggered();
        pendingCustomerList.Remove(item->text());
        delete item;
        ui->textBrowser_2->clear();

        pendingCustomerList.SavePendingCustList(pendingCustomerList);

        responseWindow* response = new responseWindow(NULL, DENY_ACCOUNT);
        response->show();
    }
    else
    {
        responseWindow* response = new responseWindow(NULL, NO_ITEM_SELECTED);
        response->show();
    }
}
