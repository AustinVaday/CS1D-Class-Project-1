#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    wineryList()
{
    ui->setupUi(this);

//    ui->addToCart->setEnabled(false);
    QList<int> list;
    scrollAreaListStacked = new QStackedWidget;

    
    
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


    //Used to display wineries and wines in admin
    QStringList headers;
    headers << "Name" << "Distance From Villa";

    ui->wineryTable->setShowGrid(true);
    ui->wineryTable->setColumnCount(2);
    ui->wineryTable->setRowCount(0);
    ui->wineryTable->setHorizontalHeaderLabels(headers);
    ui->wineryTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    updateWineryTableItems();
}

MainWindow::~MainWindow()
{
    if (WriteToFile())
    {
        QMessageBox::information(this, "Success", "Write to file success!");
    }

    delete ui;
    delete scrollAreaListStacked;
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
        ui->page_admin_login->show();
        ui->page_admin_login_success->show();
    }

    ui->userNameLine->setFocus();
}

void MainWindow::on_viewListWineriesButton_clicked()
{
    QVBoxLayout *layList = new QVBoxLayout(this);

    for (QMap<int, Winery>::iterator it = wineryList.begin()+1; it != wineryList.end(); ++it)
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



void MainWindow::on_admin_log_ok_button_clicked()
{
    // admin credentials!!
    if (ui->userNameLine->text() == "admin" &&    (ui->passwordLine->text() == "password"
                                                || ui->passwordLine->text() == "admin"))
    {
        userType = 'a'; //set user to admin

        //restore to previous state
        ui->passwordLine->clear();
        ui->userNameLine->clear();
        ui->userNameLine->setFocus();


        // GRANT ACCESS TO ADMIN WIDGET
        ui->page_admin_login_form->hide();
        ui->page_admin_login_success->show();
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
    ui->page_shortest_trip->hide();
    ui->page_plan_day_trip->show();
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
            this->wineryList.insert(wineryObject->GetWineryNum(), *wineryObject);
        }
        // sets read true, flushes the Qtextstream buffer
        readSuccessFull = true;

        wineryDataFile.flush();
        wineryDataFile.close();


    }

    for (QMap<int, Winery>::iterator it = wineryList.begin(); it != wineryList.end(); ++it)
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

        for (QMap<int, Winery>::iterator it = wineryList.begin(); it != wineryList.end(); ++it)
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


void MainWindow::on_visit_all_clicked()
{
    ui->page_plan_day_trip->hide();
    ui->page_purchase_wines->show();

    QString year;
    QString price;

    currWinery = 0;


    QList<Winery> wineries;
    float    totalDist       = 0.0;


    // return shortest path of wineries, total distance traversed.

    /* ENTIRE TRIP */
    ShortestPath(wineries,
                 totalDist,
                 false,     // NOT shortest trip
                 NULL,      // no specifieddata
                 0,         // no specified data
                 false,     // NOT custom Trip
                 NULL);     // no specified data


    qDebug() << "\n\n\n OUTPUTTING ENTIRE TRIP PATH\n";
    qDebug() << "TOTAL DISTANCE IS: " << totalDist;

 ui-> wineryName->setText(wineries[0].GetName());

 ui->subtotal->setText("Total: $0");

 qDebug() << "size " << wineries.size();

 for (int l = 0; l < wineries.size(); l++)
 {
    qDebug() << "name " << wineries[l].GetName();
 }


    for (int l = 0; l < wineries.size(); l++)
    {
        QCheckBox *wineCheckbox;
        QVBoxLayout *layWineList = new QVBoxLayout();
        QWidget *wineriesWidget  = new QWidget;
        names.push_back(wineries[l].GetName());

      for (QMap<QString, Wine>::const_iterator it3 = wineries[l].GetWines().cbegin(); it3 != wineries[l].GetWines().cend(); ++it3)
      {
          year = QString::number(it3.value().GetYear());
          price = QString::number(it3.value().GetPrice());

          wineCheckbox = new QCheckBox(it3.value().GetName() + ' ' + year + '\n' + "Price: $" + price, this);
          winePrices.push_back(it3.value().GetPrice());
          layWineList->addWidget(wineCheckbox);
          wineriesWidget->setLayout(layWineList);
          wineCheckBoxList1.push_back(wineCheckbox);
      }

      scrollAreaListStacked->addWidget(wineriesWidget);
    }

       ui->scrollArea->setWidget(scrollAreaListStacked);

       scrollAreaListStacked->setCurrentIndex(0);

       ui->wineryName->setStyleSheet("font: 16pt;");
}

void MainWindow::on_backToTripType_clicked()
{
    ui -> page_purchase_wines -> hide();
    ui -> page_plan_day_trip -> show();
}


void MainWindow::on_next_clicked()
{

    if(currWinery < scrollAreaListStacked->count() - 1)
    {
        qDebug() << "WINERY NUM (NEXT) IS: " << currWinery;

        currWinery++;

        scrollAreaListStacked->setCurrentIndex(currWinery);

        ui-> wineryName->setText(names[currWinery]);

        ui->prev_winery->setEnabled(true);

    }
    else
    {
        ui->next->setEnabled(false);
//        QMessageBox messageBox;
//        messageBox.critical(0,"Error","You have reached an end!");

    }


}

void MainWindow::on_prev_winery_clicked()
{
    qDebug() << "WINERY NUM (PREV) IS: " << wineryNum;


    if(currWinery > 0)
    {
         currWinery--;

         scrollAreaListStacked->setCurrentIndex(currWinery);

         ui-> wineryName->setText(names[currWinery]);

         ui->next->setEnabled(true);

    }
    else
    {
       ui->prev_winery->setEnabled(false);

    }
}

void MainWindow::ShortestPath(QList<Winery>&        shortestPathList,   // the resulting shorted path
                              float&                distanceTravelled,  // the total distance travelled
                              bool                  shortestTrip,       // For shortest trip, you will need to enter data in for:
                                                                        //      --> beginningWinery
                                                                        //      --> wineriesToVisit
                                                                        // and let the rest be as follows
                                                                        //      --> wineriesToVisit : 0
                                                                        //      --> customTrip : false
                                                                        //      --> customWineryList : NULL
                              const Winery*         beginningWinery,        // CONST ptr so that cannot change the winery
                              int                   wineriesToVisit,
                              bool                  customTrip,         // For custom trip, you will need to enter data in for:
                                                                        //      --> customerWineryList
                                                                        // and let the rest be as follows
                                                                        //      --> shortestTrip : false
                                                                        //      --> beginningWinery : NULL

                              QMap<int,Winery>*   customWineryList)   // Map for CUSTOM TRIP
{
    Winery currentWinery;
    QMap<int, Winery> tempWineryList;
    QMap<float, int> distMap;
    int wineryNum = 0;
    distanceTravelled = 0.0;
    bool notFound = true;
    bool loopCondition;


    // store winery list into a local temp list.
    if (customTrip)
    {
        tempWineryList = *customWineryList;


    }
    else // if entire trip or shortest trip
    {
        tempWineryList = wineryList;
    }

    // perform shortest path algo if and only if we have nodes
    if (!tempWineryList.isEmpty())
    {
        // if shortest trip, the user has selected a starting
        // winery..
        if (shortestTrip && beginningWinery != NULL)
        {
            currentWinery = *beginningWinery;
        }
        else
        {

            // find shortest distance to Villa, this will be the starting point. O(n)
            currentWinery = closestToVilla(tempWineryList);


        }
        // starting winery num
        wineryNum = currentWinery.GetWineryNum();


        // distance from villa to starting winery
        distanceTravelled = currentWinery.GetDistanceToVilla();

        // loop until ALL wineries have been traversed.
        int index = 0;
        int size = tempWineryList.size();

        /* CONDITION OF OUTER LOOP*/
        // if shortest trip, then user has selected
        // a specific number of wineries to visit. Make sure
        // not to exceed this number
        if (shortestTrip && wineriesToVisit != 0)
        {
            loopCondition = (index < size && index < wineriesToVisit);
        }
        else // if custom trip or entire trip
        {
            loopCondition = (index < size);
        }

        while (loopCondition)
        {
            notFound = true;

            // find next distance to visit.
            // using the class variable wineryList here is OK
            // because we map each winery num to a specific
            // winery! So as long as the winery numbers are unique,
            // the folowwing operation will always work.
            distMap = wineryList[wineryNum].GetDistances();

            // start 1 AFTER beginning (because beginning is distance to
            // itself)
            QMap<float, int>::iterator distIt = distMap.begin() + 1;
            while (distIt!= distMap.end() && notFound)
            {

                // check if the winery exists (if not, we've already visited it)
                if (tempWineryList.contains(distIt.value()))
                {

                    // remove old from map
                    tempWineryList.remove(wineryNum);


                    // update the winery num
                    // remember: value == winery num, key == distance (sorted by key/distance)
                    wineryNum = distIt.value();


                    // keep adding up the distances
                    qDebug() << "DIST TRAV - BEFORE: " << distanceTravelled;

                    // if we're doing a shortest trip and the shortest path size
                    // is equal to that of one less than how many wineries we seek,
                    // we know that it's our last location, so we need to get it's
                    // distance to the villa instead.
                    if (shortestTrip && shortestPathList.size() == wineriesToVisit - 1)
                    {
                        distanceTravelled += currentWinery.GetDistanceToVilla();
                    }
                    else
                    {
                        distanceTravelled += distIt.key();
                    }
                    qDebug() << "DIST TRAV - ADDED: " << distIt.key();
                    qDebug() << "DIST TRAV - AFTER: " << distanceTravelled;


                    // PREP FOR ADDING TO LIST.. MAKE SURE WE DON'T ADD TWICE
                    bool wineryExists = false;
                    QList<Winery>::iterator iterator = shortestPathList.begin();
                    while (iterator != shortestPathList.end() && !wineryExists)
                    {
                        if (  (*iterator).GetWineryNum() == currentWinery.GetWineryNum()
                            &&(*iterator).GetName()      == currentWinery.GetName())
                        {
                            wineryExists = true;
                        }
                        else
                        {
                            iterator++;
                        }
                    }

                    // add to list if winery does not already exist in the list
                    if (!wineryExists)
                    {
                        qDebug() << "ADDING TO LIST: " << currentWinery.GetName();
                        shortestPathList.push_back(currentWinery);
                    }


                    // update new current winery
                    currentWinery = tempWineryList[wineryNum];

                    notFound = false;
                }
                else
                {
                    distIt++;
                }
            }

            // if END of iteration, the last winery distance will indicate
            // that nothing was found, so push back that winery, and add it's
            // distance from the Villa (since we're going back to the Villa)
            if (notFound)
            {
                // PREP FOR ADDING TO LIST.. MAKE SURE WE DON'T ADD TWICE
                bool wineryExists = false;
                QList<Winery>::iterator iterator = shortestPathList.begin();
                while (iterator != shortestPathList.end() && !wineryExists)
                {
                    if (  (*iterator).GetWineryNum() == currentWinery.GetWineryNum()
                        &&(*iterator).GetName()      == currentWinery.GetName())
                    {
                        wineryExists = true;
                    }
                    else
                    {
                        iterator++;
                    }
                }

                // add to list if winery does not already exist in the list
                if (!wineryExists)
                {
                    qDebug() << "ADDING TO LIST: " << currentWinery.GetName();
                    shortestPathList.push_back(currentWinery);
                    distanceTravelled += currentWinery.GetDistanceToVilla();

                }

            }

            index++;

            // if shortest trip, then user has selected
            // number of wineries to visit. Make sure
            // not to exceed this number
            if (shortestTrip && wineriesToVisit != 0)
            {
                loopCondition = (index < size && index < wineriesToVisit);
            }
            else
            {
                loopCondition = (index < size);
            }
        }

    }
    else
    {
        QMessageBox::information(this, "Error", "Empty List, cannot perform any shortest path!");
    }

}


Winery MainWindow::closestToVilla(QMap<int, Winery>& localWineryList)
{
    // store lowest distance in this var
    int lowest;
    // stores temporary distance
    int temp;
    // stores index
    int index;


    lowest = 10000000; // some arbritary lowest value
    index = 1;  // if error, returns winery at index 1

    // traverse map from 1 to size. O(n)
    for (int traverse = 1; traverse < wineryList.size(); traverse++)
    {
        if (localWineryList.contains(traverse))
        {
            temp = localWineryList[traverse].GetDistanceToVilla();
            // if we find a lower distance, set to new lowest distance
            if (temp < lowest)
            {
                // update lowest and index
                lowest = temp;
                index = traverse;
            }

            }
        // else, check next iteration

    }

    // at the end of the loop, we should have the lowest/closest distance
    // to the Villa. Return that index.

    qDebug() << "INDEX BEFORE RETURN: " << index;
    qDebug() << "WINERY NAME BEFORE RETURN " << localWineryList[index].GetName();
    return localWineryList[index];

}

void MainWindow::on_shortest_trip_clicked()
{
    ui->page_plan_day_trip->hide();
    ui->page_shortest_trip->show();

    QRadioButton *radioButton;
    QVBoxLayout *radioLayout = new QVBoxLayout();

    ui->selectWineryLabel->setText("Slect the beginning winery");
    ui->selectWineryLabel->setStyleSheet("font: 16pt;");

    for (QMap<int, Winery>::iterator it = wineryList.begin()+1; it != wineryList.end(); it++)
    {
        radioButton = new QRadioButton(it.value().GetName());
        radioLayout->addWidget(radioButton);
        wineryRadioButtonList.push_back(radioButton);
    }

    ui->radio_button_scroll_area->setLayout(radioLayout);
}

void MainWindow::on_custom_trip_clicked()
{
    ui->page_plan_day_trip->hide();
    ui->customt_trip->show();

    QCheckBox *customList;
    QVBoxLayout *customLayout = new QVBoxLayout();

    QList<Winery>       wineries;
    float               totalDist       = 0.0;
    QMap<int, Winery>*  customWineryList= NULL;

    for (int m=1; m<wineryList.size(); m++)
    {
       customList = new QCheckBox(wineryList[m].GetName());
       customLayout->addWidget(customList);
       wineries.push_back(wineryList[m]);
    }

    ui->selectWineryLabel_2->setText("Slect the wineries");
    ui->selectWineryLabel_2->setStyleSheet("font: 16pt;");
    ui->scrollAreaWidgetContents_3->setLayout(customLayout);

    /************** TEMP VALUES TESTING ******************/
    // add 4 random wineries to visit.
    customWineryList = new QMap<int, Winery>;

    customWineryList->insert(3, this->wineryList[3]);
    customWineryList->insert(10, this->wineryList[10]);
    customWineryList->insert(2, this->wineryList[2]);
    customWineryList->insert(7, this->wineryList[7]);

    /*****************************************************/

    // return shortest path of wineries, total distance traversed.

    /* CUSTOM TRIP */
    ShortestPath(wineries,
                 totalDist,
                 false,             // NOT shortest trip
                 NULL,              // no specified data
                 0,                 // no specified data
                 true,              // YES custom Trip
                 customWineryList); // specified winery list to traverse


    qDebug() << "\n\n\n OUTPUTTING CUSTOM TRIP PATH\n";
    qDebug() << "TOTAL DISTANCE IS: " << totalDist;
    for (QList<Winery>::iterator it = wineries.begin(); it != wineries.end(); it++)
    {
        qDebug() << "WINERY NUMBER " << (*it).GetWineryNum();
    }

    delete customWineryList;

}



void MainWindow::on_addToCart_clicked()
{
    QWidget *cartWidget = new QWidget();
    QVBoxLayout *cartLayout = new QVBoxLayout();
    bool atLeastOnce = false;
    QCheckBox   *temp;

    for(int count = 0; count < wineCheckBoxList1.size(); count++)
    {

        if(wineCheckBoxList1.at(count)->isChecked())
        {
                temp = new QCheckBox(wineCheckBoxList1.at(count)->text());
                cartList.push_back(temp);
                cartPrices.push_back(winePrices.at(count));

           atLeastOnce = true;

        }

        wineCheckBoxList1.at(count)->setChecked(false);
    }


    if (atLeastOnce)
    {

        for(int numCheckBox = 0; numCheckBox < cartList.size(); numCheckBox++)
        {
           cartLayout->addWidget(cartList.at(numCheckBox));
        }

        cartWidget->setLayout(cartLayout);
        ui->scrollArea_2->setWidget(cartWidget);

        total = 0;
        for(int g=0; g<cartPrices.size();g++)
        {
            total = total + cartPrices.at(g);
        }
        qDebug() << "total: " + QString::number(total);
        qDebug() << "size: " << cartPrices.size();

        ui->subtotal->setText("Total: $" + QString::number(total));
    }



}


void MainWindow::on_removeFromCart_clicked()
{
    QWidget *cartWidgetUpdated = new QWidget();
    QVBoxLayout *cartLayoutUpdated = new QVBoxLayout();
    bool atLeastOnce = false;

    for(int i = 0; i < cartList.size(); i++)
    {
       if(cartList.at(i)->isChecked())
       {
           atLeastOnce = true;
           cartList.remove(i);
           cartPrices.removeAt(i);
           i--;         
       }

    }

     if(atLeastOnce)
     {
         for(int j = 0; j < cartList.size(); j++)
         {
             cartLayoutUpdated->addWidget(cartList.at(j));
         }


         cartWidgetUpdated->setLayout(cartLayoutUpdated);
         ui->scrollArea_2->setWidget(cartWidgetUpdated);

         total = 0;
         for(int g=0; g<cartPrices.size();g++)
         {
             total = total + cartPrices.at(g);
         }

         ui->subtotal->setText("Total: $" + QString::number(total));
     }
}


void MainWindow::on_goBack_clicked()
{
    ui->customt_trip->hide();
    ui->page_plan_day_trip->show();
}

void MainWindow::updateWineryTableItems()
{
    static int row = 0;

    for(int index = 1; index < wineryList.size(); index++)
    {
        if(ui->wineryTable->rowCount() < row + 1)
        {
            ui->wineryTable->setRowCount(row + 1);
        }

        Winery item = wineryList.operator [](index);

        QStringList itemList;
        itemList << item.GetName();
        itemList.append((new QString())->setNum(item.GetDistanceToVilla()));

        for(int column = 0; column < 2; column++){
            QTableWidgetItem *newItem = new QTableWidgetItem(itemList.at(column));
            ui->wineryTable->setItem(row, column, newItem);
        }
        row++;
    }
    row = 0;
}

void MainWindow::updateWineTableItems()
{
    static int row = 0;
    QMap<QString, Wine>::Iterator it;
    it = wineryObject->GetWines().begin();

    for(int index = 0; index < wineryObject->GetWines().size(); index++)
    {        
        if(ui->WineTable->rowCount() < row + 1)
        {
            ui->WineTable->setRowCount(row + 1);
        }

        Wine item = *it;

        QStringList itemList;
        QString out[2];
        out[0].setNum(item.GetYear());
        out[1].setNum(item.GetPrice());
        itemList << (QString)item.GetName() << out[0] << out[1];

        for(int column = 0; column < 3; column++){
            QTableWidgetItem *newItem = new QTableWidgetItem(itemList.at(column));
            ui->WineTable->setItem(row, column, newItem);
        }
        row++;
        it++;
    }
    row = 0;
}

void MainWindow::on_wineryTable_itemClicked(QTableWidgetItem *item)
{
    selectedWinery = item;
}

//login->addWinery
void MainWindow::on_addNewWinery_clicked()
{
    ui->page_admin_login_success->hide();
    ui->page_admin_login->hide();

    ui->AddWinery->show();
}

//back from add new winery
void MainWindow::on_pushButton_6_clicked()
{
    ui->addNewWinery->hide();
    ui->stackedWidget->currentWidget()->hide();

    ui->page_admin_login_success->show();
}

//login to edit winery
void MainWindow::on_addNew_2_clicked()
{
    ui->page_admin_login->hide();
    ui->page_admin_login_success->hide();

    ui->EditWinery->show();
}

//back from edit winery
void MainWindow::on_pushButton_7_clicked()
{
     ui->stackedWidget->currentWidget()->hide();
     ui->EditWinery->hide();

     ui->page_admin_login->show();
     ui->page_admin_login_success->show();
}

//Edit to specific edit
void MainWindow::on_pushButton_3_clicked()
{
    ui->EditWinery->hide();
    ui->stackedWidget->currentWidget()->hide();

    ui->EditSpecificWinery->show();
}

//Add winery to add new wines in that winery
void MainWindow::on_AddWineryButton_clicked()
{
    if (!(ui->addWineryName->text() == "" || ui->addWineryNum->text() == "" || ui->addWineFrmVilla->text() == ""))
    {

        Winery *temp = new Winery();
        temp->SetName(ui->addWineryName->text());
        temp->setDistanceToVilla(ui->addWineFrmVilla->text().toFloat());
        temp->SetWineryNum(wineryList.last().GetWineryNum() + 1);

        wineryObject = temp;

        ui->addWineryName->clear();
        ui->addWineFrmVilla->clear();
        ui->addWineryNum->clear();

        ui->AddWinery->hide();

        ui->pageDistanceTo->show();
        ui->DistanceWineryName->setText(wineryList.operator [](wineryNum).GetName());
        ui->DistanceToWinery->setFocus();
    }
}

//back from add new winery
void MainWindow::on_backAddWinery_clicked()
{
    ui->AddWinery->hide();
    ui->page_admin_login->hide();
    ui->page_admin_login_form->hide();
    ui->stackedWidget->currentWidget()->hide();

    ui->page_admin_login->show();

    ui->page_admin_login_success->setHidden(false);
    ui->page_admin_login_success->show();
}

void MainWindow::on_AddWinesBack_clicked()
{
    ui->AddWines->hide();
    ui->stackedWidget->currentWidget()->hide();
    delete wineryObject;
    wineryObject = NULL;

    ui->AddWinery->show();
}

//back from edit specific
void MainWindow::on_pushButton_2_clicked()
{
    ui->EditSpecificWinery->hide();
    ui->stackedWidget->currentWidget()->hide();

    ui->EditWinery->show();
}

//edit wine in specific winery
void MainWindow::on_pushButton_4_clicked()
{
    ui->EditSpecificWinery->hide();
    ui->stackedWidget->currentWidget()->hide();

    ui->EditWine->show();
}


//back from edit wine to edit specific
void MainWindow::on_pushButton_8_clicked()
{
    ui->EditWine->hide();
    ui->stackedWidget->currentWidget()->hide();

    ui->EditSpecificWinery->show();
}


void MainWindow::on_AddWine_clicked()
{
    wineObject->SetName(ui->addWineName->text());
    wineObject->SetYear(ui->addWineYear->text().toInt());
    wineObject->SetPrice(ui->addWinePrice->text().toFloat());

    wineryObject->AddWine(*wineObject);
    ui->AddWines->hide();

    QStringList headers;
    headers << "Name" << "Year" << "Price";

    ui->WineTable->setShowGrid(true);
    ui->WineTable->setColumnCount(3);
    ui->WineTable->setRowCount(0);
    ui->WineTable->setHorizontalHeaderLabels(headers);
    ui->WineTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    updateWineTableItems();

    ui->AddWines->show();

    ui->addWineName->clear();
    ui->addWineYear->clear();
    ui->addWinePrice->clear();
}

void MainWindow::on_doneAddWine_clicked()
{
    wineryList.insert(wineryObject->GetWineryNum(),*wineryObject);
    for (int index = 1; index < wineryList.size()-1; index++)
    {
        wineryList[index].AddDistance(wineryObject->GetWineryNum(), wineryObject->GetDistances().values().at(index));
    }
    ui->AddWines->hide();
    ui->page_admin_login->show();
    ui->page_admin_login_success->show();
    wineryObject = NULL;
}

void MainWindow::on_NextToAddWine_clicked()
{
    if (wineryNum < wineryObject->GetWineryNum() && ui->DistanceToWinery->text() != "")
    {
        wineryObject->AddDistance(wineryNum,ui->DistanceToWinery->text().toFloat());

        wineryNum++;
        ui->DistanceToWinery->setFocus();
    }

    if (wineryNum >= wineryObject->GetWineryNum())
    {
        ui->pageDistanceTo->hide();
        ui->page_admin_login->hide();
        wineryNum = 1;
        wineryObject->AddDistance(wineryObject->GetWineryNum(),0.0);

        QStringList headers;
        headers << "Name" << "Year" << "Price";

        ui->WineTable->setShowGrid(true);
        ui->WineTable->setColumnCount(3);
        ui->WineTable->setRowCount(0);
        ui->WineTable->setHorizontalHeaderLabels(headers);
        ui->WineTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        updateWineTableItems();

        ui->AddWines->show();
    }
    ui->DistanceWineryName->setText(wineryList.operator [](wineryNum).GetName());
    ui->DistanceToWinery->clear();
}

void MainWindow::on_BacktoAddWinery_clicked()
{
    ui->DistanceToWinery->clear();
    wineryNum = 1;
    ui->pageDistanceTo->hide();
    ui->AddWinery->show();
}

void MainWindow::on_startShortest_clicked()
{
    QList<Winery>       wineries;
    float               totalDist       = 0.0;
    Winery*             beginningWinery = NULL;
    bool checked = false;
    int wineriesToVisit = 0;

    for(int i = 0; i < wineryRadioButtonList.size();i++)
    {
        if(wineryRadioButtonList.at(i)->isChecked())
        {
            checked = true;
            beginningWinery = &(this->wineryList[i+1]);
            qDebug() << "beginning winery: " << beginningWinery->GetName();
        }
    }

    if(checked)
    {
        wineriesToVisit = QInputDialog::getInt(this, "Number of Wineries","Enter the number of wineries to visit", 0, 1 , wineryRadioButtonList.size());
        ui->page_shortest_trip->hide();

        // return shortest path of wineries, total distance traversed.
            /* SHORTEST TRIP*/
            ShortestPath(wineries,
                         totalDist,
                         true,                  // YES shortest trip
                         beginningWinery,       // specified winery to begin
                         wineriesToVisit,       // specified number of wineries to visit
                         false,                 // NOT custom Trip
                         NULL);                 // no specified data



            qDebug() << "\n\n\n OUTPUTTING SHORTEST TRIP PATH\n";
            qDebug() << "TOTAL DISTANCE IS: " << totalDist;
            for (QList<Winery>::iterator it = wineries.begin(); it != wineries.end(); it++)
            {
                qDebug() << "WINERY NUMBER " << (*it).GetWineryNum();
            }


    }
    else
    {
        QMessageBox::information(this,"Error", "Select the beginning winery");

    }







}
