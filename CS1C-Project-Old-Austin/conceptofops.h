#ifndef CONCEPTOFOPS_H
#define CONCEPTOFOPS_H

#include <QDialog>

namespace Ui {
class ConceptOfOps;
}

class ConceptOfOps : public QDialog
{
    Q_OBJECT

public:
    explicit ConceptOfOps(QWidget *parent = 0);
    ~ConceptOfOps();

private:
    Ui::ConceptOfOps *ui;
};

#endif // CONCEPTOFOPS_H
