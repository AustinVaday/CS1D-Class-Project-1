#ifndef OTHERINFO_H
#define OTHERINFO_H

#include <QWidget>

namespace Ui {
class otherInfo;
}

class otherInfo : public QWidget
{
    Q_OBJECT

public:
    // Default constructor
    explicit otherInfo(QWidget *parent = 0);
    // Non-default constructor
    // Takes in INT to determine the response given to the user
    otherInfo(QWidget *parent, int responseType);
    // Destructor
    ~otherInfo();

private slots:
    // Function triggered when okay button is pressed
    void on_okay_clicked();

private:
    Ui::otherInfo *ui;
};

#endif // OTHERINFO_H
