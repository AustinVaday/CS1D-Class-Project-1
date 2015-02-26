#include "Winery.h"

Winery::Winery(QString newName, SortedList<intStruct, float> newDistances, SortedList<Wine, QString> newList, float distanceToVilla)
        : name(newName), distanceMap(newDistances),  distanceToCanyonVilla(distanceToVilla), wines(newList)
{
//    distance = newDistances;
//    wines = newList;
}


Winery::Winery() : name(""), distanceToCanyonVilla(0.0)
{

}

Winery::~Winery()
{

}

void Winery::SetName(QString newName)
{
    name = newName;
}

void Winery::SetDistances(SortedList<intStruct, float> newMap)
{
   distanceMap = newMap;
}
void Winery::setDistanceToVilla(int villaDist)
{
   distanceToCanyonVilla = villaDist;
}

void Winery::SetWineList(SortedList<Wine, QString> newWines)
{
    wines = newWines;
}

void Winery::AddWine(Wine newWine)
{
    wines.Add(newWine, newWine.GetName());
}

void Winery::AddDistance(int wineryNum, float distanceTo)
{
    intStruct integer;

    integer.val = wineryNum;

    distanceMap.Add(integer, distanceTo);
}


void Winery::RemoveWine(QString removeName)
{
    wines.Remove(removeName);
}

void Winery::RemoveDistance(int wineryNum)
{
//    distanceMap.re
}

QString Winery::GetName() const
{
    return name;
}

SortedList<intStruct, float> Winery::GetDistances() const
{
    return distanceMap;
}

float Winery::GetDistanceToVilla() const
{
    return distanceToCanyonVilla;
}
Wine Winery::SearchWine(QString searchWine)
{
    return wines.SearchFor(searchWine);
}

SortedList<Wine, QString> Winery::GetWines() const
{
    return wines;
}

int Winery::ShortestWineryNumTo() const
{
    // since the first distance at index 0 is 0.0 (the distance
    // to itself), we will ignore this and will instead
    // treat the next distance as the shortest winery num dist.
    return (distanceMap[1]).val;
}
