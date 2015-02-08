#include "test.h"
#include "otherinfo.h"
#include "ui_test.h"

test::test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);
}

test::~test()
{
    delete ui;
}

void test::on_buttonBox_accepted()
{
    otherInfo *c = new otherInfo;
    c->show();
    test.close();
}
