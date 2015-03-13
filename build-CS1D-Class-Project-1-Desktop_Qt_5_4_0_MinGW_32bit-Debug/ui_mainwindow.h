/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
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
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page_main_window;
    QPlainTextEdit *plainTextEdit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *viewListWineriesButton;
    QPushButton *planDayTripButton;
    QPushButton *adminLogButton;
    QPushButton *quitButton;
    QLabel *label;
    QWidget *page_view_list_wineries;
    QLabel *label_3;
    QPushButton *ViewBack;
    QLabel *label_2;
    QLabel *label_6;
    QScrollArea *scrollWineryList;
    QWidget *scrollAreaWidgetContents;
    QWidget *page_plan_day_trip;
    QPushButton *PlanTripBack;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *visit_all;
    QPushButton *shortest_trip;
    QPushButton *custom_trip;
    QWidget *shortest_trip_3;
    QLabel *selectWineryLabel;
    QPushButton *TourBack;
    QScrollArea *radio_button_scroll_area;
    QWidget *scrollAreaWidgetContents_2;
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
    QWidget *visit_all_wineries;
    QPushButton *backToTripType;
    QLabel *wineryName;
    QScrollArea *scrollArea;
    QWidget *list_of_wines_scroll_area;
    QLabel *listOfWines;
    QScrollArea *scrollArea_2;
    QWidget *cart_scroll_area;
    QLabel *cart;
    QPushButton *addToCart;
    QPushButton *next;
    QPushButton *prev_winery;
    QWidget *customt_trip;
    QPushButton *goBack;
    QScrollArea *custom_trip_scroll_area;
    QWidget *scrollAreaWidgetContents_3;
    QLabel *selectWineryLabel_2;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(781, 594);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
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

        adminLogButton = new QPushButton(layoutWidget);
        adminLogButton->setObjectName(QStringLiteral("adminLogButton"));

        verticalLayout->addWidget(adminLogButton);

        quitButton = new QPushButton(layoutWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));

        verticalLayout->addWidget(quitButton);

        label = new QLabel(page_main_window);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 711, 71));
        label->setWordWrap(true);
        stackedWidget->addWidget(page_main_window);
        page_view_list_wineries = new QWidget();
        page_view_list_wineries->setObjectName(QStringLiteral("page_view_list_wineries"));
        label_3 = new QLabel(page_view_list_wineries);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 11, 377, 45));
        QFont font;
        font.setPointSize(22);
        label_3->setFont(font);
        label_3->setFrameShadow(QFrame::Sunken);
        ViewBack = new QPushButton(page_view_list_wineries);
        ViewBack->setObjectName(QStringLiteral("ViewBack"));
        ViewBack->setGeometry(QRect(11, 19, 93, 28));
        label_2 = new QLabel(page_view_list_wineries);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(111, 90, 68, 24));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_6 = new QLabel(page_view_list_wineries);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(470, 90, 157, 24));
        label_6->setFont(font1);
        scrollWineryList = new QScrollArea(page_view_list_wineries);
        scrollWineryList->setObjectName(QStringLiteral("scrollWineryList"));
        scrollWineryList->setGeometry(QRect(111, 140, 521, 331));
        scrollWineryList->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 519, 329));
        scrollWineryList->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(page_view_list_wineries);
        page_plan_day_trip = new QWidget();
        page_plan_day_trip->setObjectName(QStringLiteral("page_plan_day_trip"));
        PlanTripBack = new QPushButton(page_plan_day_trip);
        PlanTripBack->setObjectName(QStringLiteral("PlanTripBack"));
        PlanTripBack->setGeometry(QRect(10, 10, 75, 23));
        verticalLayoutWidget = new QWidget(page_plan_day_trip);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(180, 110, 371, 301));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        visit_all = new QPushButton(verticalLayoutWidget);
        visit_all->setObjectName(QStringLiteral("visit_all"));

        verticalLayout_2->addWidget(visit_all);

        shortest_trip = new QPushButton(verticalLayoutWidget);
        shortest_trip->setObjectName(QStringLiteral("shortest_trip"));

        verticalLayout_2->addWidget(shortest_trip);

        custom_trip = new QPushButton(verticalLayoutWidget);
        custom_trip->setObjectName(QStringLiteral("custom_trip"));

        verticalLayout_2->addWidget(custom_trip);

        stackedWidget->addWidget(page_plan_day_trip);
        shortest_trip_3 = new QWidget();
        shortest_trip_3->setObjectName(QStringLiteral("shortest_trip_3"));
        selectWineryLabel = new QLabel(shortest_trip_3);
        selectWineryLabel->setObjectName(QStringLiteral("selectWineryLabel"));
        selectWineryLabel->setGeometry(QRect(200, 20, 371, 61));
        QFont font2;
        font2.setPointSize(24);
        selectWineryLabel->setFont(font2);
        TourBack = new QPushButton(shortest_trip_3);
        TourBack->setObjectName(QStringLiteral("TourBack"));
        TourBack->setGeometry(QRect(10, 10, 75, 23));
        radio_button_scroll_area = new QScrollArea(shortest_trip_3);
        radio_button_scroll_area->setObjectName(QStringLiteral("radio_button_scroll_area"));
        radio_button_scroll_area->setGeometry(QRect(30, 140, 271, 331));
        radio_button_scroll_area->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 269, 329));
        radio_button_scroll_area->setWidget(scrollAreaWidgetContents_2);
        stackedWidget->addWidget(shortest_trip_3);
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
        layoutWidget_4->setGeometry(QRect(270, 290, 195, 32));
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
        visit_all_wineries = new QWidget();
        visit_all_wineries->setObjectName(QStringLiteral("visit_all_wineries"));
        backToTripType = new QPushButton(visit_all_wineries);
        backToTripType->setObjectName(QStringLiteral("backToTripType"));
        backToTripType->setGeometry(QRect(10, 10, 75, 23));
        wineryName = new QLabel(visit_all_wineries);
        wineryName->setObjectName(QStringLiteral("wineryName"));
        wineryName->setGeometry(QRect(260, 20, 231, 51));
        scrollArea = new QScrollArea(visit_all_wineries);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(40, 120, 221, 321));
        scrollArea->setWidgetResizable(true);
        list_of_wines_scroll_area = new QWidget();
        list_of_wines_scroll_area->setObjectName(QStringLiteral("list_of_wines_scroll_area"));
        list_of_wines_scroll_area->setGeometry(QRect(0, 0, 219, 319));
        scrollArea->setWidget(list_of_wines_scroll_area);
        listOfWines = new QLabel(visit_all_wineries);
        listOfWines->setObjectName(QStringLiteral("listOfWines"));
        listOfWines->setGeometry(QRect(40, 80, 81, 31));
        scrollArea_2 = new QScrollArea(visit_all_wineries);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(470, 120, 221, 321));
        scrollArea_2->setWidgetResizable(true);
        cart_scroll_area = new QWidget();
        cart_scroll_area->setObjectName(QStringLiteral("cart_scroll_area"));
        cart_scroll_area->setGeometry(QRect(0, 0, 219, 319));
        scrollArea_2->setWidget(cart_scroll_area);
        cart = new QLabel(visit_all_wineries);
        cart->setObjectName(QStringLiteral("cart"));
        cart->setGeometry(QRect(470, 80, 81, 31));
        addToCart = new QPushButton(visit_all_wineries);
        addToCart->setObjectName(QStringLiteral("addToCart"));
        addToCart->setGeometry(QRect(320, 150, 93, 28));
        next = new QPushButton(visit_all_wineries);
        next->setObjectName(QStringLiteral("next"));
        next->setGeometry(QRect(630, 460, 111, 41));
        prev_winery = new QPushButton(visit_all_wineries);
        prev_winery->setObjectName(QStringLiteral("prev_winery"));
        prev_winery->setGeometry(QRect(10, 460, 111, 41));
        stackedWidget->addWidget(visit_all_wineries);
        customt_trip = new QWidget();
        customt_trip->setObjectName(QStringLiteral("customt_trip"));
        goBack = new QPushButton(customt_trip);
        goBack->setObjectName(QStringLiteral("goBack"));
        goBack->setGeometry(QRect(10, 10, 93, 28));
        custom_trip_scroll_area = new QScrollArea(customt_trip);
        custom_trip_scroll_area->setObjectName(QStringLiteral("custom_trip_scroll_area"));
        custom_trip_scroll_area->setGeometry(QRect(60, 130, 271, 331));
        custom_trip_scroll_area->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 269, 329));
        custom_trip_scroll_area->setWidget(scrollAreaWidgetContents_3);
        selectWineryLabel_2 = new QLabel(customt_trip);
        selectWineryLabel_2->setObjectName(QStringLiteral("selectWineryLabel_2"));
        selectWineryLabel_2->setGeometry(QRect(200, 20, 371, 61));
        selectWineryLabel_2->setFont(font2);
        stackedWidget->addWidget(customt_trip);

        gridLayout_2->addWidget(stackedWidget, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 781, 26));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionHelp);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(5);
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
        adminLogButton->setText(QApplication::translate("MainWindow", "Admin Log-In", 0));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-family:'Comic Sans MS'; font-size:18pt;\">STRAIGHT AHEAD WINE TOURS OF THE CENTRAL COAST</span><span style=\" font-size:18pt;\"/></p></body></html>", 0));
        label_3->setText(QApplication::translate("MainWindow", "Our Beautiful Wineries:", 0));
        ViewBack->setText(QApplication::translate("MainWindow", "Back", 0));
        label_2->setText(QApplication::translate("MainWindow", "Names:", 0));
        label_6->setText(QApplication::translate("MainWindow", "Distance from us:", 0));
        PlanTripBack->setText(QApplication::translate("MainWindow", "Back", 0));
        visit_all->setText(QApplication::translate("MainWindow", "Visit All the Wineries", 0));
        shortest_trip->setText(QApplication::translate("MainWindow", "Shortest Trip", 0));
        custom_trip->setText(QApplication::translate("MainWindow", "Custom Trip", 0));
        selectWineryLabel->setText(QString());
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
        backToTripType->setText(QApplication::translate("MainWindow", "Back", 0));
#ifndef QT_NO_TOOLTIP
        wineryName->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        wineryName->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        listOfWines->setText(QApplication::translate("MainWindow", "List of Wines", 0));
        cart->setText(QApplication::translate("MainWindow", "Cart", 0));
        addToCart->setText(QApplication::translate("MainWindow", "Add to Cart", 0));
        next->setText(QApplication::translate("MainWindow", "Next Winery", 0));
        prev_winery->setText(QApplication::translate("MainWindow", "Previous Winery", 0));
        goBack->setText(QApplication::translate("MainWindow", "Back", 0));
        selectWineryLabel_2->setText(QString());
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
