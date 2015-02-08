/********************************************************************************
** Form generated from reading UI file 'confirmwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMWINDOW_H
#define UI_CONFIRMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_confirmWindow
{
public:
    QWidget *centralwidget;
    QLabel *text;
    QPushButton *confirm;
    QPushButton *cancel;

    void setupUi(QMainWindow *confirmWindow)
    {
        if (confirmWindow->objectName().isEmpty())
            confirmWindow->setObjectName(QStringLiteral("confirmWindow"));
        confirmWindow->resize(417, 200);
        centralwidget = new QWidget(confirmWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        text = new QLabel(centralwidget);
        text->setObjectName(QStringLiteral("text"));
        text->setGeometry(QRect(25, 50, 371, 51));
        confirm = new QPushButton(centralwidget);
        confirm->setObjectName(QStringLiteral("confirm"));
        confirm->setGeometry(QRect(130, 130, 75, 23));
        cancel = new QPushButton(centralwidget);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(220, 130, 75, 23));
        confirmWindow->setCentralWidget(centralwidget);

        retranslateUi(confirmWindow);

        QMetaObject::connectSlotsByName(confirmWindow);
    } // setupUi

    void retranslateUi(QMainWindow *confirmWindow)
    {
        confirmWindow->setWindowTitle(QApplication::translate("confirmWindow", "MainWindow", 0));
        text->setText(QString());
        confirm->setText(QApplication::translate("confirmWindow", "Confirm", 0));
        cancel->setText(QApplication::translate("confirmWindow", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class confirmWindow: public Ui_confirmWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMWINDOW_H
