/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHelp;
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page_main_window;
    QPlainTextEdit *plainTextEdit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *viewListWineriesButton;
    QPushButton *planDayTripButton;
    QPushButton *tourWineriesButton;
    QPushButton *adminLogButton;
    QPushButton *quitButton;
    QLabel *label;
    QWidget *page_view_list_wineries;
    QLabel *label_3;
    QPushButton *ViewBack;
    QWidget *page_plan_day_trip;
    QLabel *label_4;
    QPushButton *PlanTripBack;
    QWidget *page_tour_and_purchase;
    QLabel *label_5;
    QPushButton *TourBack;
    QWidget *page_admin_login;
    QStackedWidget *stackedWidget_2;
    QWidget *page_admin_login_form;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QLineEdit *userNameLine;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QLineEdit *passwordLine;
    QLabel *label_9;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *admin_log_ok_button;
    QPushButton *adming_log_cancel_button;
    QWidget *page_admin_login_success;
    QLabel *label_16;
    QPushButton *admin_log_out_button;
    QPushButton *LogInBack;
    QPushButton *pushButton;
    QWidget *page_7;
    QWidget *page_8;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(781, 594);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 781, 531));
        page_main_window = new QWidget();
        page_main_window->setObjectName(QStringLiteral("page_main_window"));
        plainTextEdit = new QPlainTextEdit(page_main_window);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(300, 400, 151, 91));
        plainTextEdit->setReadOnly(true);
        layoutWidget = new QWidget(page_main_window);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(230, 180, 288, 198));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        viewListWineriesButton = new QPushButton(layoutWidget);
        viewListWineriesButton->setObjectName(QStringLiteral("viewListWineriesButton"));

        verticalLayout->addWidget(viewListWineriesButton);

        planDayTripButton = new QPushButton(layoutWidget);
        planDayTripButton->setObjectName(QStringLiteral("planDayTripButton"));

        verticalLayout->addWidget(planDayTripButton);

        tourWineriesButton = new QPushButton(layoutWidget);
        tourWineriesButton->setObjectName(QStringLiteral("tourWineriesButton"));

        verticalLayout->addWidget(tourWineriesButton);

        adminLogButton = new QPushButton(layoutWidget);
        adminLogButton->setObjectName(QStringLiteral("adminLogButton"));

        verticalLayout->addWidget(adminLogButton);

        quitButton = new QPushButton(layoutWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));

        verticalLayout->addWidget(quitButton);

        label = new QLabel(page_main_window);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 50, 631, 71));
        label->setWordWrap(true);
        stackedWidget->addWidget(page_main_window);
        page_view_list_wineries = new QWidget();
        page_view_list_wineries->setObjectName(QStringLiteral("page_view_list_wineries"));
        label_3 = new QLabel(page_view_list_wineries);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 160, 311, 20));
        ViewBack = new QPushButton(page_view_list_wineries);
        ViewBack->setObjectName(QStringLiteral("ViewBack"));
        ViewBack->setGeometry(QRect(10, 20, 75, 23));
        stackedWidget->addWidget(page_view_list_wineries);
        page_plan_day_trip = new QWidget();
        page_plan_day_trip->setObjectName(QStringLiteral("page_plan_day_trip"));
        label_4 = new QLabel(page_plan_day_trip);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(300, 190, 311, 20));
        PlanTripBack = new QPushButton(page_plan_day_trip);
        PlanTripBack->setObjectName(QStringLiteral("PlanTripBack"));
        PlanTripBack->setGeometry(QRect(10, 10, 75, 23));
        stackedWidget->addWidget(page_plan_day_trip);
        page_tour_and_purchase = new QWidget();
        page_tour_and_purchase->setObjectName(QStringLiteral("page_tour_and_purchase"));
        label_5 = new QLabel(page_tour_and_purchase);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(260, 220, 311, 20));
        TourBack = new QPushButton(page_tour_and_purchase);
        TourBack->setObjectName(QStringLiteral("TourBack"));
        TourBack->setGeometry(QRect(10, 10, 75, 23));
        stackedWidget->addWidget(page_tour_and_purchase);
        page_admin_login = new QWidget();
        page_admin_login->setObjectName(QStringLiteral("page_admin_login"));
        stackedWidget_2 = new QStackedWidget(page_admin_login);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(10, 20, 771, 521));
        page_admin_login_form = new QWidget();
        page_admin_login_form->setObjectName(QStringLiteral("page_admin_login_form"));
        layoutWidget_3 = new QWidget(page_admin_login_form);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(250, 210, 209, 58));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(layoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);

        userNameLine = new QLineEdit(layoutWidget_3);
        userNameLine->setObjectName(QStringLiteral("userNameLine"));

        horizontalLayout_2->addWidget(userNameLine);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_8 = new QLabel(layoutWidget_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_3->addWidget(label_8);

        passwordLine = new QLineEdit(layoutWidget_3);
        passwordLine->setObjectName(QStringLiteral("passwordLine"));
        passwordLine->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(passwordLine);


        verticalLayout_3->addLayout(horizontalLayout_3);

        label_9 = new QLabel(page_admin_login_form);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(300, 150, 131, 16));
        layoutWidget_4 = new QWidget(page_admin_login_form);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(270, 290, 171, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget_4);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        admin_log_ok_button = new QPushButton(layoutWidget_4);
        admin_log_ok_button->setObjectName(QStringLiteral("admin_log_ok_button"));

        horizontalLayout->addWidget(admin_log_ok_button);

        adming_log_cancel_button = new QPushButton(layoutWidget_4);
        adming_log_cancel_button->setObjectName(QStringLiteral("adming_log_cancel_button"));

        horizontalLayout->addWidget(adming_log_cancel_button);

        stackedWidget_2->addWidget(page_admin_login_form);
        page_admin_login_success = new QWidget();
        page_admin_login_success->setObjectName(QStringLiteral("page_admin_login_success"));
        label_16 = new QLabel(page_admin_login_success);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(290, 190, 261, 16));
        admin_log_out_button = new QPushButton(page_admin_login_success);
        admin_log_out_button->setObjectName(QStringLiteral("admin_log_out_button"));
        admin_log_out_button->setGeometry(QRect(310, 270, 113, 32));
        LogInBack = new QPushButton(page_admin_login_success);
        LogInBack->setObjectName(QStringLiteral("LogInBack"));
        LogInBack->setGeometry(QRect(310, 230, 111, 31));
        pushButton = new QPushButton(page_admin_login_success);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 75, 23));
        stackedWidget_2->addWidget(page_admin_login_success);
        stackedWidget->addWidget(page_admin_login);
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        stackedWidget->addWidget(page_8);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 781, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionHelp);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);
        stackedWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0));
        plainTextEdit->setPlainText(QApplication::translate("MainWindow", "TEMP ADMIN LOGIN:\n"
"\n"
"username: admin\n"
"password: password", 0));
        viewListWineriesButton->setText(QApplication::translate("MainWindow", "View Our List of Wineries", 0));
        planDayTripButton->setText(QApplication::translate("MainWindow", "Plan A Day Trip", 0));
        tourWineriesButton->setText(QApplication::translate("MainWindow", "Tour Your Wineries and Purchase Wines", 0));
        adminLogButton->setText(QApplication::translate("MainWindow", "Admin Log-In", 0));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-family:'Comic Sans MS'; font-size:18pt;\">STRAIGHT AHEAD WINE TOURS OF THE CENTRAL COAST</span><span style=\" font-size:18pt;\"/></p></body></html>", 0));
        label_3->setText(QApplication::translate("MainWindow", "View Wineries Page", 0));
        ViewBack->setText(QApplication::translate("MainWindow", "Back", 0));
        label_4->setText(QApplication::translate("MainWindow", "Plan Day Trip Page", 0));
        PlanTripBack->setText(QApplication::translate("MainWindow", "Back", 0));
        label_5->setText(QApplication::translate("MainWindow", "Tour and Purchase Wine Page", 0));
        TourBack->setText(QApplication::translate("MainWindow", "Back", 0));
        label_7->setText(QApplication::translate("MainWindow", "User Name :", 0));
        label_8->setText(QApplication::translate("MainWindow", "Password   :", 0));
        label_9->setText(QApplication::translate("MainWindow", "Admin Log In", 0));
        admin_log_ok_button->setText(QApplication::translate("MainWindow", "Ok", 0));
        adming_log_cancel_button->setText(QApplication::translate("MainWindow", "Cancel", 0));
        label_16->setText(QApplication::translate("MainWindow", "Congrats, you are now logged in", 0));
        admin_log_out_button->setText(QApplication::translate("MainWindow", "Log Out", 0));
        LogInBack->setText(QApplication::translate("MainWindow", "Back to Main", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
