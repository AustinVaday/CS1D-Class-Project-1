/********************************************************************************
** Form generated from reading UI file 'adminlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGIN_H
#define UI_ADMINLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminLogin
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *authLogin;
    QFrame *frame;
    QPushButton *cancelLogin;
    QMenuBar *menubar;

    void setupUi(QMainWindow *adminLogin)
    {
        if (adminLogin->objectName().isEmpty())
            adminLogin->setObjectName(QStringLiteral("adminLogin"));
        adminLogin->resize(600, 300);
        adminLogin->setMinimumSize(QSize(600, 300));
        adminLogin->setMaximumSize(QSize(600, 300));
        centralwidget = new QWidget(adminLogin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(250, 50, 300, 30));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(250, 110, 300, 30));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 50, 81, 30));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 110, 101, 30));
        authLogin = new QPushButton(centralwidget);
        authLogin->setObjectName(QStringLiteral("authLogin"));
        authLogin->setGeometry(QRect(70, 190, 200, 50));
        authLogin->setAutoFillBackground(false);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(25, 20, 550, 150));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        cancelLogin = new QPushButton(centralwidget);
        cancelLogin->setObjectName(QStringLiteral("cancelLogin"));
        cancelLogin->setGeometry(QRect(330, 190, 200, 50));
        cancelLogin->setAutoFillBackground(false);
        adminLogin->setCentralWidget(centralwidget);
        frame->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        label->raise();
        label_2->raise();
        authLogin->raise();
        cancelLogin->raise();
        menubar = new QMenuBar(adminLogin);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 21));
        adminLogin->setMenuBar(menubar);

        retranslateUi(adminLogin);

        QMetaObject::connectSlotsByName(adminLogin);
    } // setupUi

    void retranslateUi(QMainWindow *adminLogin)
    {
        adminLogin->setWindowTitle(QApplication::translate("adminLogin", "Admin Login", 0));
        label->setText(QApplication::translate("adminLogin", "<html><head/><body><p><span style=\" font-size:12pt;\">Username:</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("adminLogin", "<html><head/><body><p><span style=\" font-size:12pt;\">Password:</span></p></body></html>", 0));
        authLogin->setText(QApplication::translate("adminLogin", "Login", 0));
        authLogin->setShortcut(QApplication::translate("adminLogin", "Return", 0));
        cancelLogin->setText(QApplication::translate("adminLogin", "Cancel", 0));
        cancelLogin->setShortcut(QApplication::translate("adminLogin", "Return", 0));
    } // retranslateUi

};

namespace Ui {
    class adminLogin: public Ui_adminLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGIN_H
