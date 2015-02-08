#include "contactus.h"
#include "ui_contactus.h"
#include "responsewindow.h"
//#include "BigHead.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

contactUs::contactUs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::contactUs)
{
    // Creates the UI
    ui->setupUi(this);
    this->setWindowTitle("Contact Form");

    QFile       contactUsFile("ContactUs.txt");
    QTextStream contactUsInput(&contactUsFile);

    if(!contactUsFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"Critical Failure","Contact us has failed to load");
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
}

contactUs::~contactUs()
{
    // Destroys the UI
    delete ui;
}

void contactUs::on_send_clicked()
{
    node<contactUsInfo, QString>* tempContactList = contactUsList.GetHead();
    bool found = false;

    while(!found && tempContactList != NULL)
    {
        if(tempContactList->item.name == ui->userName->text())
        {
            found = true;
        }
        tempContactList = tempContactList->next;
    }

    if(!found)
    {
        contactUsInfo* newNode = new contactUsInfo;

        newNode->name    = ui->userName->text();

        QString temp      = ui->textEdit->toPlainText();
        for(int index = 0; index < temp.size(); index++)
        {
            if(temp[index] == '\n')
            {
                temp[index] = ' ';
            }
        }
        newNode->message = temp;

        contactUsList.Add(*newNode, newNode->name);
        contactUsList.SaveContactMessages();

        // Closes current window
        this->close();

        responseWindow* response = new responseWindow(NULL,CONTACT_US);
        response->show();
    }
    else
    {
        node<contactUsInfo, QString>* tempNode = contactUsList.SearchForPtrWrap(ui->userName->text());
        tempNode->item.message += ' ' + ui->textEdit->toPlainText();

        contactUsList.SaveContactMessages();

        // Closes current window
        this->close();

        responseWindow* response = new responseWindow(NULL,CONTACT_US);
        response->show();
    }

}

void contactUs::on_cancel_clicked()
{
    this->close();
}
