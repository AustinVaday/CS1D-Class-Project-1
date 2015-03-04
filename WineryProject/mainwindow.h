#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "helpwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QCheckBox>
#include "Winery.h"
#include <QVBoxLayout>

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

private:
    Ui::MainWindow *ui;
    HelpWindow *helpWindow;
    char userType; //'c' for customer, 'a' for admin, 'n' for none(no login made)
    bool ReadFromFile();
    bool WriteToFile();
    QList<QVBoxLayout*> wineryLayoutList;
    QList<QCheckBox*> wineCheckBoxList1;
    QList<QCheckBox*> wineryCheckBoxList1;
//    SortedList<Winery, float> wineryList;   // sort wineries by distance to VILLA
    QMap<float, Winery> wineryList; // sort wineries by distance to VILLA
    Wine    *wineObject = NULL;
    Winery  *wineryObject = NULL;
};

#endif // MAINWINDOW_H
