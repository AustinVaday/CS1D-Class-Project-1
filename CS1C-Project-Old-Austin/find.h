#ifndef FIND_H
#define FIND_H

#include <QDialog>

namespace Ui {
class Find;
}

class Find : public QDialog
{
    Q_OBJECT

public:
    explicit Find(QWidget *parent = 0);
    ~Find();
    QString return_searched_name();


private slots:
    void on_buttonBox_accepted();

private:
    Ui::Find *ui;
    QString findText;
};

#endif // FIND_H
