#ifndef WINERIE_H
#define WINERIE_H

#include <qstring.h>
#include "SortedList.h"
#include "Wine.h"

struct Distance
{
	int dist;
	string name;
};
class Winery
{
public:

    Winery();
    Winery(QString newName, int newX, int newY, SortedList<Wine, int> newList);
    ~Winery();

    int DistanceFrom(string);
    void SetName(QString newName);

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
    SortedList<Distance, int> distances;
    SortedList<Wine, int> wines;
};



Winery::Winery(QString newName, int newX, int newY, SortedList<Wine, int> newList)
        : name(newName), posX(newX), posY(newY)
{
//    wines = newList; need overloaded assignment operator


//    for (int i = 0; i < newList.Size(); i++)
//    {
//        wines.Add(newList[i], );
//    }
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
