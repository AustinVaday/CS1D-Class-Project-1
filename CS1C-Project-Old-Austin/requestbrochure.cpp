#include "requestbrochure.h"
#include "ui_requestbrochure.h"

RequestBrochure::RequestBrochure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RequestBrochure)
{
    ui->setupUi(this);
}

RequestBrochure::~RequestBrochure()
{
    delete ui;
}

void RequestBrochure::editText()
{
    ui->textBrowser->setReadOnly(false);
}
