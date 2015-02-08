#include "navigatingapp.h"
#include "ui_navigatingapp.h"

NavigatingApp::NavigatingApp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NavigatingApp)
{
    ui->setupUi(this);
}

NavigatingApp::~NavigatingApp()
{
    delete ui;
}

void NavigatingApp::editText()
{
    ui->textBrowser->setReadOnly(false);
}
