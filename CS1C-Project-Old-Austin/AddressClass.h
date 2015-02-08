#ifndef CUSTOMERDATACLASS_H
#define CUSTOMERDATACLASS_H
#include <QString>
#include <userclass.h>

class AddressClass
{
public:
    AddressClass();
    AddressClass(QString stree,
                 QString city,
                 int     zipCode,
                  QString state);
    virtual ~AddressClass();

    // ACCESSORS
    virtual QString getStreet()  const;
    virtual QString getCity()    const;
    virtual int     getZipCode() const;
    virtual QString getState()   const;

    // MUTATORS
    virtual QString setStreet(QString newStreet);
    virtual QString setCity(QString setCity);
    virtual QString setZipCode(int newZip);
    virtual QString setState(QString newState);



private:
    QString stree;
    QString city;
    int     zipCode;
    QString state;
};

#endif // CUSTOMERDATACLASS_H
