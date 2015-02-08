/********************************************************************************
** Form generated from reading UI file 'responsewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESPONSEWINDOW_H
#define UI_RESPONSEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_responseWindow
{
public:
    QPushButton *okay;
    QLabel *label;

    void setupUi(QWidget *responseWindow)
    {
        if (responseWindow->objectName().isEmpty())
            responseWindow->setObjectName(QStringLiteral("responseWindow"));
        responseWindow->resize(400, 115);
        responseWindow->setMinimumSize(QSize(400, 115));
        responseWindow->setMaximumSize(QSize(400, 115));
        okay = new QPushButton(responseWindow);
        okay->setObjectName(QStringLiteral("okay"));
        okay->setGeometry(QRect(160, 80, 75, 23));
        label = new QLabel(responseWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 291, 41));

        retranslateUi(responseWindow);

        QMetaObject::connectSlotsByName(responseWindow);
    } // setupUi

    void retranslateUi(QWidget *responseWindow)
    {
        responseWindow->setWindowTitle(QApplication::translate("responseWindow", "Form", 0));
        okay->setText(QApplication::translate("responseWindow", "Okay", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class responseWindow: public Ui_responseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESPONSEWINDOW_H
