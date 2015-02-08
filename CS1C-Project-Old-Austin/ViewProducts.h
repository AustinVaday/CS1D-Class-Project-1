#ifndef VIEWPRODUCTS_H
#define VIEWPRODUCTS_H

#include <QWidget>
#include "ProductClass.h"
#include "ProductListClass.h"
#include "ImageViewer.h"
#include "maintplan.h"
#include "ShoppingCartWindowNew.h"

namespace Ui {
class ViewProducts;
}

class ViewProducts : public QWidget
{
    Q_OBJECT

public:
    explicit ViewProducts(QWidget *parent = 0);
    ViewProducts(QWidget *parent, ProductList &robotList, ProductList &shoppingCartList);



    ~ViewProducts();
signals:

    void signal_updated_shopping_list(ProductList &shoppingCartList);

public slots:
    void on_updated_shopping_list(ProductList &ShoppingCartList);

private slots:


    void on_MaintPlan_clicked();

    void on_product_One_clicked();

    void on_product_Two_clicked();

    void on_product_Three_clicked();

    void on_checkout_button_clicked();

private:
    Ui::ViewProducts *ui;
    ImageViewer* image1;
    ProductList shoppingCartList;
    ProductList roboList;
    ShoppingCartWindowNew *scWindow;

};

#endif // VIEWPRODUCTS_H
