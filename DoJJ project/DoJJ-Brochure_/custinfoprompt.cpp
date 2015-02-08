#include "custinfoprompt.h"
#include "ui_custinfoprompt.h"
#include "responsewindow.h"
#include "sortedlist.h"
#include "customer.h"
#include "admin.h"
#include <QString>
//#include "BigHead.h"

CustInfoPrompt::CustInfoPrompt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustInfoPrompt)
{
    ui->setupUi(this);
}

CustInfoPrompt::CustInfoPrompt(QWidget *parent, Admin* newAdmin) :
    QDialog(parent),
    ui(new Ui::CustInfoPrompt)
{
    ui->setupUi(this);
    admin = newAdmin;
    this->setWindowTitle("Edit Customer");

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

CustInfoPrompt::~CustInfoPrompt()
{
    delete ui;
}

void CustInfoPrompt::on_Cancel_clicked()
{
    this->close();
}

void CustInfoPrompt::on_Add_clicked()
{
    Customer<QString> tempCust;

    QString custName;
    QString custAddy;
    QString custAddy2;
    QString fullAddress;

    int      tempp = ui->InterestBox->currentIndex();
    QTextStream(stdout) << "Interest Count: " << tempp << "\n";
    Interest importance = (Interest)tempp;

    bool key = ui->ImportanceBox->currentIndex();

    custName = ui->CompName->text();
    custAddy = ui->CompAddy->text();
    custAddy2 = ui->CompAddy_2->text();

    fullAddress = custAddy + "\n" + custAddy2;

    tempCust.SetCompName(custName);
    tempCust.SetAddress(fullAddress);
    tempCust.SetInterest(importance);
    tempCust.SetKey(key);

    try
    {
        if (custName.size() == 0 || custAddy.size() == 0)
        {
            throw (tempCust);
        }
        else
        {
            bool found = customerList.SearchForBool(custName);
            if(!found)
            {
                customerList.Add(tempCust,tempCust.GetCompName());
                customerList.SaveCustList(customerList);
                emit changeSuccess();
                this->close();
                responseWindow* response = new responseWindow(NULL, ADD_CUSTOMER);
                response->show();
            }
            else
            {
                responseWindow* response = new responseWindow(NULL, ALREADY_EXISTING_ACCOUNT);
                response->show();
            }
        }
    }
    catch(Customer<QString> tempCust){
        responseWindow* response;
        response = new responseWindow(NULL, INCOMPLETE_FORM);
        response->show();
    }
}

void CustInfoPrompt::on_Remove_clicked()
{
    bool found = false;

    QString custName;
    custName = ui->CompName->text();

    found = customerList.Remove(custName);

    if(found)
    {
        customerList.SaveCustList(customerList);
        emit changeSuccess();
        responseWindow* response;
        response = new responseWindow(NULL, REMOVE_CUSTOMER);
        response->show();
        this->close();
    }
    else
    {
        /*Do not close window, clear texted typed in*/
        responseWindow* response;
        response = new responseWindow(NULL, REMOVE_CUSTOMER_FAIL);
        response->show();
    }
}

void CustInfoPrompt::on_Edit_clicked()
{
    QString nodeToEdit = ui->CompName->text();

    int      tempp = ui->InterestBox->currentIndex();
    QTextStream(stdout) << "Interest Count: " << tempp << "\n";
    Interest importance = (Interest)tempp;

    bool key = ui->ImportanceBox->currentIndex();

    bool found = customerList.SearchForBool(nodeToEdit);
    if(found)
    {
        node<Customer<QString>, QString>* newTemp = customerList.SearchForPtrWrap(nodeToEdit);
        newTemp->item.SetAddress(ui->CompAddy->text() + '\n' + ui->CompAddy_2->text());
        newTemp->item.SetInterest(importance);
        newTemp->item.SetKey(key);

        customerList.SaveCustList(customerList);
        emit changeSuccess();
        this->close();
        responseWindow* response;
        response = new responseWindow(NULL, EDIT_CUSTOMER);
        response->show();
    }
    else
    {
        responseWindow* response;
        response = new responseWindow(NULL, EDIT_CUSTOMER_FAIL);
        response->show();
    }
}
