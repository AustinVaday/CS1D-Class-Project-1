#include "otherinfo.h"
#include "ui_otherinfo.h"
#include "responsewindow.h"
//#include "BigHead.h"

otherInfo::otherInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::otherInfo)
{
    // Creates UI
    ui->setupUi(this);
}

otherInfo::otherInfo(QWidget *parent, int responseType) :
    QWidget(parent),
    ui(new Ui::otherInfo)
{
    QString text;

    // Creates UI
    ui->setupUi(this);

    // Switches based on response type given based on the button that was clicked
    switch(responseType)
    {
        case HELP_ADMIN : text = "Hot Keys:\nCtrl+L - Logout\nCtrl+Q - Quit\n\nTo view the list of customers, click the \n\"Customer List\" tab. You can add or\ndelete customers from the list by clicking \"Edit\nCustomers List\" button. Enter the name and address of the customer and click \"Add\" or \"Remove\".\n\nTo view messages from customers, click the \"View Messages\" tab. From this tab you can read and delete messages by clicking the \"Delete\" button.\n\nCustomer testimonials can be previewed and approved from the \"Approve Testimonials\" tab, you can select a testimonial and click \"Approve Testimonial\".";
                          this->setWindowTitle("We're here to help");
                          break;
        case HELP_USER  : text = "Hot Keys:\nCtrl+L - Logout\nCtrl+Q - Quit\n\nTo view information about our product you\ncan click the product info page.\n\nTo read and add testimonials to the brochure you\ncan click on the \"Testimonials\" tab.To add your\ntestimonials, type in your reviewand click \"Add\nTestimonial\".\n\nTo purchase our robot, click the \"Purchase\" tab,\nselect the model, number of robots you would like\nto purchase and the maintentance plan, if you \nso choose and click \"Calculate\" to view your total, \nthen click \"Purchase\"";
                          this->setWindowTitle("We're here to help");
                          break;
        default         : break;
    }


    // Displays text variable in the window
    ui->label->setText(text);
    // Aligns the text in the center of the window
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setWordWrap(true);

}

otherInfo::~otherInfo()
{
    // Destroys UI
    delete ui;
}

void otherInfo::on_okay_clicked()
{
    // Closes current window
    this->close();
}
