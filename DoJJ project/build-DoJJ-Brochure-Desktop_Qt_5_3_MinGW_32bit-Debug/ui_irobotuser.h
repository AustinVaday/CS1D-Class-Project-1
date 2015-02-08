/********************************************************************************
** Form generated from reading UI file 'irobotuser.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IROBOTUSER_H
#define UI_IROBOTUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_iRobotUser
{
public:
    QAction *actionLog_out;
    QAction *actionQuit;
    QAction *actionUser_Guide;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *conceptofOperations;
    QLabel *label;
    QFrame *frame;
    QPushButton *requestAccount;
    QWidget *tab_2;
    QPushButton *requestBrochure;
    QPushButton *printBrochure;
    QTabWidget *tabWidget_2;
    QWidget *tab_5;
    QLabel *label_2;
    QLabel *salesPitch;
    QWidget *tab_6;
    QLabel *label_3;
    QLabel *envitemnetList;
    QWidget *tab_7;
    QLabel *guaranteePolicyLabel;
    QLabel *label_4;
    QWidget *tab_3;
    QPushButton *addTestimonial;
    QTextEdit *textEdit;
    QFrame *testimonialFrame;
    QTextBrowser *testimonialDisplay;
    QWidget *tab_4;
    QFrame *frame_2;
    QGroupBox *groupBox;
    QRadioButton *basic;
    QRadioButton *advanced;
    QRadioButton *hardcore;
    QLabel *label_7;
    QLabel *tax;
    QLabel *label_6;
    QLabel *total;
    QPushButton *pushButton;
    QSpinBox *spinBox;
    QLabel *label_5;
    QPushButton *purchase;
    QRadioButton *maintenanceButton;
    QLabel *Maintenance;
    QPushButton *contactus;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *iRobotUser)
    {
        if (iRobotUser->objectName().isEmpty())
            iRobotUser->setObjectName(QStringLiteral("iRobotUser"));
        iRobotUser->resize(800, 600);
        iRobotUser->setMinimumSize(QSize(800, 600));
        iRobotUser->setMaximumSize(QSize(800, 600));
        actionLog_out = new QAction(iRobotUser);
        actionLog_out->setObjectName(QStringLiteral("actionLog_out"));
        actionQuit = new QAction(iRobotUser);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionUser_Guide = new QAction(iRobotUser);
        actionUser_Guide->setObjectName(QStringLiteral("actionUser_Guide"));
        centralwidget = new QWidget(iRobotUser);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 781, 531));
        tabWidget->setMinimumSize(QSize(781, 531));
        tabWidget->setMaximumSize(QSize(781, 531));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setLayoutDirection(Qt::RightToLeft);
        conceptofOperations = new QLabel(tab);
        conceptofOperations->setObjectName(QStringLiteral("conceptofOperations"));
        conceptofOperations->setGeometry(QRect(110, 70, 561, 241));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 50, 71, 16));
        frame = new QFrame(tab);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(90, 30, 611, 361));
        frame->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        requestAccount = new QPushButton(tab);
        requestAccount->setObjectName(QStringLiteral("requestAccount"));
        requestAccount->setGeometry(QRect(330, 440, 111, 23));
        tabWidget->addTab(tab, QString());
        frame->raise();
        conceptofOperations->raise();
        label->raise();
        requestAccount->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        requestBrochure = new QPushButton(tab_2);
        requestBrochure->setObjectName(QStringLiteral("requestBrochure"));
        requestBrochure->setGeometry(QRect(250, 450, 121, 23));
        printBrochure = new QPushButton(tab_2);
        printBrochure->setObjectName(QStringLiteral("printBrochure"));
        printBrochure->setGeometry(QRect(410, 450, 121, 23));
        tabWidget_2 = new QTabWidget(tab_2);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(20, 10, 731, 381));
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label_2 = new QLabel(tab_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 20, 101, 16));
        salesPitch = new QLabel(tab_5);
        salesPitch->setObjectName(QStringLiteral("salesPitch"));
        salesPitch->setGeometry(QRect(70, 50, 591, 241));
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        label_3 = new QLabel(tab_6);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 20, 141, 21));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        envitemnetList = new QLabel(tab_6);
        envitemnetList->setObjectName(QStringLiteral("envitemnetList"));
        envitemnetList->setGeometry(QRect(70, 50, 581, 231));
        tabWidget_2->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        guaranteePolicyLabel = new QLabel(tab_7);
        guaranteePolicyLabel->setObjectName(QStringLiteral("guaranteePolicyLabel"));
        guaranteePolicyLabel->setGeometry(QRect(70, 52, 581, 231));
        label_4 = new QLabel(tab_7);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 20, 121, 16));
        label_4->setFont(font);
        tabWidget_2->addTab(tab_7, QString());
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        addTestimonial = new QPushButton(tab_3);
        addTestimonial->setObjectName(QStringLiteral("addTestimonial"));
        addTestimonial->setGeometry(QRect(340, 470, 101, 23));
        textEdit = new QTextEdit(tab_3);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(250, 390, 281, 71));
        testimonialFrame = new QFrame(tab_3);
        testimonialFrame->setObjectName(QStringLiteral("testimonialFrame"));
        testimonialFrame->setGeometry(QRect(10, 20, 751, 351));
        testimonialFrame->setFrameShape(QFrame::Box);
        testimonialFrame->setFrameShadow(QFrame::Raised);
        testimonialDisplay = new QTextBrowser(testimonialFrame);
        testimonialDisplay->setObjectName(QStringLiteral("testimonialDisplay"));
        testimonialDisplay->setGeometry(QRect(20, 20, 711, 311));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        frame_2 = new QFrame(tab_4);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(30, 30, 361, 431));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        groupBox = new QGroupBox(frame_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 291, 111));
        basic = new QRadioButton(groupBox);
        basic->setObjectName(QStringLiteral("basic"));
        basic->setGeometry(QRect(20, 10, 211, 17));
        advanced = new QRadioButton(groupBox);
        advanced->setObjectName(QStringLiteral("advanced"));
        advanced->setGeometry(QRect(20, 50, 251, 17));
        hardcore = new QRadioButton(groupBox);
        hardcore->setObjectName(QStringLiteral("hardcore"));
        hardcore->setGeometry(QRect(20, 90, 241, 17));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(130, 340, 21, 16));
        tax = new QLabel(frame_2);
        tax->setObjectName(QStringLiteral("tax"));
        tax->setGeometry(QRect(160, 340, 61, 20));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(120, 360, 31, 16));
        total = new QLabel(frame_2);
        total->setObjectName(QStringLiteral("total"));
        total->setGeometry(QRect(160, 360, 61, 20));
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 300, 75, 23));
        spinBox = new QSpinBox(frame_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(200, 260, 42, 22));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(120, 260, 71, 16));
        purchase = new QPushButton(frame_2);
        purchase->setObjectName(QStringLiteral("purchase"));
        purchase->setGeometry(QRect(140, 390, 75, 23));
        maintenanceButton = new QRadioButton(frame_2);
        maintenanceButton->setObjectName(QStringLiteral("maintenanceButton"));
        maintenanceButton->setGeometry(QRect(60, 220, 211, 20));
        Maintenance = new QLabel(tab_4);
        Maintenance->setObjectName(QStringLiteral("Maintenance"));
        Maintenance->setGeometry(QRect(460, 150, 241, 221));
        tabWidget->addTab(tab_4, QString());
        contactus = new QPushButton(centralwidget);
        contactus->setObjectName(QStringLiteral("contactus"));
        contactus->setGeometry(QRect(360, 550, 81, 23));
        iRobotUser->setCentralWidget(centralwidget);
        contactus->raise();
        tabWidget->raise();
        menubar = new QMenuBar(iRobotUser);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        iRobotUser->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionLog_out);
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionUser_Guide);

        retranslateUi(iRobotUser);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(iRobotUser);
    } // setupUi

    void retranslateUi(QMainWindow *iRobotUser)
    {
        iRobotUser->setWindowTitle(QApplication::translate("iRobotUser", "MainWindow", 0));
        actionLog_out->setText(QApplication::translate("iRobotUser", "Log out", 0));
        actionLog_out->setShortcut(QApplication::translate("iRobotUser", "Ctrl+L", 0));
        actionQuit->setText(QApplication::translate("iRobotUser", "Quit", 0));
        actionQuit->setShortcut(QApplication::translate("iRobotUser", "Ctrl+Q", 0));
        actionUser_Guide->setText(QApplication::translate("iRobotUser", "User Guide", 0));
        actionUser_Guide->setShortcut(QApplication::translate("iRobotUser", "Ctrl+H", 0));
        conceptofOperations->setText(QString());
        label->setText(QApplication::translate("iRobotUser", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">iRobot</span></p></body></html>", 0));
        requestAccount->setText(QApplication::translate("iRobotUser", "Request Account", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("iRobotUser", "Home", 0));
        requestBrochure->setText(QApplication::translate("iRobotUser", "Request Brochure", 0));
        printBrochure->setText(QApplication::translate("iRobotUser", "Print Brochure", 0));
        label_2->setText(QApplication::translate("iRobotUser", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Sales Pitch</span></p></body></html>", 0));
        salesPitch->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("iRobotUser", "Sales Pitch", 0));
        label_3->setText(QApplication::translate("iRobotUser", "List of Environments", 0));
        envitemnetList->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("iRobotUser", "List of Environments", 0));
        guaranteePolicyLabel->setText(QString());
        label_4->setText(QApplication::translate("iRobotUser", "Guarantee Policy", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("iRobotUser", "Guarantee Policy", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("iRobotUser", "Product Info", 0));
        addTestimonial->setText(QApplication::translate("iRobotUser", "Add Testimonial", 0));
        textEdit->setPlaceholderText(QApplication::translate("iRobotUser", "Enter your testimonial here", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("iRobotUser", "Testimonials", 0));
        groupBox->setTitle(QString());
        basic->setText(QApplication::translate("iRobotUser", "Basic Model - $199.99", 0));
        advanced->setText(QApplication::translate("iRobotUser", "Advanced Robotnics - $249.99", 0));
        hardcore->setText(QApplication::translate("iRobotUser", "Hardcore Herobot - $299.99", 0));
        label_7->setText(QApplication::translate("iRobotUser", "Tax:", 0));
        tax->setText(QString());
        label_6->setText(QApplication::translate("iRobotUser", "Total:", 0));
        total->setText(QString());
        pushButton->setText(QApplication::translate("iRobotUser", "Calculate", 0));
        label_5->setText(QApplication::translate("iRobotUser", "# of robots:", 0));
        purchase->setText(QApplication::translate("iRobotUser", "Purchase", 0));
        maintenanceButton->setText(QApplication::translate("iRobotUser", "Maintenance Plan $42,852.60", 0));
        Maintenance->setText(QApplication::translate("iRobotUser", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("iRobotUser", "Purchase", 0));
        contactus->setText(QApplication::translate("iRobotUser", "Contact Us", 0));
        menuFile->setTitle(QApplication::translate("iRobotUser", "File", 0));
        menuHelp->setTitle(QApplication::translate("iRobotUser", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class iRobotUser: public Ui_iRobotUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IROBOTUSER_H
