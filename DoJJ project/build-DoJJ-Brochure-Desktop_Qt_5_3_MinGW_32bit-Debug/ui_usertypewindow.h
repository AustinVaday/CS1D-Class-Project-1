/********************************************************************************
** Form generated from reading UI file 'usertypewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERTYPEWINDOW_H
#define UI_USERTYPEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserTypeWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QLabel *User_Type_Prompt;
    QPushButton *customerButton;
    QPushButton *guestButton;
    QPushButton *adminButton;
    QLabel *Brochure_Banner;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *UserTypeWindow)
    {
        if (UserTypeWindow->objectName().isEmpty())
            UserTypeWindow->setObjectName(QStringLiteral("UserTypeWindow"));
        UserTypeWindow->resize(600, 300);
        UserTypeWindow->setMinimumSize(QSize(600, 300));
        UserTypeWindow->setMaximumSize(QSize(600, 300));
        actionQuit = new QAction(UserTypeWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(UserTypeWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        User_Type_Prompt = new QLabel(centralWidget);
        User_Type_Prompt->setObjectName(QStringLiteral("User_Type_Prompt"));
        User_Type_Prompt->setGeometry(QRect(230, 140, 130, 25));
        User_Type_Prompt->setTextFormat(Qt::AutoText);
        customerButton = new QPushButton(centralWidget);
        customerButton->setObjectName(QStringLiteral("customerButton"));
        customerButton->setGeometry(QRect(220, 175, 160, 70));
        guestButton = new QPushButton(centralWidget);
        guestButton->setObjectName(QStringLiteral("guestButton"));
        guestButton->setGeometry(QRect(50, 175, 160, 70));
        adminButton = new QPushButton(centralWidget);
        adminButton->setObjectName(QStringLiteral("adminButton"));
        adminButton->setGeometry(QRect(390, 175, 160, 70));
        Brochure_Banner = new QLabel(centralWidget);
        Brochure_Banner->setObjectName(QStringLiteral("Brochure_Banner"));
        Brochure_Banner->setGeometry(QRect(50, 20, 500, 110));
        Brochure_Banner->setPixmap(QPixmap(QString::fromUtf8(":/Images/Brochure_Banner.png")));
        Brochure_Banner->setScaledContents(true);
        UserTypeWindow->setCentralWidget(centralWidget);
        guestButton->raise();
        User_Type_Prompt->raise();
        customerButton->raise();
        adminButton->raise();
        Brochure_Banner->raise();
        menuBar = new QMenuBar(UserTypeWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        UserTypeWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(UserTypeWindow);

        QMetaObject::connectSlotsByName(UserTypeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UserTypeWindow)
    {
        UserTypeWindow->setWindowTitle(QApplication::translate("UserTypeWindow", "UserTypeWindow", 0));
        actionQuit->setText(QApplication::translate("UserTypeWindow", "Quit", 0));
        actionQuit->setShortcut(QApplication::translate("UserTypeWindow", "Ctrl+Q", 0));
        User_Type_Prompt->setText(QApplication::translate("UserTypeWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Select User Type:</span></p></body></html>", 0));
        customerButton->setText(QApplication::translate("UserTypeWindow", "Returning Customer", 0));
        guestButton->setText(QApplication::translate("UserTypeWindow", "Guest", 0));
        adminButton->setText(QApplication::translate("UserTypeWindow", "Admin", 0));
        Brochure_Banner->setText(QString());
        menuFile->setTitle(QApplication::translate("UserTypeWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class UserTypeWindow: public Ui_UserTypeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERTYPEWINDOW_H
