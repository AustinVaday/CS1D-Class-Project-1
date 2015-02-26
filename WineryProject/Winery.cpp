#include "Winery.h"

Winery::Winery(QString newName, QQueue<int> newDistances, SortedList<Wine, QString> newList)
        : name(newName)
{
    distance = newDistances;
    wines = newList;
}


Winery::Winery() : name("")
{

}

Winery::~Winery()
{

}

void Winery::SetName(QString newName)
{
    name = newName;
}

void Winery::SetWineList(SortedList<Wine, QString> newWines)
{
    wines = newWines;
}

void Winery::AddWine(Wine newWine)
{
    wines.Add(newWine, newWine.GetName());
}

void AddDistance(int newDistance)
{

}


void Winery::RemoveWine(QString removeName)
{
    wines.Remove(removeName);
}


QString Winery::GetName() const
{
    return name;
}

Wine Winery::SearchWine(QString searchWine)
{
    return wines.SearchFor(searchWine);
}

SortedList<Wine, QString> Winery::GetWines() const
{
    return wines;
}
