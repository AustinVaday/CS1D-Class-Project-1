#ifndef NEWACTIVATEDLIST_H
#define NEWACTIVATEDLIST_H

//#include <QDialog>
#include <QListWidgetItem>
// #include <QObject>
#include "customeraddressbook.h"
#include "customerlistclass.h"

namespace Ui {
class NewActivatedList;
}

class NewActivatedList : public QDialog
{
    Q_OBJECT

public:
    explicit NewActivatedList(QWidget *parent = 0);
    NewActivatedList(QWidget *parent, CustomerList &list);

    ~NewActivatedList();

    void DisplayTheList(const CustomerList& list);

    int UpdateNumDeactivatedCustomers();
    int UpdateNumActivatedCustomers();

signals:

    void customerListChanged(CustomerList* list);

public slots:
//    void on_listItem_clicked(QListWidgetItem* item);
    void updateCustomerList(CustomerList *list);


private slots:
    void on_addCustomer_clicked();

//    void on_addToActivatedListButton_clicked();

    void on_addToDeactivatedListButton_clicked();


    void on_addToActivatedListButton_clicked();

    void on_masterModeButton_clicked();

private:
    Ui::NewActivatedList *ui;
    CustomerList customerList;
    CustomerAddressBook *custAddBook;
};

#endif // NEWACTIVATEDLIST_H
