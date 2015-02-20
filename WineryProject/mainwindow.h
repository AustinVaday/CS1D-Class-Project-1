#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "helpwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QQueue>
#include "Wine.h"
#include "Winery.h"
#include "SortedList.h"

//cool
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

private:
    Ui::MainWindow *ui;
    HelpWindow *helpWindow;
    char userType; //'c' for customer, 'a' for admin, 'n' for none(no login made)
    bool ReadFromFile();
    bool WriteToFile();


};

#endif // MAINWINDOW_H
