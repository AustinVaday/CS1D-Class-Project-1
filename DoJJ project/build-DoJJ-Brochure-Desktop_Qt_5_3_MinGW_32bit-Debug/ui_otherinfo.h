/********************************************************************************
** Form generated from reading UI file 'otherinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OTHERINFO_H
#define UI_OTHERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_otherInfo
{
public:
    QPushButton *okay;
    QLabel *label;

    void setupUi(QWidget *otherInfo)
    {
        if (otherInfo->objectName().isEmpty())
            otherInfo->setObjectName(QStringLiteral("otherInfo"));
        otherInfo->resize(400, 300);
        okay = new QPushButton(otherInfo);
        okay->setObjectName(QStringLiteral("okay"));
        okay->setGeometry(QRect(160, 250, 75, 23));
        okay->setAutoFillBackground(false);
        label = new QLabel(otherInfo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 311, 221));

        retranslateUi(otherInfo);

        QMetaObject::connectSlotsByName(otherInfo);
    } // setupUi

    void retranslateUi(QWidget *otherInfo)
    {
        otherInfo->setWindowTitle(QApplication::translate("otherInfo", "Form", 0));
        okay->setText(QApplication::translate("otherInfo", "Okay", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class otherInfo: public Ui_otherInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTHERINFO_H
