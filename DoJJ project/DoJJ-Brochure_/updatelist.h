#ifndef UPDATELIST_H
#define UPDATELIST_H

#include <QDialog>

namespace Ui {
class UpdateList;
}

class UpdateList : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateList(QWidget *parent = 0);
    ~UpdateList();

private slots:

    void on_AddCustomer_clicked();

    void on_RemoveCust_clicked();

private:
    Ui::UpdateList *ui;
};

#endif // UPDATELIST_H
