/********************************************************************************
** Form generated from reading UI file 'userlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLOGIN_H
#define UI_USERLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userLogin
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *login;
    QPushButton *cancel;

    void setupUi(QWidget *userLogin)
    {
        if (userLogin->objectName().isEmpty())
            userLogin->setObjectName(QStringLiteral("userLogin"));
        userLogin->resize(600, 300);
        userLogin->setMinimumSize(QSize(600, 300));
        userLogin->setMaximumSize(QSize(600, 300));
        label = new QLabel(userLogin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 110, 111, 21));
        lineEdit = new QLineEdit(userLogin);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(270, 110, 113, 20));
        login = new QPushButton(userLogin);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(200, 210, 75, 23));
        cancel = new QPushButton(userLogin);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(300, 210, 75, 23));

        retranslateUi(userLogin);

        QMetaObject::connectSlotsByName(userLogin);
    } // setupUi

    void retranslateUi(QWidget *userLogin)
    {
        userLogin->setWindowTitle(QApplication::translate("userLogin", "Form", 0));
        label->setText(QApplication::translate("userLogin", "Company Name", 0));
        lineEdit->setPlaceholderText(QString());
        login->setText(QApplication::translate("userLogin", "Login", 0));
        login->setShortcut(QApplication::translate("userLogin", "Return", 0));
        cancel->setText(QApplication::translate("userLogin", "Cancel", 0));
        cancel->setShortcut(QApplication::translate("userLogin", "Return", 0));
    } // retranslateUi

};

namespace Ui {
    class userLogin: public Ui_userLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLOGIN_H
