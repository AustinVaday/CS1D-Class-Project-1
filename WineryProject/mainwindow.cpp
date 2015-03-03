#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    wineryList()
{
    ui->setupUi(this);
    wineObject = NULL;
    wineryObject = NULL;
    helpWindow = NULL;
    this->setWindowTitle("Winery Tours!");
    userType = 'n';

    // will allocate memory as needed.
//    wineryList = new SortedList<Winery, float>;

    // if failed to read from file, output error
    if (!ReadFromFile())
    {
        QMessageBox::information(this, "Error 0x333456", "An error has occured, please restart the program. If this error persists, contact your administration with the error id.");
    }

    //comment
    // austin's test comment!
    // austin's test comment #2!!
    //make sure to display first stacked widget widnow!
    ui->stackedWidget->currentWidget()->hide();
    ui->page_main_window->show();

    //creates checkboxes dynamically and the list of wineries
    QVBoxLayout *layList = new QVBoxLayout(this);

    for (QMap<float, Winery>::iterator it = wineryList.begin(); it != wineryList.end(); ++it)
    {
        QString d = QString::number(it.value().GetDistanceToVilla());

        QLabel *wineryListLabels = new QLabel(it.value().GetName());
        wineryListLabels->setStyleSheet("font: 16pt;");
        QLabel *wineryListDistance = new QLabel(d + " mi\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");

        wineryListDistance->setAlignment(Qt::AlignRight);

        layList->addWidget(wineryListLabels);
        layList->addWidget(wineryListDistance);
    }

    ui->scrollAreaWidgetContents->setLayout(layList);

}

MainWindow::~MainWindow()
{
    if (WriteToFile())
    {
        QMessageBox::information(this, "Success", "Write to file success!");
    }

    delete ui;

    if (helpWindow != NULL)
    {
    delete helpWindow;
    }
    if (wineObject != NULL)
    {
        delete wineObject;
    }
    if (wineryObject != NULL)
    {
        delete wineryObject;
    }

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

    ui->userNameLine->setFocus();
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
    readSuccessFull = false;

    // QDir datapath is a pointer that points towards each directory
    while(!dataPath.cd("TextFiles"))
    {
        dataPath.cdUp();
    }

    QFile wineryDataFile((dataPath.path() + "/MasterList.txt"));

    // This checks if the file opens, if it does not, it will display an
    //  error message
    if(wineryDataFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString wineryName;
        int     wineryNum;
        int     numOtherWineries;
        float   milesToCanyonVilla;
        int     numWinesOffered;
        QString  tempString;
        float   distanceToOther;
        // Points Text stream to input file to read in.
        QTextStream inFile(&wineryDataFile);

        while(!inFile.atEnd())
        {
            wineryObject = new Winery;

            wineryName       = inFile.readLine().remove("name of winery: ");

            wineryObject->SetName(wineryName);

            wineryNum         = inFile.readLine().remove("winery number ").toInt();

            wineryObject->SetWineryNum(wineryNum);

            numOtherWineries = inFile.readLine().remove("distance to other wineries - ").toInt();


            // loop to gather all the distances to all other wineries.
            for (int i = 0; i < numOtherWineries; i++)
            {
                int     loopWineryNum;  // corresponding winery number
                QString string1;
                QString string2;
                int numDigits = 1;  // corresponds to length of the number
                                    // that is before the distance in the TEXT
                                    // file. i.e -->     1 0.0
                                    //                   2 2.0
                                    // when this number is greater than 9,
                                    // we have two digits and thus more things to
                                    // remove!


                if (i >= 9)
                {
                    if (i >= 99)
                    {
                        numDigits = numDigits + 2;
                    }
                    else
                    {
                        numDigits = numDigits + 1;
                    }
                }

                string1 = inFile.readLine();
                string2 = string1;

                numDigits = string1.indexOf(' ');
                loopWineryNum = string1.remove(numDigits, string1.size() - 1).toInt();


                // read line, remove the leading digits, convert the string to float
                distanceToOther = string2.remove(0, numDigits).toFloat();
                wineryObject->AddDistance(loopWineryNum, distanceToOther);

            }

            milesToCanyonVilla = inFile.readLine().remove(" miles to Canyon Villa").toFloat();

            wineryObject->setDistanceToVilla(milesToCanyonVilla);

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
                wineObject = new Wine;

                // does nothing for now, will fix this later..
                wineObject->SetName(inFile.readLine());
                wineObject->SetYear(inFile.readLine().toInt());
                wineObject->SetPrice(inFile.readLine().toFloat());

                // add wine to winery
                wineryObject->AddWine(*wineObject);

                // do not allocate memory on last loop
                if (i != numWinesOffered - 1)
                {
                    wineObject = new Wine;
                }
            }

            // Do Something
            inFile.skipWhiteSpace();
            inFile.flush();

            // add list into sorted wine list.
            this->wineryList.insert(milesToCanyonVilla, *wineryObject);
        }
        // sets read true, flushes the Qtextstream buffer
        readSuccessFull = true;

        wineryDataFile.flush();
        wineryDataFile.close();


    }

    for (QMap<float, Winery>::iterator it = wineryList.begin(); it != wineryList.end(); ++it)
    {
        qDebug() << "name of winery: " << it.value().GetName();
        qDebug() << "winery number " << it.value().GetWineryNum();
        qDebug() << "distance to other wineries - " << it.value().GetDistances().size();

        for (QMap<float, int>::const_iterator it2 = it.value().GetDistances().cbegin(); it2 != it.value().GetDistances().cend(); ++it2)
        {
            // list all winery distances (sorted by distance)
            qDebug() << it2.value() << it2.key();

        }

        qDebug() << it.value().GetDistanceToVilla() << " miles to Canyon Villa";
        qDebug() << it.value().GetWines().size()    << "wines offered";

        for (QMap<QString, Wine>::const_iterator it3 = it.value().GetWines().cbegin(); it3 != it.value().GetWines().cend(); ++it3)
        {
            qDebug() << it3.value().GetName();
            qDebug() << it3.value().GetYear();
            qDebug() << it3.value().GetPrice();
        }

        qDebug() << endl;


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
bool MainWindow::WriteToFile()
{
    QDir dataPath = QDir::current();
    bool writeStatus;

    // Failstate signal
    writeStatus = false;

    // Initialize QFile and write failed, Appended File to path, QFile Creates
    while(!dataPath.cd("TextFiles"))
    {
        dataPath.cdUp();
    }


    dataPath.remove((dataPath.path() + "/MasterList.txt"));

    QFile wineryDataFile((dataPath.path() + "/MasterList.txt"));

    if(wineryDataFile.open((QIODevice::ReadWrite | QIODevice::Text)|QIODevice::Truncate) && !wineryList.empty())
    {
        QTextStream out(&wineryDataFile);

        for (QMap<float, Winery>::iterator it = wineryList.begin(); it != wineryList.end(); ++it)
        {
            out << "name of winery: " << it.value().GetName() << endl;
            out << "winery number " << it.value().GetWineryNum() << endl;
            out << "distance to other wineries - " << it.value().GetDistances().size() << endl;

            for (QMap<float, int>::const_iterator it2 = it.value().GetDistances().cbegin(); it2 != it.value().GetDistances().cend(); ++it2)
            {
                // list all winery distances (sorted by distance)
                out << it2.value() << " " << it2.key() << endl;

            }

            out << it.value().GetDistanceToVilla() << " miles to Canyon Villa" << endl;
            out << it.value().GetWines().size()    << " wines offered" << endl;

            for (QMap<QString, Wine>::const_iterator it3 = it.value().GetWines().cbegin(); it3 != it.value().GetWines().cend(); ++it3)
            {
                out << it3.value().GetName() << endl;
                out << it3.value().GetYear() << endl;
                out << it3.value().GetPrice() << endl;
            }

            out << endl;


        }

        // Flushes output buffer

        out.flush();
        writeStatus = true;

// Flushes and coses the data file
    wineryDataFile.flush();
    wineryDataFile.close();
    } // END OPEN FILE IF


    // Returns True or False status
    return writeStatus;


}// **** END METHOD **** //



void MainWindow::on_passwordLine_returnPressed()
{
    // if someone presses enter, let it be as if
    // they clicked the "ok" button

    this->on_admin_log_ok_button_clicked();
}

void MainWindow::on_plan_trip_submit_button_clicked()
{
    for (int i = 0; i < 20; i ++)
    {
        qDebug() << "Instance " << i + 1 << "is: ";

        if (wineryCheckBoxList1[i]->isChecked())
        {
            qDebug() << "CHECKED!";
        }
        else
        {
            qDebug() << "NOT CHECKED!";
        }

    }
}

void MainWindow::on_visit_all_clicked()
{
    ui->page_plan_day_trip->hide();
    ui->visit_all_wineries->show();

    int i=0;
    QVBoxLayout *layCart = new QVBoxLayout(this);

    for (QMap<float, Winery>::iterator it = wineryList.begin(); it != wineryList.end(); ++it)
    {
          QVBoxLayout *layWineList = new QVBoxLayout(this);


        for (QMap<QString, Wine>::const_iterator it3 = it.value().GetWines().cbegin(); it3 != it.value().GetWines().cend(); ++it3)
        {


            QString year = QString::number(it3.value().GetYear());
            QString price = QString::number(it3.value().GetPrice());
            QCheckBox *wineCheckbox = new QCheckBox(it3.value().GetName() + '\n' + year + '\n' +'$' + price, this);
            wineCheckbox->setChecked (false);


            layWineList->addWidget(wineCheckbox);

//            if(i==0)
//            {
//                ui->list_of_wines_scroll_area->setLayout(layWineList);
//            }


        }

            wineryLayoutList.push_back(layWineList);
            ui->list_of_wines_scroll_area->setLayout(layWineList);
            i++;
    }





}

void MainWindow::on_backToTripType_clicked()
{
    ui -> visit_all_wineries -> hide();
    ui -> page_plan_day_trip -> show();
}


void MainWindow::on_next_clicked()
{
//    ui->list_of_wines_scroll_area->
//    ui->list_of_wines_scroll_area->setLayout(wineryLayoutList.at(1));
}
