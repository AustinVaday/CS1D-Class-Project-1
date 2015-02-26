#include "Wine.h"



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


