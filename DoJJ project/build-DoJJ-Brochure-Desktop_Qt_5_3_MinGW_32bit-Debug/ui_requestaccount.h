/********************************************************************************
** Form generated from reading UI file 'requestaccount.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REQUESTACCOUNT_H
#define UI_REQUESTACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RequestAccount
{
public:
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *Confirm;
    QPushButton *Cancel;
    QLineEdit *CompName;
    QLabel *label_5;
    QComboBox *InterestBox;
    QLabel *label;
    QLineEdit *CompAddy_2;
    QLineEdit *CompAddy;

    void setupUi(QDialog *RequestAccount)
    {
        if (RequestAccount->objectName().isEmpty())
            RequestAccount->setObjectName(QStringLiteral("RequestAccount"));
        RequestAccount->resize(408, 298);
        label_3 = new QLabel(RequestAccount);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 130, 101, 21));
        label_2 = new QLabel(RequestAccount);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 50, 121, 16));
        Confirm = new QPushButton(RequestAccount);
        Confirm->setObjectName(QStringLiteral("Confirm"));
        Confirm->setGeometry(QRect(70, 250, 101, 32));
        Cancel = new QPushButton(RequestAccount);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setGeometry(QRect(240, 250, 91, 32));
        CompName = new QLineEdit(RequestAccount);
        CompName->setObjectName(QStringLiteral("CompName"));
        CompName->setGeometry(QRect(140, 10, 231, 21));
        label_5 = new QLabel(RequestAccount);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 90, 121, 16));
        InterestBox = new QComboBox(RequestAccount);
        InterestBox->setObjectName(QStringLiteral("InterestBox"));
        InterestBox->setGeometry(QRect(30, 160, 104, 26));
        label = new QLabel(RequestAccount);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 121, 16));
        CompAddy_2 = new QLineEdit(RequestAccount);
        CompAddy_2->setObjectName(QStringLiteral("CompAddy_2"));
        CompAddy_2->setGeometry(QRect(140, 90, 231, 21));
        CompAddy = new QLineEdit(RequestAccount);
        CompAddy->setObjectName(QStringLiteral("CompAddy"));
        CompAddy->setGeometry(QRect(140, 50, 231, 21));

        retranslateUi(RequestAccount);

        QMetaObject::connectSlotsByName(RequestAccount);
    } // setupUi

    void retranslateUi(QDialog *RequestAccount)
    {
        RequestAccount->setWindowTitle(QApplication::translate("RequestAccount", "Dialog", 0));
        label_3->setText(QApplication::translate("RequestAccount", "Level of Interest", 0));
        label_2->setText(QApplication::translate("RequestAccount", "Address 1:", 0));
        Confirm->setText(QApplication::translate("RequestAccount", "Confirm", 0));
        Cancel->setText(QApplication::translate("RequestAccount", "Cancel", 0));
        label_5->setText(QApplication::translate("RequestAccount", "Address 2:", 0));
        InterestBox->clear();
        InterestBox->insertItems(0, QStringList()
         << QApplication::translate("RequestAccount", "Very interested", 0)
         << QApplication::translate("RequestAccount", "Some what Interested", 0)
         << QApplication::translate("RequestAccount", "Not very Interested", 0)
         << QApplication::translate("RequestAccount", "Never call again", 0)
        );
        label->setText(QApplication::translate("RequestAccount", "Company Name:", 0));
    } // retranslateUi

};

namespace Ui {
    class RequestAccount: public Ui_RequestAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REQUESTACCOUNT_H
