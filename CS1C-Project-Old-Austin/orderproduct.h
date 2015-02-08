#ifndef ORDERPRODUCT_H
#define ORDERPRODUCT_H

#include <QDialog>

namespace Ui {
class OrderProduct;
}

class OrderProduct : public QDialog
{
    Q_OBJECT

public:
    explicit OrderProduct(QWidget *parent = 0);
    ~OrderProduct();

    void editText();

signals:
//    void helpOrderChanged();

private slots:
//   void on_OrderingAProduct_textChanged();

        private:
    Ui::OrderProduct *ui;
};

#endif // ORDERPRODUCT_H
