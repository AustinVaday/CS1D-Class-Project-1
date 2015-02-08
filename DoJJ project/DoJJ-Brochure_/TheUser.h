#ifndef THEUSER_H
#define THEUSER_H

#include "BigHead.h"

class User
{
public:
    User(QString name);
    ~User();

    void    SetName(QString newName);
    QString GetName();
    void    Print();

private:
    QString name;
    
};


#endif // THEUSER_H
