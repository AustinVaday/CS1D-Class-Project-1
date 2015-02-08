#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QWidget>

namespace Ui {
class HelpWindow;
}

class HelpWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HelpWindow(QWidget *parent = 0);
    ~HelpWindow();


   void editText();


signals:
    void clicked();

public slots:

//    void changeOrderText(QString);

   void on_LoginHelp_clicked();

private slots:
   void on_CreatingAnAccount_clicked();

   void on_HowToOrderAProduct_clicked();

   void on_RequestingABrochure_clicked();

   void on_NavigatingApp_clicked();

private:
    Ui::HelpWindow *ui;
    bool edit;
};

#endif // HELPWINDOW_H
