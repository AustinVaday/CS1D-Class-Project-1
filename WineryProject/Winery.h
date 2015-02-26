#ifndef WINERIE_H
#define WINERIE_H

#include <qstring.h>
#include <qqueue.h>
#include "SortedList.h"
#include "Wine.h"

class Winery
{
public:

    Winery();
    Winery(QString newName, QQueue<int> newDistances, SortedList<Wine, QString> newList);
    ~Winery();

    void SetName(QString newName);
    void SetDistances(QQueue<int> wholeList);
    void SetWineList(SortedList<Wine, QString> newWines);
    void AddWine(Wine newWine);
    void AddDistance(int newDistance);
    void RemoveWine(QString removeName);

    QString GetName() const;
    Wine SearchWine(QString searchWine);
    SortedList<Wine, QString> GetWines() const;


private:
    QString name;
    QQueue<int>  distance;
    SortedList<Wine, QString> wines;
};

#endif // WINERIE_H
