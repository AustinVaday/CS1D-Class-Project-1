#ifndef CUSTOMERCLASS_H
#define CUSTOMERCLASS_H
#include "userclass.h"
#include <QString>
#include <QTextStream>

class Customer : public User
{

    public:
        Customer();
        // default constructor

        Customer(QString userName,
                             QString customerAddress,
                             QString initInterest,
                             QString key,
                             QString password,
                             QString email,
                             long    accountNum);
        // Nondefault constructor

        bool operator >(const Customer& otherCustomer) const;
        // Overloading comparison operator greater than

        bool operator <(const Customer& otherCustomer) const;
        // Overloading comparison operator less than

        // ACCESSORS

        QString getFullAddress()  const;
        QString getAddressLine1() const;
        QString getAddressLine2() const;
        QString getKey()           const;
        QString getInterest()   const;

        // MUTATORS
        void setInterest(QString newInterest);
        void setAddress(QString newAddress);
        void setAddressLine1(QString customerAddress);
        void setAddressLine2(QString customerAddress);
        void setKey(QString key);
        void separateAddress();

    private:
        QString address1;
        QString address2;
        QString interest;
        QString keyCustomer;

};


#endif // CUSTOMERCLASS_H
