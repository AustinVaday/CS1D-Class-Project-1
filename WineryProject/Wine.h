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

Wine::Wine()
{

}

Wine::Wine(QString newName, int newYear, int newPrice)
       : name (newName), year(newYear), price (newPrice)
{

}

Wine::~Wine()
{

}

void Wine::SetName(QString newName)
{

}

void Wine::SetYear(int newYear)
{

}

void Wine::SetPrice(int newPrice)
{

}

QString Wine::GetName() const
{

}

int Wine::GetYear() const
{

}

int Wine::GetPrice() const
{

}



#endif // WINE_H
