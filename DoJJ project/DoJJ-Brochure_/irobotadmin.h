#ifndef IROBOTADMIN_H
#define IROBOTADMIN_H
#include "ui_irobotadmin.h"
#include "sortedlist.h"
#include "customer.h"
#include "admin.h"
#include <QString>
#include <QMainWindow>
#include <QFile>
#include <QStringList>
#include <QWidgetList>
#include <QWidget>
#include <QTextStream>
#include <QMessageBox>

namespace Ui {
class irobotAdmin;
}

class irobotAdmin : public QMainWindow
{
    Q_OBJECT

public:
    // Default constructor
    explicit irobotAdmin(QWidget *parent = 0);
    explicit irobotAdmin(QWidget *parent, Admin* admin);
    // Destructor
    ~irobotAdmin();
    int  GetRow();
    void AddRow();
    void DeleteRow();
    // Function Adds Items to the table
    void addTableItems();
    // Function Deletes All table items
    void deleteTableItems();
    // Function to set the list
    void SetCustomerList();
    // Function to update list (Wrapper w/ extra check)
    void UpdateCustomerList();
    Ui::irobotAdmin *GetUI();

private slots:
    // Function triggered when logout action is pressed
    void on_actionLog_out_triggered();

    // Function triggered when quit action is pressed
    void on_actionQuit_triggered();

    // Function triggered when printList button is pressed
    void on_printList_clicked();

    // Function triggered when editList button is pressed
    void on_editList_clicked();

    // Function triggered when deleteMessage button is pressed
    void on_deleteMessage_clicked();

    // Function triggered when approveTestimonial button is pressed
    void on_approveTestimonial_clicked();

    // Function triggered when help action is pressed
    void on_actionUser_Guide_triggered();

    // Function triggered when add item to table is pressed
    void on_updateTable_triggered();

    void on_contactUsList_itemClicked(QListWidgetItem *item);

    void on_testiList_itemClicked(QListWidgetItem *item);

    void on_approveButton_clicked();

    void on_denyButton_clicked();

    void on_listWidget_2_itemClicked(QListWidgetItem *item);

    void on_approveTestimonial_2_clicked();

private:
    Ui::irobotAdmin *ui;
    Admin* admin;
    int    row;
    SortedList<contactUsInfo,QString> contactUsList;
    SortedList<Customer<QString>,QString> customerList;
    SortedList<Customer<QString>,QString> pendingCustomerList;
    SortedList<testiInfo,QString> testiList;
};

#endif // IROBOTADMIN_H
