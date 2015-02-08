/********************************************************************************
** Form generated from reading UI file 'contactus.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTUS_H
#define UI_CONTACTUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_contactUs
{
public:
    QPushButton *send;
    QTextEdit *textEdit;
    QLineEdit *userName;
    QLabel *label;
    QPushButton *cancel;

    void setupUi(QWidget *contactUs)
    {
        if (contactUs->objectName().isEmpty())
            contactUs->setObjectName(QStringLiteral("contactUs"));
        contactUs->resize(400, 300);
        send = new QPushButton(contactUs);
        send->setObjectName(QStringLiteral("send"));
        send->setGeometry(QRect(110, 250, 75, 23));
        textEdit = new QTextEdit(contactUs);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 60, 361, 181));
        userName = new QLineEdit(contactUs);
        userName->setObjectName(QStringLiteral("userName"));
        userName->setGeometry(QRect(160, 20, 113, 20));
        label = new QLabel(contactUs);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 22, 46, 21));
        cancel = new QPushButton(contactUs);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(210, 250, 75, 23));

        retranslateUi(contactUs);

        QMetaObject::connectSlotsByName(contactUs);
    } // setupUi

    void retranslateUi(QWidget *contactUs)
    {
        contactUs->setWindowTitle(QApplication::translate("contactUs", "Form", 0));
        send->setText(QApplication::translate("contactUs", "Send", 0));
        label->setText(QApplication::translate("contactUs", "Name:", 0));
        cancel->setText(QApplication::translate("contactUs", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class contactUs: public Ui_contactUs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTUS_H
