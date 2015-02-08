/********************************************************************************
** Form generated from reading UI file 'custinfoprompt.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTINFOPROMPT_H
#define UI_CUSTINFOPROMPT_H

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

class Ui_CustInfoPrompt
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *Add;
    QPushButton *Cancel;
    QLineEdit *CompAddy;
    QLineEdit *CompName;
    QPushButton *Remove;
    QComboBox *InterestBox;
    QComboBox *ImportanceBox;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *CompAddy_2;
    QPushButton *Edit;

    void setupUi(QDialog *CustInfoPrompt)
    {
        if (CustInfoPrompt->objectName().isEmpty())
            CustInfoPrompt->setObjectName(QStringLiteral("CustInfoPrompt"));
        CustInfoPrompt->resize(400, 300);
        label = new QLabel(CustInfoPrompt);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 121, 16));
        label_2 = new QLabel(CustInfoPrompt);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 121, 16));
        Add = new QPushButton(CustInfoPrompt);
        Add->setObjectName(QStringLiteral("Add"));
        Add->setGeometry(QRect(20, 210, 115, 32));
        Cancel = new QPushButton(CustInfoPrompt);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setGeometry(QRect(20, 250, 361, 32));
        CompAddy = new QLineEdit(CustInfoPrompt);
        CompAddy->setObjectName(QStringLiteral("CompAddy"));
        CompAddy->setGeometry(QRect(130, 60, 231, 21));
        CompName = new QLineEdit(CustInfoPrompt);
        CompName->setObjectName(QStringLiteral("CompName"));
        CompName->setGeometry(QRect(130, 20, 231, 21));
        Remove = new QPushButton(CustInfoPrompt);
        Remove->setObjectName(QStringLiteral("Remove"));
        Remove->setGeometry(QRect(140, 210, 115, 32));
        InterestBox = new QComboBox(CustInfoPrompt);
        InterestBox->setObjectName(QStringLiteral("InterestBox"));
        InterestBox->setGeometry(QRect(20, 170, 104, 26));
        ImportanceBox = new QComboBox(CustInfoPrompt);
        ImportanceBox->setObjectName(QStringLiteral("ImportanceBox"));
        ImportanceBox->setGeometry(QRect(270, 170, 104, 26));
        label_3 = new QLabel(CustInfoPrompt);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 140, 131, 21));
        label_4 = new QLabel(CustInfoPrompt);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(270, 140, 101, 21));
        label_5 = new QLabel(CustInfoPrompt);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 100, 121, 16));
        CompAddy_2 = new QLineEdit(CustInfoPrompt);
        CompAddy_2->setObjectName(QStringLiteral("CompAddy_2"));
        CompAddy_2->setGeometry(QRect(130, 100, 231, 21));
        Edit = new QPushButton(CustInfoPrompt);
        Edit->setObjectName(QStringLiteral("Edit"));
        Edit->setGeometry(QRect(260, 210, 115, 32));

        retranslateUi(CustInfoPrompt);

        QMetaObject::connectSlotsByName(CustInfoPrompt);
    } // setupUi

    void retranslateUi(QDialog *CustInfoPrompt)
    {
        CustInfoPrompt->setWindowTitle(QApplication::translate("CustInfoPrompt", "Dialog", 0));
        label->setText(QApplication::translate("CustInfoPrompt", "Company Name:", 0));
        label_2->setText(QApplication::translate("CustInfoPrompt", "Address 1:", 0));
        Add->setText(QApplication::translate("CustInfoPrompt", "Add", 0));
        Cancel->setText(QApplication::translate("CustInfoPrompt", "Cancel", 0));
        Remove->setText(QApplication::translate("CustInfoPrompt", "Remove", 0));
        InterestBox->clear();
        InterestBox->insertItems(0, QStringList()
         << QApplication::translate("CustInfoPrompt", "Very interested", 0)
         << QApplication::translate("CustInfoPrompt", "Some what Interested", 0)
         << QApplication::translate("CustInfoPrompt", "Not very Interested", 0)
         << QApplication::translate("CustInfoPrompt", "Never call again", 0)
        );
        ImportanceBox->clear();
        ImportanceBox->insertItems(0, QStringList()
         << QApplication::translate("CustInfoPrompt", "Nice to Have", 0)
         << QApplication::translate("CustInfoPrompt", "Key", 0)
        );
        label_3->setText(QApplication::translate("CustInfoPrompt", "Level of Interest", 0));
        label_4->setText(QApplication::translate("CustInfoPrompt", "Importance", 0));
        label_5->setText(QApplication::translate("CustInfoPrompt", "Address 2:", 0));
        Edit->setText(QApplication::translate("CustInfoPrompt", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class CustInfoPrompt: public Ui_CustInfoPrompt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTINFOPROMPT_H
