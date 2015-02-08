#include "irobotuser.h"
#include "ui_irobotuser.h"
#include "usertypewindow.h"
#include "responsewindow.h"
#include "otherinfo.h"
#include "contactus.h"
#include "confirmwindow.h"
#include "TheUser.h"
#include "requestaccount.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

iRobotUser::iRobotUser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::iRobotUser)
{
    // Creates UI
    ui->setupUi(this);
    // Changes the background color of the tabWidget
    ui->tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240)"));

    // Opens concept.txt file
    QFile       conceptFile(":/Text/concept.txt");
    // Declares new textStream variable
    QTextStream conceptIn(&conceptFile);
    QString     concept;

    // Verifies that the file was properly opened.
    // If the file has not opened, an error popup will appear
    if(!conceptFile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"Critical Failure","Concept of Operations has failed to load");
    }

    // Reads all text from concept.txt into concept QString variable
    concept = conceptIn.readAll();

    // Closes concept text file
    conceptFile.close();

    // Displays text in the conceptofOperations label
    ui->conceptofOperations->setText(concept);
    // Aligns the text to the top of the conceptofOperations label
    ui->conceptofOperations->setAlignment(Qt::AlignTop);
    // Enables wordwrapping inside the conceptofOperations label
    ui->conceptofOperations->setWordWrap(true);


    // Opens salesPitch.txt file
    QFile       salesPitchFile(":/Text/salesPitch.txt");
    // Declares new textStream variable
    QTextStream salesIn(&salesPitchFile);
    QString     salesPitch;

    // Verifies that the file was properly opened.
    // If the file has not opened, an error popup will appear
    if(!salesPitchFile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"Critical Failure","Sales Pitch has failed to load");
    }

    // Reads all information from salesPitch.txt into salesPitch QString variable
    salesPitch = salesIn.readAll();

    // Closes salesPitch text file
    salesPitchFile.close();

    // Displays text in the salesPitch label
    ui->salesPitch->setText(salesPitch);
    // Aligns the text to the top of the salesPitch label
    ui->salesPitch->setAlignment(Qt::AlignTop);
    // Enables wordwrapping inside the salesPitch label
    ui->salesPitch->setWordWrap(true);

    QFile     listOfEnviornmentsFile(":/Text/ListOfEnvitemnets.txt");
    QTextStream enviornmentIn(&listOfEnviornmentsFile);
    QString   enviornmentList;

    if(!listOfEnviornmentsFile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"Critical Failure","Sales Pitch has failed to load");
    }
    enviornmentList = enviornmentIn.readAll();
    listOfEnviornmentsFile.close();

    ui->envitemnetList->setText(enviornmentList);
    ui->envitemnetList->setAlignment(Qt::AlignTop);
    ui->envitemnetList->setWordWrap(true);
}

iRobotUser::iRobotUser(QWidget *parent, User* newUser) :
    QMainWindow(parent),
    ui(new Ui::iRobotUser)
{
    // Creates UI
    ui->setupUi(this);
    this->setWindowTitle("iRobot - The Bomb");

    // Changes the background color of the tabWidget
    ui->tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240)"));

    // Opens concept.txt file
    QFile       conceptFile(":/Text/concept.txt");
    // Declares new textStream variable
    QTextStream conceptIn(&conceptFile);
    QString     concept;

    // Verifies that the file was properly opened.
    // If the file has not opened, an error popup will appear
    if(!conceptFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::information(0,"Critical Failure","Concept of Operations has failed to load");
    }

    // Reads all text from concept.txt into concept QString variable
    concept = conceptIn.readAll();

    // Closes concept text file
    conceptFile.close();

    // Displays text in the conceptofOperations label
    ui->conceptofOperations->setText(concept);
    // Aligns the text to the top of the conceptofOperations label
    ui->conceptofOperations->setAlignment(Qt::AlignTop);
    // Enables wordwrapping inside the conceptofOperations label
    ui->conceptofOperations->setWordWrap(true);


    // Opens salesPitch.txt file
    QFile       salesPitchFile(":/Text/salesPitch.txt");
    // Declares new textStream variable
    QTextStream salesIn(&salesPitchFile);
    QString     salesPitch;

    // Verifies that the file was properly opened.
    // If the file has not opened, an error popup will appear
    if(!salesPitchFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::information(0,"Critical Failure","Sales Pitch has failed to load");
    }

    // Reads all information from salesPitch.txt into salesPitch QString variable
    salesPitch = salesIn.readAll();

    // Closes salesPitch text file
    salesPitchFile.close();

    // Displays text in the salesPitch label
    ui->salesPitch->setText(salesPitch);
    // Aligns the text to the top of the salesPitch label
    ui->salesPitch->setAlignment(Qt::AlignTop);
    // Enables wordwrapping inside the salesPitch label
    ui->salesPitch->setWordWrap(true);

    // ENVIRONMENTS LIST
    QFile       listOfEnviornmentsFile(":/Text/ListOfEnvitemnets.txt");
    QTextStream enviornmentIn(&listOfEnviornmentsFile);
    QString     enviornmentList;

    // Opens the List of Enviornments files
    if(!listOfEnviornmentsFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::information(0,"Critical Failure","List of Enviornments has failed to load");
    }
    // Reads all info from file
    enviornmentList = enviornmentIn.readAll();
    listOfEnviornmentsFile.close();

    // Displays text from file onto the GUI
    ui->envitemnetList->setText(enviornmentList);
    ui->envitemnetList->setAlignment(Qt::AlignTop);
    ui->envitemnetList->setWordWrap(true);


    // GUARANTEE POLICY
    QFile       guaranteePolicyFile(":/Text/GuaranteePolicy.txt");
    QTextStream guaranteePolicyIn(&guaranteePolicyFile);
    QString     guaranteePolicy;

    // Opens guarantee policy file
    if(!guaranteePolicyFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::information(0,"Critical Failure","Guarantee Policy has failed to load");
    }

    // Reads all text from the file
    guaranteePolicy = guaranteePolicyIn.readAll();
    guaranteePolicyFile.close();

    // Displays text from file onto GUI
    ui->guaranteePolicyLabel->setText(guaranteePolicy);
    ui->guaranteePolicyLabel->setAlignment(Qt::AlignTop);
    ui->guaranteePolicyLabel->setWordWrap(true);

    // Opens maintenance.txt file
    QFile       maintenanceFile(":/Text/maintenance.txt");
    // Declares new textStream variable
    QTextStream maintenanceIn(&maintenanceFile);
    QString     maintenanceStr;

    // Verifies that the file was properly opened.
    // If the file has not opened, an error popup will appear
    if(!maintenanceFile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"Critical Failure","Maintanence has failed to load");
    }

    // Reads all text from concept.txt into concept QString variable
    maintenanceStr = maintenanceIn.readAll();

    // Closes concept text file
    maintenanceFile.close();

    // Displays text in the conceptofOperations label
    ui->Maintenance->setText(maintenanceStr);
    // Aligns the text to the top of the conceptofOperations label
    ui->Maintenance->setAlignment(Qt::AlignTop);
    // Enables wordwrapping inside the conceptofOperations label
    ui->Maintenance->setWordWrap(true);

    // TESTIMONIALS
    bool        brochure;
    bool        isKey;
    Interest    interestLevel;
    QString     testimonialList = "";

    QFile       customerFile("CustomerList.txt");
    QTextStream customerIn(&customerFile);
    QString     customerInfo;
    QString     customerInfo2;

    // Opens customer list file
    if(!customerFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(0,"Critical Failure","Customer file has failed to load");
    }
    else
    {
        Customer<QString>* newNode = new Customer<QString>;

        // Reads in list
        while(!customerIn.atEnd())
        {
            // Reads in name
            customerInfo = customerIn.readLine();
            newNode->SetCompName(customerInfo);

            // Reads in address
            customerInfo  = customerIn.readLine();
            customerInfo2 = customerIn.readLine();
            customerInfo += '\n' + customerInfo2;
            newNode->SetAddress(customerInfo);

            // Reads in interest level
            customerInfo = customerIn.readLine();
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

            // Reads in key status
            customerInfo = customerIn.readLine();
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

            // Reads brochure request status
            customerInfo = customerIn.readLine();
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

            // Reads in testimonial
            customerInfo = customerIn.readLine();
            newNode->SetTestimonial(customerInfo);

            if(customerInfo != "")
            {
                testimonialList += newNode->GetCompName() + ":\n" + newNode->GetTestimonial() + "\n\n";
            }

            customerInfo = customerIn.readLine();

            customerList.Add(*newNode, newNode->GetCompName());

            newNode = new Customer<QString>;
        }
    }
    customerFile.close();

    ui->testimonialDisplay->setStyleSheet("background-color: white");
    ui->testimonialDisplay->setText(testimonialList);

    user = newUser;

    if(user->GetName() != "Guest")
    {
        // Hides button from users
        ui->requestAccount->hide();
    }
    else
    {
        // Hides buttons from guests
        ui->textEdit->hide();
        ui->addTestimonial->hide();
        ui->purchase->hide();
        ui->requestBrochure->hide();
    }

    QFile testiFile("testi.txt");
    QTextStream testiInput(&testiFile);
    // Opens pending testimonial file
    if(!testiFile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"Critical Failure","Testi has failed to load");
    }

    testiInfo* building;
    building = new testiInfo;
    while(!testiInput.atEnd())
    {
        // Reads info from file into new node
        building->name = testiInput.readLine();
        building->message = testiInput.readLine();
        // Adds node to list
        testiList.Add(*building,building->name);
        building = new testiInfo;
    }
    testiFile.close();
}

iRobotUser::~iRobotUser()
{
    // Destroys UI
    delete ui;
}

void iRobotUser::on_actionLog_out_triggered()
{
    // Closes current window
    this->close();

    // Declares new login window
    UserTypeWindow* mainWindow;
    mainWindow = new UserTypeWindow();
    // Displays new window
    mainWindow->show();
}

void iRobotUser::on_actionQuit_triggered()
{
    // Closes current window
    this->close();
}

void iRobotUser::on_requestBrochure_clicked()
{
    node<Customer<QString>, QString> *temp = customerList.GetHead();
    Customer<QString> tempo = customerList.SearchFor(user->GetName());

    // If user hasn't already requested brochure
    if(tempo.GetBrochureStat() == "False")
    {
        node<Customer<QString>,QString>* tempNode = customerList.SearchForPtrWrap(user->GetName());

        // Set new brochure status
        tempNode->item.SetBrochureStat(true);

        // Saves new list
        customerList.SaveCustList(customerList);

        // Declares new response window
        responseWindow* response;
        response = new responseWindow(NULL, REQUEST_BROCHURE);
        // Displays new window
        response->show();
    }
    else
    {
        // Declares new response window
        responseWindow* response;
        response = new responseWindow(NULL, BROCHURE_REQUESTED);
        // Displays new window
        response->show();
    }
}

void iRobotUser::on_printBrochure_clicked()
{
    // Opens environment list file
    QFile listOfEnviornmentsFile(":/Text/ListOfEnvitemnets.txt");
    if(!listOfEnviornmentsFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"Critical Failure","List of enviornments has failed to load");
    }

    // Opens sales pitch file
    QFile salesPitchFile(":/Text/salesPitch.txt");
    if(!salesPitchFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"Critical Failure","Sales pitch has failed to load");
    }

    // Opens concept of operations file
    QFile conceptFile(":/Text/concept.txt");
    if(!conceptFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"Critical Failure","Product concept has failed to load");
    }

    // Opens guarantee files
    QFile guaranteeFile(":/Text/GuaranteePolicy.txt");
    if(!guaranteeFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"Critical Failure","Guarantee policy has failed to load");
    }

    // Connects streams to files
    QTextStream enviornmentIn(&listOfEnviornmentsFile);
    QTextStream salesPitchIn(&salesPitchFile);
    QTextStream conceptIn(&conceptFile);
    QTextStream guaranteeIn(&guaranteeFile);

    QString enviornmentList;
    QString salesPitch;
    QString concept;
    QString guarantee;

    // Reads in all text from all files
    enviornmentList = enviornmentIn.readAll();
    salesPitch      = salesPitchIn.readAll();
    concept         = conceptIn.readAll();
    guarantee       = guaranteeIn.readAll();

    listOfEnviornmentsFile.close();
    salesPitchFile.close();
    conceptFile.close();
    guaranteeFile.close();

    QString fileName = "brochure.txt";
    QFile brochureFile(fileName);

    // Opens brochure file
    if(!brochureFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::information(0,"Critical Failure","Output has failed to load");
    }

    // Opens text stream to brochure file
    QTextStream out(&brochureFile);

    // Word wraps all text from text files
    enviornmentList = WordWrap(enviornmentList, 75);
    salesPitch      = WordWrap(salesPitch,      75);
    concept         = WordWrap(concept,         75);
    guarantee       = WordWrap(guarantee,       75);

    // Writes info to file
    out << enviornmentList << endl;
    out << salesPitch      << endl;
    out << concept         << endl << endl;
    out << guarantee       << endl;

    brochureFile.close();

    // Declares new response window
    responseWindow* response;
    response = new responseWindow(NULL, PRINT_BROCHURE);
    // Displays new window
    response->show();
}

void iRobotUser::on_addTestimonial_clicked()
{
    node<testiInfo, QString>* tempTestiList = testiList.GetHead();
    bool found = false;

    // Searches the list checking if the user has already sent a testimonial
    while(!found && tempTestiList != NULL)
    {
        if(user->GetName() == tempTestiList->item.name)
        {
            found = true;
        }
        tempTestiList = tempTestiList->next;
    }

    // If an object of the same name was found
    if(found)
    {
        ui->textEdit->clear();

        // Declares new response window
        responseWindow* response;
        response = new responseWindow(NULL, TESTI_PENDING);
        // Displays new window
        response->show();
    }
    else
    {
        // Creates new testiInfo struct
        testiInfo* newTesti = new testiInfo;

        newTesti->name    = user->GetName();

        QString temp      = ui->textEdit->toPlainText();
        // Replaces all \n in testimonial input with ' '
        for(int index = 0; index < temp.size(); index++)
        {
            if(temp[index] == '\n')
            {
                temp[index] = ' ';
            }
        }
        newTesti->message = temp;

        // Adds testimonial to pending list
        testiList.Add(*newTesti, newTesti->name);
        // Saves pending list
        testiList.SaveTestimonials();

        // Clears input field
        ui->textEdit->clear();

        // Declares new response window
        responseWindow* response;
        response = new responseWindow(NULL, ADD_TESTIMONIAL);
        // Displays new window
        response->show();
    }
}

void iRobotUser::on_purchase_clicked()
{
    QString text = ui->total->text();
    // Declares new confirmWindow
    if(text.size() > 0)
    {
        confirmWindow* confirm = new confirmWindow(NULL, text, PURCHASE_CONFIRM);
        // Displays new window
        confirm->show();
    }
    else
    {
        // Displays new window if the price wasn't
        responseWindow* response = new responseWindow(NULL, PURCHASE_FAILED);
        response->show();
    }
}

void iRobotUser::on_contactus_clicked()
{
    // Declares new contactUs window
    contactUs* contact;
    contact = new contactUs();
    // Displays new window
    contact->show();
}

void iRobotUser::on_actionUser_Guide_triggered()
{
    // Declares new help window
    otherInfo* info;
    info = new otherInfo(NULL, HELP_USER);
    // Displays new window
    info->show();
}

// Word wraps text from files
QString iRobotUser::WordWrap(QString bigString, int lineLimit)
{
    int index; //PROC- LCV & counts backwards to find blank space in string
    int sizeOf;//PROC- the size of the string

    sizeOf = bigString.size();
    index  = lineLimit;

    //WHILE - adds new lines to the string each time it needs to be wrapped
    while(index < sizeOf)
    {
        if(bigString[index] == ' ')
        {
            bigString[index] = '\n';
            index += lineLimit;
        }
        else
        {
            index --;
        }
    }
    return bigString;
}

// Calculates total cost of potential purchase
void iRobotUser::on_pushButton_clicked()
{
    float   modelPrice;
    int     numRobots;

    // Checks if lowest level model is selected
    if(ui->basic->isChecked())
    {
        modelPrice = 199.99;
    }
    // Checks if mid level model is selected
    else if(ui->advanced->isChecked())
    {
        modelPrice = 249.99;
    }
    // Checks if highest level model is selected
    else if(ui->hardcore->isChecked())
    {
        modelPrice = 299.99;
    }
    else
    {
        modelPrice = 0;
    }

    // Checks if maintenance option is selected
    if (ui->maintenanceButton->isChecked())
    {
        modelPrice += 42852.6;
    }

    // Allows user to choose number of robots to purchase
    numRobots = ui->spinBox->value();

    // Calculates total cost
    float totalFloat = 0.00;
    totalFloat = numRobots * modelPrice;
    float tax        = totalFloat * 0.08;
    totalFloat = totalFloat + tax;

    // Converts floats to strings
    QString totalString = QString::number(totalFloat, 'f', 2);
    QString taxString   = QString::number(tax, 'f', 2);

    // Displays strings onto GUI
    ui->tax->setText(taxString);
    ui->total->setText(totalString);
}

// Request account button for guests
void iRobotUser::on_requestAccount_clicked()
{
    // Opens request account for for guests
    RequestAccount* newAccount;
    newAccount = new RequestAccount();
    newAccount->show();
}
