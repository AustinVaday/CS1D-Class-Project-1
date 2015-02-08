#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include "helpwindow.h"
#include "newactivatedlist.h"

namespace Ui {
class AdminWindow;

}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = 0);
    AdminWindow(QWidget *parent , CustomerList &list);

    ~AdminWindow();

signals:
    void clicked();
    void adminAccess();
    void customerListChanged(CustomerList* list);

public slots:
    void on_modify_help_options_clicked();
    void updateCustomerList(CustomerList *list);

private slots:
    void on_back_button_clicked();
    void on_view_activated_customers_clicked();
    void on_actionHelp_triggered();

private:

	Ui::AdminWindow  *ui;

    NewActivatedList *viewList;
	CustomerList	  customerList;
};

#endif // ADMINWINDOW_H
