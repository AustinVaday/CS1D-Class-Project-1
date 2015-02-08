#ifndef REQUESTBROCHURE_H
#define REQUESTBROCHURE_H

#include <QDialog>

namespace Ui {
class RequestBrochure;
}

class RequestBrochure : public QDialog
{
    Q_OBJECT

public:
    explicit RequestBrochure(QWidget *parent = 0);
    ~RequestBrochure();
    void editText();

private:
    Ui::RequestBrochure *ui;
};

#endif // REQUESTBROCHURE_H
