#ifndef ACTIVATEDLIST_H
#define ACTIVATEDLIST_H

#include <QDialog>

namespace Ui {
class ActivatedList;
}

class ActivatedList : public QDialog
{
    Q_OBJECT

public:
    explicit ActivatedList(QWidget *parent = 0);
    ~ActivatedList();

private slots:
    void on_listWidget_activated(const QModelIndex &index);

private:
    Ui::ActivatedList *ui;
};

#endif // ACTIVATEDLIST_H
