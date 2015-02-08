#ifndef CUSTOMERPLACEORDER_H
#define CUSTOMERPLACEORDER_H

#include <QWidget>

namespace Ui {
class CustomerPlaceOrder;
}

class CustomerPlaceOrder : public QWidget
{
    Q_OBJECT

public:
    explicit CustomerPlaceOrder(QWidget *parent = 0);
    ~CustomerPlaceOrder();

private:
    Ui::CustomerPlaceOrder *ui;
};

#endif // CUSTOMERPLACEORDER_H
