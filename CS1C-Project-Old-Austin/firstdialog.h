#ifndef FIRSTDIALOG_H
#define FIRSTDIALOG_H

#include <QDialog>

namespace Ui {
class FirstDialog;
}

class FirstDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FirstDialog(QWidget *parent = 0);
    ~FirstDialog();

signals:
    void adminAcces();

public slots:
    void editText();


private:
    Ui::FirstDialog *ui;
    bool    editPermission;

};

#endif // FIRSTDIALOG_H
