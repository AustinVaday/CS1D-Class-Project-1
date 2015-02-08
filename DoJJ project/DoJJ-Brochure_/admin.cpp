#include "admin.h"

Admin::Admin(QString newName) : User(newName)
{
}

Admin::Admin(Customer<QString> newCust,QString newName): User(newName), cust(newCust)
{
}

Admin::~Admin()
{
}

void Admin::SetCustomer(Customer<QString> newCust)
{
    cust = newCust;
}

Customer<QString> Admin::GetCust()
{
    return cust;
}

