#include "orderproduct.h"
#include "ui_orderproduct.h"

OrderProduct::OrderProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderProduct)
{
    ui->setupUi(this);

//    connect(this, SIGNAL(helpOrderChanged(QString&)), parent, SLOT(changeOrderText(QString&)));
}

OrderProduct::~OrderProduct()
{
    delete ui;
}

void OrderProduct::editText()
{
    ui->OrderingAProduct->setReadOnly(true);
}

//QString OrderProduct::on_OrderingAProduct_textChanged()
//{
//        QString newText;

//        newText = ui->OrderingAProduct
//        emit helpOrderChanged();
//}
