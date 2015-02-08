#include "responsewindow.h"
#include "ui_responsewindow.h"
#include "usertypewindow.h"
//#include "BigHead.h"

responseWindow::responseWindow(QWidget *parent, int requestType) :
    QWidget(parent),
    ui(new Ui::responseWindow)
{
    QString text;

    // Creates UI
    ui->setupUi(this);

    // Switches based on response type given based on the button that was clicked
    switch(requestType)
    {
        case REQUEST_BROCHURE       : text = "You have been sent a brochure.";
                                      this->setWindowTitle("Brochure Requested");
                                      break;
        case PRINT_BROCHURE         : text = "You have printed a brochure.";
                                      this->setWindowTitle("Brochure Printed");
                                      break;
        case LOGIN_FAILED           : text = "You have entered an invalid username.";
                                      this->setWindowTitle("Login Failed");
                                      break;
        case LOGIN_SUCCESSFUL       : text = "You have successfully logged in. Welcome back.";
                                      this->setWindowTitle("Login Successful");
                                      break;
        case ADD_TESTIMONIAL        : text = "Your testimonial has been sent to be processed.";
                                      this->setWindowTitle("Testimonial Added");
                                      break;
        case PURCHASE               : text = "You have purchased our super-duper bomb disposing robot.";
                                      this->setWindowTitle("Purchase Successful");
                                      break;
        case PURCHASE_FAILED        : text = "You have not selected anything to be purchased.";
                                      this->setWindowTitle("Purchase Failed");
                                      break;
        case PRINT_CUSTOMER_LIST    : text = "You have printed the customer list.";
                                      this->setWindowTitle("Customer List Printed");
                                      break;
        case ADD_CUSTOMER           : text = "You have added a new user.";
                                      this->setWindowTitle("User Added");
                                      break;
        case REMOVE_CUSTOMER        : text = "You have removed a user.";
                                      this->setWindowTitle("User Deleted");
                                      break;
        case EDIT_CUSTOMER          : text = "You have edited a user.";
                                      this->setWindowTitle("User Edited");
                                      break;
        case REMOVE_CUSTOMER_FAIL   : text = "Customer name not found.\nNothing removed from list.";
                                      this->setWindowTitle("Removed Failed");
                                      break;
        case EDIT_CUSTOMER_FAIL     : text = "Customer name not found.\nNothing to edit.";
                                      this->setWindowTitle("Edit Failed");
                                      break;
        case APPROVE_TESTIMONIAL    : text = "You have approved this testimonial.";
                                      this->setWindowTitle("Testimonial Approved");
                                      break;
        case TESTIMONIAL_FAILED     : text = "No testimonial is selected.";
                                      this->setWindowTitle("No Item Selected");
                                      break;
        case DENY_ACCOUNT           : text = "The account has been denied.";
                                      this->setWindowTitle("Account Denied");
                                      break;
        case NO_ITEM_SELECTED       : text = "You have not selected an item.";
                                      this->setWindowTitle("Nothing Selected");
                                      break;
        case ACCOUNT_APPROVED       : text = "The account has been approved.";
                                      this->setWindowTitle("Success");
                                      break;
        case ACCOUNT_APPROVE_FAILED : text = "Failed to add the account.";
                                      this->setWindowTitle("Error");
                                      break;
        case DENY_TESTIMONIAL       : text = "You have denied this testimonial.";
                                      this->setWindowTitle("Testimonial Denied");
                                      break;
        case TESTI_PENDING          : text = "You already have a testimonial awaitng approval";
                                      this->setWindowTitle("Error");
                                      break;
        case DELETE_MESSAGE         : text = "You have deleted the selected message.";
                                      this->setWindowTitle("Message Deleted");
                                      break;
        case DELETE_FAILED          : text = "No message is selected.";
                                      this->setWindowTitle("No Item Selected");
                                      break;
        case CONTACT_US             : text = "Your message has been sent.";
                                      this->setWindowTitle("Message sent");
                                      break;
        case REQUEST_ACCOUNT        : text = "Account request has been sent for processing.";
                                      this->setWindowTitle("Account Requested");
                                      break;
        case NON_EXISTING_ACCOUNT   : text = "No such account exists.";
                                      this->setWindowTitle("Account not found");
                                      break;
        case ALREADY_EXISTING_ACCOUNT:text = "An account with this name already exists.";
                                      this->setWindowTitle("Account already Exists");
                                      break;
        case BROCHURE_REQUESTED     : text = "You have already requested a brochure.";
                                      this->setWindowTitle("Error");
                                      break;
        case INCOMPLETE_FORM        : text = "Please enter all information: Name, address, interest level, and key status.";
                                      this->setWindowTitle("Form Incomplete");
                                      break;
        default                     : break;
    }

    // Displays text in the window
    ui->label->setText(text);
    // Enables word wrapping within label
    ui->label->setWordWrap(true);
    // Centers the text in the window
    ui->label->setAlignment(Qt::AlignCenter);
}

responseWindow::~responseWindow()
{
    // Destroys UI
    delete ui;
}

void responseWindow::on_okay_clicked()
{
    // Closes current window
    this->close();
}
