#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "helpwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QCheckBox>
#include "Winery.h"
#include <QVBoxLayout>
#include <QRadioButton>


/* The following header files are included
 * in other header files...*/
#include <QDir>
//#include <QFile>
//#include <QQueue>
//#include "Wine.h"
//#include "SortedList.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void setUser(char type);
    char getUser();

    ~MainWindow();

private slots:
    void on_actionHelp_triggered();

    void on_quitButton_clicked();

    void on_adminLogButton_clicked();

    void on_viewListWineriesButton_clicked();

    void on_planDayTripButton_clicked();

    void on_tourWineriesButton_clicked();


    void on_admin_log_ok_button_clicked();

    void on_adming_log_cancel_button_clicked();

    void on_admin_log_out_button_clicked();

    void on_ViewBack_clicked();

    void on_PlanTripBack_clicked();

    void on_TourBack_clicked();

    void on_LogInBack_clicked();


    // The following methods are not defined in mainwindow.cpp
    // If you do not define them in mainwindow.cpp, you will get
    // an Architecture x86 error.

//    void on_listView_activated(const QModelIndex &index);

//    void on_listWidget_2_activated(const QModelIndex &index);


//    void on_page_view_list_wineries_destroyed();

//    void on_scrollArea_destroyed();

//    void on_pushButton_2_clicked();

    void on_passwordLine_returnPressed();

    void on_plan_trip_submit_button_clicked();

//    void on_pushButton_3_clicked();

    void on_visit_all_clicked();

    void on_backToTripType_clicked();

//    void on_TourBack_2_clicked();

    void on_next_clicked();

    /* READ THE SIDE-DOCUMENTATION. !IMPORTANT SEMANTICS! */
    void ShortestPath
 (QList<Winery>&        shortestPathList,   // the resulting shorted path
  float&                distanceTravelled,  // the total distance travelled
  bool                  shortestTrip,       // For shortest trip, you will need to enter data in for:
                                            //      --> beginningWinery
                                            //      --> wineriesToVisit
                                            // and let the rest be as follows
                                            //      --> customTrip : false
                                            //      --> customWineryList : NULL
  const Winery*         beginningWinery,        // CONST ptr so that cannot change the winery
  int                   wineriesToVisit,
  bool                  customTrip,         // For custom trip, you will need to enter data in for:
                                            //      --> customerWineryList
                                            // and let the rest be as follows
                                            //      --> wineriesToVisit : 0
                                            //      --> shortestTrip : false
                                            //      --> beginningWinery : NULL

  QMap<int,Winery>*   customWineryList);   // Map for CUSTOM TRIP


    Winery closestToVilla(QMap<int, Winery>& localWineryList);

    void on_shortest_trip_clicked();

    void on_custom_trip_clicked();


    void on_next_2_clicked();

    void on_prev_winery_clicked();

    void on_addToCart_clicked();

    void on_goBack_clicked();

private:
    Ui::MainWindow *ui;
    HelpWindow *helpWindow;
    char userType; //'c' for customer, 'a' for admin, 'n' for none(no login made)
    bool ReadFromFile();
    bool WriteToFile();
    QList<QWidget*> scrollAreaList;
    QVector<QCheckBox*> wineCheckBoxList1;
    QList<QCheckBox*> wineCheckBoxCartList;
    QList<QRadioButton*> wineryRadioButtonList;
    QList<QString> names;
//    SortedList<Winery, float> wineryList;   // sort wineries by distance to VILLA
    QMap<int, Winery> wineryList;              // sort wineries by winery number
    Wine    *wineObject = NULL;
    Winery  *wineryObject = NULL;
    int wineryNum = 1;
};

#endif // MAINWINDOW_H
