#ifndef BROCHUREWINDOW_H
#define BROCHUREWINDOW_H

#include <QMainWindow>
#include "ProductClass.h"
#include "ProductListClass.h"
#include "ViewProducts.h"
#include "ImageViewer.h"

namespace Ui {
class BrochureWindow;
}

class BrochureWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BrochureWindow(QWidget *parent = 0);
    ~BrochureWindow();

signals:
    void clicked();

    void viewProducts();

public slots:
    void on_updated_shopping_list(ProductList &ShoppingCartList);


private slots:
    void on_actionHELP_triggered();

    void on_button_viewProducts_clicked();

    void on_button_logout_clicked();

private:

    //Annie declares the objects individually wihtin the view product window
    // lol, i just realized that you don't need a shoppingCartList, it's just
    // another form of a product list....
    //haha yeah youre right
    //dang

    //tehe sorry
    ProductList shoppingCartList;
    ProductList robotList;
    Ui::BrochureWindow* ui;
    ViewProducts*       vpWindow;
    ImageViewer*        image;
};

#endif // BROCHUREWINDOW_H
