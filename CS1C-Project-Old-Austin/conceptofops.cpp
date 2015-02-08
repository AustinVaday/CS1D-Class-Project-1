#include "conceptofops.h"
#include "ui_conceptofops.h"

ConceptOfOps::ConceptOfOps(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConceptOfOps)
{
    ui->setupUi(this);
}

ConceptOfOps::~ConceptOfOps()
{
    delete ui;
}
