#ifndef WINERIE_H
#define WINERIE_H

#include <QString>
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
};

class Winery
{
public:

    Winery();
    Winery(QString newName, SortedList<intStruct, float> newDistances, SortedList<Wine, QString> newList, float distanceToVilla);
    ~Winery();

    void SetName(QString newName);
    void SetDistances(SortedList<intStruct, float> newMap);
    void SetWineList(SortedList<Wine, QString> newWines);
    void AddWine(Wine newWine);
    void AddDistance(int wineryNum, float distanceTo);
    void RemoveWine(QString removeName);
    void RemoveDistance(int wineryNum);

    QString GetName() const;
    Wine SearchWine(QString searchWine);
    SortedList<Wine, QString> GetWines() const;

    int ShortestWineryNumTo() const;
private:
    QString name;
    float distanceToCanyonVilla;
//    QQueue<int>  distance;

    // Map that sorts wineries by distance!
    SortedList<intStruct, float> distanceMap;       // int: the winery number to compare to
                                                    // float: the distance to the winery

    SortedList<Wine, QString> wines;
};

#endif // WINERIE_H
