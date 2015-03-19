/********************************************************************************
** Form generated from reading UI file 'helpwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPWINDOW_H
#define UI_HELPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpWindow
{
public:
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *page_5;
    QLabel *label_7;
    QWidget *page_6;
    QLabel *label_8;
    QWidget *page_7;
    QLabel *label_9;
    QWidget *page_8;
    QLabel *label_10;
    QPushButton *nextTextButton;
    QPushButton *nextTextButton_2;

    void setupUi(QWidget *HelpWindow)
    {
        if (HelpWindow->objectName().isEmpty())
            HelpWindow->setObjectName(QStringLiteral("HelpWindow"));
        HelpWindow->resize(743, 554);
        label = new QLabel(HelpWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 110, 361, 20));
        stackedWidget = new QStackedWidget(HelpWindow);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(190, 180, 311, 241));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        label_7 = new QLabel(page_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(110, 90, 81, 20));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        label_8 = new QLabel(page_6);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(110, 100, 81, 20));
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        label_9 = new QLabel(page_7);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(90, 110, 81, 20));
        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        label_10 = new QLabel(page_8);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(100, 100, 81, 20));
        stackedWidget->addWidget(page_8);
        nextTextButton = new QPushButton(HelpWindow);
        nextTextButton->setObjectName(QStringLiteral("nextTextButton"));
        nextTextButton->setGeometry(QRect(280, 460, 113, 32));
        nextTextButton_2 = new QPushButton(HelpWindow);
        nextTextButton_2->setObjectName(QStringLiteral("nextTextButton_2"));
        nextTextButton_2->setGeometry(QRect(440, 460, 113, 32));

        retranslateUi(HelpWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(HelpWindow);
    } // setupUi

    void retranslateUi(QWidget *HelpWindow)
    {
        HelpWindow->setWindowTitle(QApplication::translate("HelpWindow", "Form", 0));
        label->setText(QApplication::translate("HelpWindow", "No help currently available, please come back later.", 0));
        label_7->setText(QApplication::translate("HelpWindow", "First Page", 0));
        label_8->setText(QApplication::translate("HelpWindow", "Second Page", 0));
        label_9->setText(QApplication::translate("HelpWindow", "Third Page", 0));
        label_10->setText(QApplication::translate("HelpWindow", "Fourth Page", 0));
        nextTextButton->setText(QApplication::translate("HelpWindow", "Next Text", 0));
        nextTextButton_2->setText(QApplication::translate("HelpWindow", "GoTo3rd", 0));
    } // retranslateUi

};

namespace Ui {
    class HelpWindow: public Ui_HelpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWINDOW_H
