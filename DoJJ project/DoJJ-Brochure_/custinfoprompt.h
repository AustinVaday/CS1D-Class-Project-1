#ifndef CUSTINFOPROMPT_H
#define CUSTINFOPROMPT_H

#include "customer.h"
#include "sortedlist.h"
#include "admin.h"
#include "irobotadmin.h"
#include <QString>
#include <QDialog>

namespace Ui {
class CustInfoPrompt;
}

class CustInfoPrompt : public QDialog
{
    Q_OBJECT

public:
    explicit CustInfoPrompt(QWidget *parent = 0);
    explicit CustInfoPrompt(QWidget *parent, Admin* newAdmin);
    ~CustInfoPrompt();

signals:
    void changeSuccess();

private slots:
    void on_Cancel_clicked();

    void on_Add_clicked();

    void on_Remove_clicked();

    void on_Edit_clicked();

private:
    Ui::CustInfoPrompt *ui;
    Admin* admin;
    SortedList<Customer<QString>, QString> customerList;
};

#endif // CUSTINFOPROMPT_H
