#include "requestaccount.h"
#include "ui_requestaccount.h"
#include "customer.h"
#include "responsewindow.h"


RequestAccount::RequestAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RequestAccount)
{
    ui->setupUi(this);
    this->setWindowTitle("Request Account");

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

        //While loop
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

RequestAccount::~RequestAccount()
{
    delete ui;
}

void RequestAccount::on_Confirm_clicked()
{
    Customer<QString> tempCust;

    QString custName;
    QString custAddy;
    QString custAddy2;
    QString fullAddress;

    int tempp = ui->InterestBox->currentIndex();
    Interest howInterest = (Interest)tempp;


    custName = ui->CompName->text();
    custAddy = ui->CompAddy->text();
    custAddy2 = ui->CompAddy_2->text();

    fullAddress = custAddy + "\n" + custAddy2;

    tempCust.SetCompName(custName);
    tempCust.SetAddress(fullAddress);
    tempCust.SetInterest(howInterest);

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
                QFile pendingFile("PendingAcc.txt");
                QTextStream pendingStream(&pendingFile);
                if (!pendingFile.open(QIODevice::ReadOnly))
                {
                    QMessageBox::information(0,"Critical Failure","Pending accounts file has failed to load");

                }
                else
                {
                    Customer<QString> tempCust2;
                    while(!pendingStream.atEnd())
                    {
                        tempCust2.SetCompName(pendingStream.readLine());
                        tempCust2.SetAddress(pendingStream.readLine() + '\n' + pendingStream.readLine());
                        QString customerInfo = pendingStream.readLine();
                        Interest interestLevel;
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
                        tempCust2.SetInterest(interestLevel);
                        pendingStream.readLine();
                        pendingAccList.Add(tempCust2, tempCust2.GetCompName());
                    }
                    pendingAccList.Add(tempCust,tempCust.GetCompName());
                    pendingAccList.SavePendingCustList(pendingAccList);
                    this->close();
                    responseWindow* response = new responseWindow(NULL, ADD_CUSTOMER);
                    response->show();
                }
            }
            else
            {
                responseWindow* response = new responseWindow(NULL, ALREADY_EXISTING_ACCOUNT);
                response->show();
            }
        }
    }

    catch(Customer<QString> tempCust)
    {
        responseWindow* response;
        response = new responseWindow(NULL, INCOMPLETE_FORM);
        response->show();
    }
}

void RequestAccount::on_Cancel_clicked()
{
    this->close();
}
