/********************************************************************************
** Form generated from reading UI file 'updatelist.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATELIST_H
#define UI_UPDATELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UpdateList
{
public:
    QPushButton *AddCustomer;
    QPushButton *RemoveCust;

    void setupUi(QDialog *UpdateList)
    {
        if (UpdateList->objectName().isEmpty())
            UpdateList->setObjectName(QStringLiteral("UpdateList"));
        UpdateList->resize(400, 300);
        AddCustomer = new QPushButton(UpdateList);
        AddCustomer->setObjectName(QStringLiteral("AddCustomer"));
        AddCustomer->setGeometry(QRect(230, 240, 141, 32));
        RemoveCust = new QPushButton(UpdateList);
        RemoveCust->setObjectName(QStringLiteral("RemoveCust"));
        RemoveCust->setGeometry(QRect(30, 240, 141, 32));

        retranslateUi(UpdateList);

        QMetaObject::connectSlotsByName(UpdateList);
    } // setupUi

    void retranslateUi(QDialog *UpdateList)
    {
        UpdateList->setWindowTitle(QApplication::translate("UpdateList", "Dialog", 0));
        AddCustomer->setText(QApplication::translate("UpdateList", "Add Customer", 0));
        RemoveCust->setText(QApplication::translate("UpdateList", "Remove Customer", 0));
    } // retranslateUi

};

namespace Ui {
    class UpdateList: public Ui_UpdateList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATELIST_H
