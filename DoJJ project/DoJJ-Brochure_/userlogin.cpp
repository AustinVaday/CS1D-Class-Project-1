#include "userlogin.h"
#include "ui_userlogin.h"
#include "irobotuser.h"
#include "usertypewindow.h"
#include "responsewindow.h"
#include "sortedlist.h"
#include "customer.h"
#include "admin.h"
#include <QString>
#include <QFile>
#include <QMessageBox>
//#include "BigHead.h"

userLogin::userLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userLogin)
{
    // Creates UI
    ui->setupUi(this);
    this->setWindowTitle("User Login");
}

userLogin::~userLogin()
{
    // Destroys UI
    delete ui;
}

void userLogin::on_login_clicked()
{
    QString testimonialList = "";
    SortedList<Customer<QString>,QString> customerList;

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

    QString compName;
    bool    loginAllowed = false;

    // Assigns text entered into the lineEdit object in the UI to compName
    compName = ui->lineEdit->text();

    bool found = customerList.SearchForBool(compName);
    if(found)
    {
        loginAllowed = true;
    }

    // Checks if any company name was entered
    if(loginAllowed)
    {
        // Closes current window
        this->close();

        User* user = new User(compName);
        user->SetName(compName);

        // Declares new user portal window
        iRobotUser* mainWindow;
        mainWindow = new iRobotUser(NULL, user);
        // Displays new window
        mainWindow->show();

        // Declares new response window
        responseWindow* response;
        response = new responseWindow(NULL, LOGIN_SUCCESSFUL);
        // Displays new window
        response->show();
    }
    else
    {
        // Declares new response window
        responseWindow* response;
        response = new responseWindow(NULL, LOGIN_FAILED);
        // Displays new window
        response->show();
        ui->lineEdit->clear();
    }
}

void userLogin::on_cancel_clicked()
{
    // Closes current window
    this->close();

    // Declares new login window
    UserTypeWindow* mainWindow;
    mainWindow = new UserTypeWindow();
    // Displays new window
    mainWindow->show();
}
