#ifndef WINERIE_H
#define WINERIE_H

#include <QString>
#include <QMap>
#include <QQueue>
#include "SortedList.h"
#include "Wine.h"

// this is mainly used because of how the sorted list
// was designed to take in an object parameter.
// It won't let me use an int, hence I created a struct.
struct intStruct
{
    int val;
    int GetName(){ return val;} // returns integer value..
    bool operator==(const intStruct &other) { return (val == other.val);}
};

class Winery
{
public:

    Winery();
    Winery(QString newName, int newWineryNum, QMap<float, int> newDistances, QMap<QString, Wine> newList, float distanceToVilla);
    ~Winery();

    void SetName(QString newName);
    void SetDistances(QMap<float, int> newMap);
    void setDistanceToVilla(int villaDist);
    void SetWineList(QMap<QString, Wine> newWines);
    void SetWineryNum(int newWineryNum);
    void AddWine(Wine newWine);
    void AddDistance(int wineryNum, float distanceTo);
    void RemoveWine(QString removeName);
    void RemoveDistance(int wineryNum);

    QString GetName() const;
    int  GetWineryNum() const;
    const QMap<float, int>& GetDistances() const;
    float GetDistanceToVilla() const;

    Wine SearchWine(QString searchWine);
    QMap<QString, Wine> GetWines() const;

    int ShortestWineryNumTo() const;
private:
    QString name;
    float distanceToCanyonVilla;
    int wineryNum;
//    QQueue<int>  distance;

    // Map that sorts wineries by distance!
    QMap<float, int> distanceMap;                 // int: the winery number to compare to
                                                    // float: the distance to the winery (SORTED BY THIS)

    QMap<QString, Wine> wines;
};

#endif // WINERIE_H
