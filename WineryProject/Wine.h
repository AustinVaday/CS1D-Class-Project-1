#ifndef WINE_H
#define WINE_H

#include <qstring.h>

class Wine
{
public:

    Wine();
    Wine(QString newName, int newYear, int newPrice);
    ~Wine();

    void SetName(QString newName);
    void SetYear(int newYear);
    void SetPrice(int newPrice);
    QString GetName() const;
    int GetYear() const;
    int GetPrice() const;


private:
    QString name;
    int year;
    int price;

};


#endif // WINE_H
