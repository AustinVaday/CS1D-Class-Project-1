#include "contactus.h"
#include "ui_contactus.h"
#include <QTimer>
#include <QBasicTimer>
#include <QMutex>

ContactUs::ContactUs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactUs),
    question("")
{

    ui->setupUi(this);
    ui->nameEdit->setFocus(Qt::OtherFocusReason);
    ui->chatBox->setReadOnly(true);

    // initial popup
    ui->chatBox->setText("Admin: How may I help you?");

//    connect(this, send_update_messages(QString, QString), AdminWindow::  );

}

ContactUs::~ContactUs()
{
    delete ui;

}

void ContactUs::generateResponse()
{
    QString responseString;
    QString wholeString;

    responseString.clear();

    if (!question.isEmpty())
    {
        if
        (question.contains("Hey", Qt::CaseInsensitive) || question.contains("Hi", Qt::CaseInsensitive)
        ||question.contains("wassup", Qt::CaseInsensitive) || question.contains("what's up", Qt::CaseInsensitive)
        ||question.contains("yo", Qt::CaseInsensitive) || question.contains("sup", Qt::CaseInsensitive)
        ||question.contains("Hello", Qt::CaseInsensitive) || question.contains("waddup", Qt::CaseInsensitive))
        {
            responseString = "Hey there!";
        }
        else if
        ((question.contains("How", Qt::CaseInsensitive) && question.contains("log in", Qt::CaseInsensitive))
        ||((question.contains("How", Qt::CaseInsensitive) && question.contains("log-in", Qt::CaseInsensitive)))
        ||question.contains("log-in", Qt::CaseInsensitive) || question.contains("log in", Qt::CaseInsensitive)
        ||(question.contains("access", Qt::CaseInsensitive) && question.contains("brochure", Qt::CaseInsensitive)))
        {
            responseString = "Great question! To log in/access the brochure, you must go"
                    " to the main window and click on the 'Log In' button! "
                    " for further information, please see the Help options! Do you need anything else?";

        }
        else if
        ((question.contains("How", Qt::CaseInsensitive) && question.contains("create", Qt::CaseInsensitive)
        &&question.contains("account", Qt::CaseInsensitive)) || (question.contains("How", Qt::CaseInsensitive)
        &&question.contains("activate", Qt::CaseInsensitive) && question.contains("brochure", Qt::CaseInsensitive))
        ||(question.contains("How", Qt::CaseInsensitive) && question.contains("can", Qt::CaseInsensitive)
        && question.contains("sign up", Qt::CaseInsensitive)) || question.contains("sign up",Qt::CaseInsensitive))
        {
            responseString = "To create an account (sign up) you must enter all required fields"
                              " in the account creation menu. Fill in the required information"
                              " and the account will be processed and reviewed. Do you need anything else?";
        }
        else if
                ((question.contains("How", Qt::CaseInsensitive) && question.contains("view", Qt::CaseInsensitive)
                &&question.contains("pricing", Qt::CaseInsensitive)) || ((question.contains("How", Qt::CaseInsensitive)
                &&question.contains("price", Qt::CaseInsensitive)) || ((question.contains("how", Qt::CaseInsensitive)
                &&(question.contains("find item", Qt::CaseInsensitive))) )))
        {
            responseString = "Great question! To view the pricing of our products, you will need to"
                                " first have access to the brochure. Once this is done, please log"
                               " in and select the 'View Products' button! Do you need anything else?";
        }
        else if
        ((question.contains("How", Qt::CaseInsensitive) && question.contains("place", Qt::CaseInsensitive)
        &&question.contains("order", Qt::CaseInsensitive)) || ((question.contains("how", Qt::CaseInsensitive)
        &&(question.contains("buy", Qt::CaseInsensitive))) || question.contains("purchase", Qt::CaseInsensitive)))
        {
            responseString = "To place an order, you must first create an account. "
                    "You may not place an order when logged in as a guest. "
                    "You must log in and select the 'Place Order' option. "
                    "Follow the instructions on screen. Do you need anything else?";
        }
        else if
        ((question.contains("No", Qt::CaseInsensitive) && (question.contains("thanks", Qt::CaseInsensitive)
        ||question.contains("thank you", Qt::CaseInsensitive))) || question.contains("no", Qt::CaseInsensitive)
        ||question.contains("nah", Qt::CaseInsensitive) || question.contains("nope", Qt::CaseInsensitive)
        ||question.contains("bye", Qt::CaseInsensitive) || question.contains("goodbye", Qt::CaseInsensitive)
        ||question.contains("see ya", Qt::CaseInsensitive) || question.contains("later", Qt::CaseInsensitive)
        ||question.contains("seeya", Qt::CaseInsensitive) || question.contains("good bye", Qt::CaseInsensitive))
        {
            responseString = "If that's the case, have a fantastic day!";
        }
        else if
        (question.contains("I love you", Qt::CaseInsensitive) || question.contains("You suck", Qt::CaseInsensitive)
        ||question.contains("I hate you", Qt::CaseInsensitive) || question.contains("Oh my god", Qt::CaseInsensitive)
        ||question.contains("LOL", Qt::CaseInsensitive) || question.contains("haha", Qt::CaseInsensitive)
        ||question.contains("nerd", Qt::CaseInsensitive) || question.contains("omg", Qt::CaseInsensitive))
        {
            responseString = "Haha, you are so silly!";
        }
        else
        {
            responseString = "Sorry, I don't know the answer to that yet! Let me "
                             "do more research and I'll be better prepared for next time! Please"
                             " check the help options for further reference.";
        }

    }
    else
    {
        responseString = "Woops! Did you mean to say something?";
    }

    wholeString = "Admin: " + responseString;
    // append new message to chatBox
    ui->chatBox->append(wholeString);

    // clear the chat line, enable it for further user input
    ui->chatTypeLine->clear();
    ui->chatTypeLine->setEnabled(true);
    ui->chatTypeLine->setFocus(Qt::OtherFocusReason);

}

void ContactUs::on_sendButton_clicked()
{

    QString name = ui->nameEdit->text();
    QString text;

    // if name is too long, make it short
    if (name.length() > 20)
    {
        name.resize(20);
        name.append("...:");
    }
    else if (name.isEmpty())
    {
        name = "User: ";
    }
    else
    {
        name.append(": ");

    }

    // user text
    text = name + ui->chatTypeLine->text();
    ui->chatBox->append(text);

    // store the question
    question = ui->chatTypeLine->text();

    ui->chatTypeLine->clear();
    ui->chatTypeLine->setEnabled(false);
    ui->chatTypeLine->setText("Admin is typing ... ");

    ui->nameEdit->clearFocus();

    QTimer::singleShot(3000, this, SLOT(generateResponse()));

    ui->nameEdit->clearFocus();

}
