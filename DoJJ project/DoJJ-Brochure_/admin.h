#ifndef ADMIN_H
#define ADMIN_H
#include "BigHead.h"

class Admin : public User
{
public:
    Admin(QString newName);
    Admin(Customer<QString> newCust, QString newName);
    ~Admin();

    void SetCustomer(Customer<QString> newCust);
    Customer<QString> GetCust();

private:
    Customer<QString> cust;
};

#endif // ADMIN_H
