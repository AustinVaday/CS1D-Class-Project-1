#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Winery Tours!");
    userType = 'n';
    helpWindow = new HelpWindow;

    // if failed to read from file, output error
    if (!ReadFromFile())
    {
        QMessageBox::information(this, "Error 0x333456", "An error has occured, please restart the program. If this error persists, contact your administration with the error id.");
    }

    //make sure to display first stacked widget widnow!
    ui->stackedWidget->currentWidget()->hide();
    ui->page_main_window->show();


    //creates checkboxes dynamically and the list of wineries
    //needs to be modified once the SortedList is implemented
    QString s;
    QVBoxLayout *layTrip = new QVBoxLayout(this);
    QVBoxLayout *layList = new QVBoxLayout(this);
    for(int i=0;i<20;i++)
    {
        s = QString::number(i+1);
        QCheckBox *checkbox = new QCheckBox("Winery " + s, this);
        QLabel *wineryList = new QLabel("Winery " + s);
        checkbox->setChecked (false);
        layTrip->addWidget(checkbox);
        layList->addWidget(wineryList);
//      QObject::connect(checkbox, SIGNAL(isChecked()), this, SLOT(clicledCkeckBox()));
    }


    ui->scrollAreaWidgetContents_2->setLayout(layTrip);
    ui->scrollAreaWidgetContents->setLayout(layList);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete helpWindow;
}
//GET/SET FOR USER DATA
void MainWindow::setUser(char type)
{
    userType = type;
}

char MainWindow::getUser()
{
    return userType;
}

// See HelpWindow.cpp
void MainWindow::on_actionHelp_triggered()
{
    helpWindow->show();
}

void MainWindow::on_quitButton_clicked()
{
    this->close();
}

void MainWindow::on_adminLogButton_clicked()
{
    // hide current page and show new page!
    ui->page_main_window->hide();

    //show the admin page. not sure if you have to show all of the below, but
    // we need to test this out later.
    if(userType == 'n')
    {
        ui->page_admin_login->show();
        ui->page_admin_login_form->show();
        ui->page_admin_login_success->hide();
    }
    else if (userType == 'a')
    {
        ui->page_admin_login_success->show();
    }
}

void MainWindow::on_viewListWineriesButton_clicked()
{
    // hide current page and show new page!
    ui->page_main_window->hide();
    ui->stackedWidget->currentWidget()->hide();
    ui->page_view_list_wineries->show();

}

void MainWindow::on_planDayTripButton_clicked()
{
    // hide current page and show new page!
    ui->page_main_window->hide();
    ui->page_plan_day_trip->show();
}

void MainWindow::on_tourWineriesButton_clicked()
{
    // hide current page and show new page!
    ui->page_main_window->hide();
    ui->page_tour_and_purchase->show();
}


void MainWindow::on_admin_log_ok_button_clicked()
{
    // admin credentials!!
    if (ui->userNameLine->text() == "admin" &&    (ui->passwordLine->text() == "password"
                                                || ui->passwordLine->text() == "admin"))
    {
        QMessageBox::information(this, "Notification", "Access Granted!");

        userType = 'a'; //set user to admin

        //restore to previous state
        ui->passwordLine->clear();
        ui->userNameLine->clear();
        ui->userNameLine->setFocus();


        // GRANT ACCESS TO ADMIN WIDGET
        ui->page_admin_login_form->hide();
        ui->page_admin_login_success->show();
    }
    else
    {
        QMessageBox::information(this, "Notification", "Access NOT Granted!");
    }
}

void MainWindow::on_adming_log_cancel_button_clicked()
{
    // hide current page and show new page!

    /* The below code causes admin login snippet to remain in background.. oh no */
    //    ui->stackedWidget->currentWidget()->hide();

    ui->page_admin_login->hide();
    ui->page_main_window->show();
}

void MainWindow::on_admin_log_out_button_clicked()
{
    userType = 'n';
    ui->page_admin_login_success->hide();
    ui->page_admin_login->hide();
    ui->page_admin_login_form->hide();
    ui->page_main_window->show();
}

void MainWindow::on_ViewBack_clicked()
{
    ui->page_view_list_wineries->hide();
    ui->page_main_window->show();
}

void MainWindow::on_PlanTripBack_clicked()
{
    ui->page_plan_day_trip->hide();
    ui->page_main_window->show();
}

void MainWindow::on_TourBack_clicked()
{
    ui->page_tour_and_purchase->hide();
    ui->page_main_window->show();
}

void MainWindow::on_LogInBack_clicked()
{
    ui->page_admin_login->hide();
    ui->page_admin_login_form->hide();
    ui->page_admin_login_success->hide();
    ui->page_main_window->show();
}//update


/************************************************************
* ReadFile (DOES NOT allow to specify filePath)
* ----------------------------------------------------------
* Returns true only if it successfully reads
* Returns false if it fails to open, read or if there are no
*	customers in the database
* ----------------------------------------------------------
* File path is set when first establishing the database
*************************************************************/
bool MainWindow::ReadFromFile()
{
    bool readSuccessFull;
    QDir dataPath = QDir::current();
    QFileInfoList listDirs;
    readSuccessFull = false;

    // QDir datapath is a pointer that points towards each directory
    while(!dataPath.cd("TextFiles"))
    {
        dataPath.cdUp();
    }

    qDebug() << dataPath.currentPath();

    QFile wineryDataFile((dataPath.path() + "/MasterList.txt"));

    // This checks if the file opens, if it does not, it will display an
    //  error message
    if(wineryDataFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        // NEEDS A DATA STRUCTURE...
        QString wineryName;
        int     wineryNum;
        int     numOtherWineries;
        QQueue<float>  distanceToOthers;
        float   milesToCanyonVilla;
        int     numWinesOffered;
        QString  tempString;
       // QQueue  wineClass ... WINE CLASS GOES HERE


        // Points Text stream to input file to read in.
        QTextStream inFile(&wineryDataFile);

        while(!inFile.atEnd())
        {
            wineryName       = inFile.readLine().remove("name of winery: ");
            wineryNum         = inFile.readLine().remove("winery number ").toInt();
            numOtherWineries = inFile.readLine().remove("distance to other wineries - ").toInt();

            // loop to gather all the distances to all other wineries.
            for (int i = 0; i < numOtherWineries; i++)
            {
                int numDigits = 1;  // corresponds to length of the number
                                    // that is before the distance in the TEXT
                                    // file. i.e -->     1 0.0
                                    //                   2 2.0
                                    // when this number is greater than 9,
                                    // we have two digits and thus more things to
                                    // remove!

                if (i >= 10)
                {
                    if (i >= 100)
                    {
                        numDigits = numDigits + 2;
                    }
                    else
                    {
                        numDigits = numDigits + 1;
                    }
                }
                // read line, remove the leading digits, convert the string to float
                distanceToOthers.enqueue(inFile.readLine().remove(0, numDigits).toFloat());

            }


            milesToCanyonVilla = inFile.readLine().remove(" miles to Canyon Villa").toFloat();

            tempString = inFile.readLine();


            // accomodate for wines/wine occurance
            if (tempString.contains("wines"))
            {
                tempString.remove(" wines offered");
            }
            else
            {
                tempString.remove(" wine offered");
            }

            numWinesOffered = tempString.toInt();

            for(int i = 0; i < numWinesOffered; i++)
            {
                // does nothing for now, will fix this later..
                inFile.readLine();
                inFile.readLine();
                inFile.readLine();

                // STORE INTO WINE CLASS
            }

            // Do Something
            inFile.skipWhiteSpace();
            inFile.flush();

            qDebug() << wineryName;
            qDebug() << wineryNum;
            qDebug() << numOtherWineries;
            while (!distanceToOthers.isEmpty())
            {
                qDebug() << distanceToOthers.front();
                distanceToOthers.pop_front();
            }
            qDebug() << "Miles: " << milesToCanyonVilla;
            qDebug() << numWinesOffered;
            qDebug() << endl;
        }
        // sets read true, flushes the Qtextstream buffer
        readSuccessFull = true;

        wineryDataFile.flush();
        wineryDataFile.close();


    }


//    for(count=0;count<wineries;count++)
//    {
//        YSpacer += 26;
//        QCheckBox *dynamicCheckBox = new QCheckBox();
//        dynamicCheckBox->setObjectName ("dynamicCheckBox" + QString(count));
//        dynamicCheckBox->setCheckable (false);
//        dynamicCheckBox->setChecked (false);
//        //layout ()->addWidget (dynamicCheckBox);
//        ui->scrollArea->setWidget  (dynamicCheckBox); //this line
//    }

    return readSuccessFull;

}// **** END METHOD **** //

/************************************************************
* WriteToFile
* -----------------------------------------------------------
* - Overloaded
*	- see WriteToFile(Qstring)
* Returns true only if it successfully writes
* Returns false if it fails to open, write or if there are
*  no customers in the list.
* ------------------------------------------------------------
* File path is set when first establishing the database
*************************************************************/
//bool MainWindow::WriteToFile()
//{
//	Node<Customer>* _customerPtr;
//	QDir dataPath = QDir::current();
//	bool writeStatus;

//	// Failstate signal
//	writeStatus = false;

//	// Initialize QFile and write failed, Appended File to path, QFile Creates

//	while(dataPath.dirName() != "Class-Project")
//	{
//		dataPath.cdUp();
//	}

//	dataPath.cd("Database-Files");

//	dataPath.remove((dataPath.path() + "/CustomerList.txt"));

//	qDebug() << "Does the customer list file exist in the directory?" << dataPath.exists((dataPath.path() + "/CustomerList.txt"));

//qDebug() << "Customer path: line 896 : " << dataPath.path();
//	QFile customerDataFile((dataPath.path() + "/CustomerList.txt"));

//qDebug() << "1) Is it open? "<< customerDataFile.isOpen() << "and can it be written? " <<
//customerDataFile.isWritable();

//	if(customerDataFile.open((QIODevice::ReadWrite | QIODevice::Text)|QIODevice::Truncate) && !isEmpty())
//	{

//	qDebug() << "1) Is it open? "<< customerDataFile.isOpen() << "and can it be written? " <<
//customerDataFile.isWritable();
//		qDebug() << "Debugging:: WRITE Customer :::  It opened ::: ";
//		QTextStream out(&customerDataFile);
//		_customerPtr = _head;

//		while(_customerPtr != 0)
//		{
//			out << _customerPtr->GetData().getUserName() << "\n";
//			out << _customerPtr->GetData().getAddressLine1()  << "\n";
//			out << _customerPtr->GetData().getAddressLine2()  << "\n";
//			out << _customerPtr->GetData().getInterest() << "\n";
//			out << _customerPtr->GetData().getKey()      << "\n";
//			out << _customerPtr->GetData().getPassword() << "\n";
//			out << _customerPtr->GetData().getEmail() << "\n";
//			out << _customerPtr->GetData().getAccountNum() << "\n";

//			if((_customerPtr = _customerPtr->GetNext()) != 0)
//			{
//				out << "\n";
//			}

//		}// END WHILE
//		// Flushes output buffer

//		out.flush();
//		writeStatus = true;

//// Flushes and coses the data file
//	customerDataFile.flush();
//	customerDataFile.close();
//	} // END OPEN FILE IF


//	// Returns True or False status
//	return writeStatus;

//}// **** END METHOD **** //


