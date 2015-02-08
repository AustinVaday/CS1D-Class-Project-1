
#ifndef GUESTWINDOW_H
#define GUESTWINDOW_H

#include <QMainWindow>
#include "guarantee.h"
#include "sellpoint.h"
#include "environments.h"
#include "conceptofops.h"

namespace Ui {
class GuestWindow;
}

class GuestWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GuestWindow(QWidget *parent = 0);
    ~GuestWindow();

private slots:
    void on_guaranteeButton_clicked();

    void on_sellButton_clicked();

    void on_EnviroButton_clicked();

    void on_ConceptOps_clicked();

private:
    Ui::GuestWindow *ui;
};

#endif // GUESTWINDOW_H
