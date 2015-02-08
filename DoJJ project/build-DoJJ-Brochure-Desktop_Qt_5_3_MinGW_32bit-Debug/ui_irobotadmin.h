/********************************************************************************
** Form generated from reading UI file 'irobotadmin.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IROBOTADMIN_H
#define UI_IROBOTADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_irobotAdmin
{
public:
    QAction *actionLog_out;
    QAction *actionQuit;
    QAction *actionUser_Guide;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *tab_3;
    QFrame *frame_6;
    QLabel *label_6;
    QPlainTextEdit *testiText;
    QListWidget *testiList;
    QPushButton *approveButton;
    QPushButton *denyButton;
    QWidget *tab_4;
    QLabel *label;
    QFrame *frame;
    QTableWidget *customerTable;
    QPushButton *printList;
    QPushButton *editList;
    QWidget *tab_5;
    QFrame *frame_2;
    QLabel *label_2;
    QListWidget *contactUsList;
    QFrame *frame_3;
    QLabel *label_3;
    QPushButton *deleteMessage;
    QTextBrowser *contactUsText;
    QWidget *tab_6;
    QFrame *frame_4;
    QListWidget *listWidget_2;
    QLabel *label_4;
    QFrame *frame_5;
    QTextBrowser *textBrowser_2;
    QLabel *label_5;
    QPushButton *approveTestimonial;
    QPushButton *approveTestimonial_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *irobotAdmin)
    {
        if (irobotAdmin->objectName().isEmpty())
            irobotAdmin->setObjectName(QStringLiteral("irobotAdmin"));
        irobotAdmin->resize(800, 600);
        irobotAdmin->setMinimumSize(QSize(800, 600));
        irobotAdmin->setMaximumSize(QSize(800, 600));
        actionLog_out = new QAction(irobotAdmin);
        actionLog_out->setObjectName(QStringLiteral("actionLog_out"));
        actionQuit = new QAction(irobotAdmin);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionUser_Guide = new QAction(irobotAdmin);
        actionUser_Guide->setObjectName(QStringLiteral("actionUser_Guide"));
        centralwidget = new QWidget(irobotAdmin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 780, 560));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(220, 90, 320, 40));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(270, 240, 200, 31));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        frame_6 = new QFrame(tab_3);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setGeometry(QRect(19, 19, 731, 501));
        frame_6->setFrameShape(QFrame::Box);
        frame_6->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame_6);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 10, 91, 31));
        testiText = new QPlainTextEdit(frame_6);
        testiText->setObjectName(QStringLiteral("testiText"));
        testiText->setGeometry(QRect(170, 40, 541, 451));
        testiList = new QListWidget(frame_6);
        testiList->setObjectName(QStringLiteral("testiList"));
        testiList->setGeometry(QRect(10, 40, 151, 451));
        approveButton = new QPushButton(frame_6);
        approveButton->setObjectName(QStringLiteral("approveButton"));
        approveButton->setGeometry(QRect(560, 10, 75, 23));
        denyButton = new QPushButton(frame_6);
        denyButton->setObjectName(QStringLiteral("denyButton"));
        denyButton->setGeometry(QRect(640, 10, 75, 23));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label = new QLabel(tab_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 25, 191, 21));
        frame = new QFrame(tab_4);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(15, 15, 750, 401));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        customerTable = new QTableWidget(frame);
        customerTable->setObjectName(QStringLiteral("customerTable"));
        customerTable->setGeometry(QRect(15, 40, 720, 350));
        customerTable->setSortingEnabled(true);
        customerTable->horizontalHeader()->setCascadingSectionResizes(false);
        customerTable->horizontalHeader()->setDefaultSectionSize(125);
        customerTable->horizontalHeader()->setMinimumSectionSize(50);
        customerTable->horizontalHeader()->setStretchLastSection(true);
        customerTable->verticalHeader()->setStretchLastSection(false);
        printList = new QPushButton(tab_4);
        printList->setObjectName(QStringLiteral("printList"));
        printList->setGeometry(QRect(175, 450, 200, 50));
        editList = new QPushButton(tab_4);
        editList->setObjectName(QStringLiteral("editList"));
        editList->setGeometry(QRect(425, 450, 200, 50));
        tabWidget->addTab(tab_4, QString());
        frame->raise();
        label->raise();
        printList->raise();
        editList->raise();
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        frame_2 = new QFrame(tab_5);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(20, 20, 211, 501));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(12, 10, 121, 21));
        contactUsList = new QListWidget(frame_2);
        contactUsList->setObjectName(QStringLiteral("contactUsList"));
        contactUsList->setGeometry(QRect(10, 40, 191, 441));
        frame_3 = new QFrame(tab_5);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(249, 19, 511, 501));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 121, 21));
        deleteMessage = new QPushButton(frame_3);
        deleteMessage->setObjectName(QStringLiteral("deleteMessage"));
        deleteMessage->setGeometry(QRect(420, 10, 75, 23));
        contactUsText = new QTextBrowser(frame_3);
        contactUsText->setObjectName(QStringLiteral("contactUsText"));
        contactUsText->setGeometry(QRect(10, 40, 491, 441));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        frame_4 = new QFrame(tab_6);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(21, 21, 211, 501));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        listWidget_2 = new QListWidget(frame_4);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(10, 40, 191, 451));
        label_4 = new QLabel(frame_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(12, 10, 141, 21));
        frame_5 = new QFrame(tab_6);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(250, 20, 511, 501));
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Raised);
        textBrowser_2 = new QTextBrowser(frame_5);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(10, 40, 491, 451));
        label_5 = new QLabel(frame_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 141, 21));
        approveTestimonial = new QPushButton(frame_5);
        approveTestimonial->setObjectName(QStringLiteral("approveTestimonial"));
        approveTestimonial->setGeometry(QRect(384, 10, 111, 23));
        approveTestimonial_2 = new QPushButton(frame_5);
        approveTestimonial_2->setObjectName(QStringLiteral("approveTestimonial_2"));
        approveTestimonial_2->setGeometry(QRect(260, 10, 111, 23));
        tabWidget->addTab(tab_6, QString());
        irobotAdmin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(irobotAdmin);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        irobotAdmin->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionLog_out);
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionUser_Guide);

        retranslateUi(irobotAdmin);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(irobotAdmin);
    } // setupUi

    void retranslateUi(QMainWindow *irobotAdmin)
    {
        irobotAdmin->setWindowTitle(QApplication::translate("irobotAdmin", "Admin Console", 0));
        actionLog_out->setText(QApplication::translate("irobotAdmin", "Log out", 0));
        actionLog_out->setShortcut(QApplication::translate("irobotAdmin", "Ctrl+L", 0));
        actionQuit->setText(QApplication::translate("irobotAdmin", "Quit", 0));
        actionQuit->setShortcut(QApplication::translate("irobotAdmin", "Ctrl+Q", 0));
        actionUser_Guide->setText(QApplication::translate("irobotAdmin", "User Guide", 0));
        actionUser_Guide->setShortcut(QApplication::translate("irobotAdmin", "Ctrl+H", 0));
        label_7->setText(QApplication::translate("irobotAdmin", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">Welcome to the Admin Console</span></p></body></html>", 0));
        label_8->setText(QApplication::translate("irobotAdmin", "<html><head/><body><p><span style=\" font-size:12pt;\">Select a tab and get started!</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("irobotAdmin", "Home", 0));
        label_6->setText(QApplication::translate("irobotAdmin", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Testimonials:</span></p></body></html>", 0));
        approveButton->setText(QApplication::translate("irobotAdmin", "Approve", 0));
        denyButton->setText(QApplication::translate("irobotAdmin", "Deny", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("irobotAdmin", "Testimonials", 0));
        label->setText(QApplication::translate("irobotAdmin", "<html><head/><body><p><span style=\" font-size:12pt; text-decoration: underline;\">List of Current Customers</span></p></body></html>", 0));
        printList->setText(QApplication::translate("irobotAdmin", "Print Customers List", 0));
        editList->setText(QApplication::translate("irobotAdmin", "Edit Customers List", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("irobotAdmin", "Customer List", 0));
        label_2->setText(QApplication::translate("irobotAdmin", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">List of Messages:</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("irobotAdmin", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Message Display:</span></p></body></html>", 0));
        deleteMessage->setText(QApplication::translate("irobotAdmin", "Delete", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("irobotAdmin", "View Messages", 0));
        label_4->setText(QApplication::translate("irobotAdmin", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Pending Accounts:</span></p></body></html>", 0));
        textBrowser_2->setHtml(QApplication::translate("irobotAdmin", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'.Helvetica Neue DeskInterface'; font-size:13pt;\"><br /></p></body></html>", 0));
        label_5->setText(QApplication::translate("irobotAdmin", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Account Display:</span></p></body></html>", 0));
        approveTestimonial->setText(QApplication::translate("irobotAdmin", "Approve Account", 0));
        approveTestimonial_2->setText(QApplication::translate("irobotAdmin", "Deny Account", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("irobotAdmin", "Pending Accounts", 0));
        menuFile->setTitle(QApplication::translate("irobotAdmin", "File", 0));
        menuHelp->setTitle(QApplication::translate("irobotAdmin", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class irobotAdmin: public Ui_irobotAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IROBOTADMIN_H
