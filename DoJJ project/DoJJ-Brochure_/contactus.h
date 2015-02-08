#ifndef CONTACTUS_H
#define CONTACTUS_H

#include <QWidget>
#include "sortedlist.h"

namespace Ui {
class contactUs;
}

class contactUs : public QWidget
{
    Q_OBJECT

public:
    // Default constructor
    explicit contactUs(QWidget *parent = 0);
    // Destructor
    ~contactUs();

private slots:
    // Function triggered when send button is pressed
    void on_send_clicked();

    void on_cancel_clicked();

private:
    Ui::contactUs *ui;
    SortedList<contactUsInfo, QString> contactUsList;
};

#endif // CONTACTUS_H
