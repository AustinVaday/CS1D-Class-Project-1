#ifndef ACTIVATEDLIST2_H
#define ACTIVATEDLIST2_H

#include <QDialog>

namespace Ui {
class ActivatedList2;
}

class ActivatedList2 : public QDialog
{
    Q_OBJECT

public:
    explicit ActivatedList2(QWidget *parent = 0);
    ~ActivatedList2();

private slots:
    void on_listWidget_activated(const QModelIndex &index);

private:
    Ui::ActivatedList2 *ui;
};

#endif // ACTIVATEDLIST2_H
