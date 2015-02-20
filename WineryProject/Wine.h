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

Wine::Wine() : name(""), year(0), price(0)
{

}

Wine::Wine(QString newName, int newYear, int newPrice)
       : name (newName), year(newYear), price (newPrice)
{
    SetName(newName);
    SetYear(newYear);
    SetPrice(newPrice);
}

Wine::~Wine()
{

}

void Wine::SetName(QString newName)
{
    name = newName;
}

void Wine::SetYear(int newYear)
{
    year = newYear;
}

void Wine::SetPrice(int newPrice)
{
    price = newPrice;
}

QString Wine::GetName() const
{
    return name;
}

int Wine::GetYear() const
{
    return year;
}

int Wine::GetPrice() const
{
    return price;
}



#endif // WINE_H
