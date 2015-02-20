#ifndef WINERIE_H
#define WINERIE_H

#include <qstring.h>
#include "SortedList.h"
#include "Wine.h"

class Winery
{
public:

    Winery();
    Winery(QString newName, int newX, int newY, SortedList<Wine, Int> newList);
    ~Winery();

    int DistanceFrom(int x, int y);
    void SetName(QString newName);
    void SetPosX(int newX);
    void SetPosY(int newY);
    void SetPosition(int newX, int newY);
    void SetWineList(SortedList<Wine, Int> newWines);
    void AddWine(Wine newWine);
    void RemoveWine(QString removeName);

    QString GetName() const;
    int GetX() const;
    int GetY() const;
    Wine GetWine() const;


private:
    QString name;
    int posX;
    int posY;
    SortedList<Wine, Int> wines;
};



Winery::Winery(QString newName, int newX, int newY, SortedList<Wine, Int> newList)
{

}


Winery::Winery()
{

}

Winery::~Winery()
{

}

int Winery::DistanceFrom(int x, int y)
{

}

void Winery::SetName(QString newName)
{
    name = newName;
}

void Winery::SetPosX(int newX)
{
    posX = newX;
}

void Winery::SetPosY(int newY)
{
    posY = newY;
}

void Winery::SetPosition(int newX, int newY)
{
    posX = newX;
    posY = newY;
}

void Winery::SetWineList(SortedList<Wine, Int> newWines)
{
    wines = newWines;
}

void Winery::AddWine(Wine newWine)
{
    wines.Add(newWine);
}
\
bool Winery::RemoveWine(QString removeName)
{
    return wines.Remove(removeName);
}


QString Winery::GetName() const
{

}

int Winery::GetX() const
{

}

int Winery::GetY() const
{

}

Wine Winery::GetWine() const
{

}








#endif // WINERIE_H