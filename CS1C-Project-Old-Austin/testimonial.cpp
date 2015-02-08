#include "testimonial.h"
#include "ui_testimonial.h"
#include <QIcon>

Testimonial::Testimonial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Testimonial)
{
    /* AUSTIN VADAY EDITED THIS WHOLE CLASS */

    ui->setupUi(this);
    testimonial = new QString;

    ui->custTest->setAcceptRichText(true);
    ui->custTest->setText(*testimonial);
    ui->custTest->setReadOnly(true);

    ui->submitForm->setAcceptRichText(true);
    ui->submitForm->setReadOnly(false);
}


Testimonial::~Testimonial()
{
    emit returnString(*testimonial);
    delete ui;
    delete testimonial;
}

void Testimonial::on_write_clicked()
{
    QString name;
    QString interestRating;

    /* CHANGED THIS CODE */
    if (!ui->submitForm->toPlainText().isEmpty())
    {
        *testimonial += '\n' + ui->submitForm->toPlainText();
        name = ui->nameLine->text();

        if (name.isEmpty())
        {
            name = "Anonymous";
        }
        ui->nameLine->clear();
        ui->custTest->clear();
        ui->submitForm->clear();
        this->clearRadioButtons(); /*ADDED BY AUSTIN */

        /*ADDED BY AUSTIN */
        if (ui->veryInterested->isChecked())
        {
            interestRating = "Very Interested";
        }
        else if (ui->somewhatInterested->isChecked())
        {
            interestRating = "Somewhat Interested";
        }
        else if (ui->notInterested->isChecked())
        {
            interestRating = "Not Interested";

        }
        else if (ui->neverCallAgain->isChecked())
        {
            interestRating = "Never Call Again";
        }
        // else if nothing checked
        else
        {
            interestRating = "None Selected";
        }

        ui->custTest->setReadOnly(false);
        *testimonial += "\nInterest rating: " + interestRating;


        *testimonial += "\n- " + name;
        ui->custTest->setText(*testimonial);
        ui->custTest->setReadOnly(true);
    }

}

void Testimonial::setTestimonial(QString input)
{
    if(testimonial != 0)
    {
        *testimonial = input;
    }
}

QString Testimonial::getTestimonial() const
{
    QString returnStr;
    returnStr.clear();
    if(testimonial != 0)
    {
        returnStr = *testimonial;
    }

    return returnStr;
}

void Testimonial::on_veryInterested_clicked()
{
    ui->veryInterested->setChecked(true);
    ui->somewhatInterested->setChecked(false);
    ui->notInterested->setChecked(false);
    ui->neverCallAgain->setChecked(false);
}

void Testimonial::on_somewhatInterested_clicked()
{
    ui->veryInterested->setChecked(false);
    ui->somewhatInterested->setChecked(true);
    ui->notInterested->setChecked(false);
    ui->neverCallAgain->setChecked(false);
}

void Testimonial::on_notInterested_clicked()
{
    ui->veryInterested->setChecked(false);
    ui->somewhatInterested->setChecked(false);
    ui->notInterested->setChecked(true);
    ui->neverCallAgain->setChecked(false);
}

void Testimonial::on_neverCallAgain_clicked()
{
    ui->veryInterested->setChecked(false);
    ui->somewhatInterested->setChecked(false);
    ui->notInterested->setChecked(false);
    ui->neverCallAgain->setChecked(true);
}

void Testimonial::clearRadioButtons()
{
    ui->veryInterested->setChecked(false);
    ui->somewhatInterested->setChecked(false);
    ui->notInterested->setChecked(false);
    ui->neverCallAgain->setChecked(false);
}
