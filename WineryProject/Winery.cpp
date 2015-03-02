#include "Winery.h"
#include <QDebug>
Winery::Winery(QString newName, int newWineryNum, QMap<float, int> newDistances, QMap<QString, Wine> newList, float distanceToVilla)
        : name(newName), wineryNum(newWineryNum), distanceMap(newDistances),  distanceToCanyonVilla(distanceToVilla), wines(newList)
{
//    distance = newDistances;
//    wines = newList;
}


Winery::Winery() : name(""), distanceToCanyonVilla(0.0), wineryNum(0)
{

}

Winery::~Winery()
{

}

void Winery::SetName(QString newName)
{
    name = newName;
}

void Winery::SetDistances(QMap<float, int> newMap)
{
   distanceMap = newMap;
}
void Winery::setDistanceToVilla(int villaDist)
{
   distanceToCanyonVilla = villaDist;
}

void Winery::SetWineList(QMap<QString, Wine> newWines)
{
    wines = newWines;
}
void Winery::SetWineryNum(int newWineryNum)
{
    wineryNum = newWineryNum;
}

int Winery::GetWineryNum() const
{
    return wineryNum;
}
void Winery::AddWine(Wine newWine)
{
    wines.insert(newWine.GetName(), newWine);
//    wines.Add(newWine, newWine.GetName());
}

void Winery::AddDistance(int wineryNum, float distanceTo)
{

    distanceMap.insert(distanceTo, wineryNum);

    qDebug() << "INSIDE WINERY: AddDistance, inserted value" << wineryNum << "and: "<< distanceTo;
//    distanceMap[distanceTo] = wineryNum;
}


void Winery::RemoveWine(QString removeName)
{
    wines.remove(removeName);
}

void Winery::RemoveDistance(int wineryNum)
{
//    distanceMap.re
    // got to find the int val :(
//    distanceMap.remove();
}

QString Winery::GetName() const
{
    return name;
}

const QMap<float, int>& Winery::GetDistances() const
{
    return distanceMap;
}

float Winery::GetDistanceToVilla() const
{
    return distanceToCanyonVilla;
}
Wine Winery::SearchWine(QString searchWine)
{
    return wines[searchWine];
}

QMap<QString, Wine> Winery::GetWines() const
{
    return wines;
}

int Winery::ShortestWineryNumTo() const
{
    // since the first distance at index 0 is 0.0 (the distance
    // to itself), we will ignore this and will instead
    // treat the next distance as the shortest winery num dist.
    return (distanceMap.begin() + 1).value();
}
