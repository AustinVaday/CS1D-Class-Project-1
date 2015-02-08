#include "ViewProducts.h"
#include "ui_ViewProducts.h"
#include <QMessageBox>


ViewProducts::ViewProducts(QWidget *parent):
    QWidget(parent),
    ui(new Ui::ViewProducts)
{
    ui->setupUi(this);
    scWindow = new ShoppingCartWindowNew;
}


ViewProducts::ViewProducts(QWidget *parent, ProductList &robotList, ProductList &shoppingCartList)
 :
    QWidget(parent),
    ui(new Ui::ViewProducts)
{

    connect(this, SIGNAL(signal_updated_shopping_list(ProductList&)), parent, SLOT(on_updated_shopping_list(ProductList &)));

    roboList = robotList;

    ui->setupUi(this);

    ui->text1->insertPlainText(robotList[0]);

    ui->text2->insertPlainText(robotList[1]);

    ui->text3->insertPlainText(robotList[2]);

    scWindow = new ShoppingCartWindowNew();
    Product robo3("Soviet Attackers", "if cold war ever happens again robot is very efficient\nmade special to detect Soviet threats\ncan transmit video and audio", 500.56, 234, 81285);
    ui->text3->insertPlainText(robo3.OutputData());
}

ViewProducts::~ViewProducts()
{
    delete ui;

    delete scWindow;
}


void ViewProducts::on_updated_shopping_list(ProductList &ShoppingCartList)
{

    shoppingCartList = ShoppingCartList;

    emit signal_updated_shopping_list(shoppingCartList);
}

void ViewProducts::on_MaintPlan_clicked()
{
    MaintPlan mWindow;

    mWindow.setModal(true);
    mWindow.exec();
}


//Product Buttons ok
void ViewProducts::on_product_One_clicked()
{

    Product data;

    data = roboList.FindProduct("Meowzers");

    if (!shoppingCartList.isExist(data))
    {
        shoppingCartList.Enqueue(data);

        emit signal_updated_shopping_list(shoppingCartList);
    }
    else
    {
        QMessageBox::information(this,"Error" ,"Already in your shopping cart!");
    }

}
void ViewProducts::on_product_Two_clicked()
{
    Product data;

    data = roboList.FindProduct("iRobot 6000");

    if (!shoppingCartList.isExist(data))
    {
        shoppingCartList.Enqueue(data);

        emit signal_updated_shopping_list(shoppingCartList);
    }
    else
    {
        QMessageBox::information(this,"Error" ,"Already in your shopping cart!");
    }
}

void ViewProducts::on_product_Three_clicked()
{
    Product data;

     data = roboList.FindProduct("Soviet Attackers");

     if (!shoppingCartList.isExist(data))
     {
         shoppingCartList.Enqueue(data);

         emit signal_updated_shopping_list(shoppingCartList);
     }
     else
     {
         QMessageBox::information(this,"Error" ,"Already in your shopping cart!");
     }

}

void ViewProducts::on_checkout_button_clicked()
{

    if (shoppingCartList.isEmpty())
    {
        QMessageBox::information(this,"Error" ,"Nothing in cart");

    }
    else
    {
        delete scWindow;

        scWindow = new ShoppingCartWindowNew(this, roboList, shoppingCartList);

        scWindow->show();
    }

}
