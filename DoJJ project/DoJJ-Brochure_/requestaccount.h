#ifndef REQUESTACCOUNT_H
#define REQUESTACCOUNT_H

#include <QDialog>
#include "sortedlist.h"

namespace Ui {
class RequestAccount;
}

class RequestAccount : public QDialog
{
    Q_OBJECT

public:
    explicit RequestAccount(QWidget *parent = 0);


    ~RequestAccount();

private slots:
    void on_Cancel_clicked();
    void on_Confirm_clicked();

private:
    Ui::RequestAccount *ui;
    //Sorted list
    SortedList<Customer<QString>, QString> customerList;
    SortedList<Customer<QString>, QString> pendingAccList;

};

#endif // REQUESTACCOUNT_H
