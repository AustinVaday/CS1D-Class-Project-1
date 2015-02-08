#include "customerclass.h"
#include <QDebug>

Customer::Customer()
{

}

Customer::Customer(QString userName,
                   QString customerAddress,
                   QString initInterest,
                   QString key,
                   QString password,
                   QString email,
                   long    accountNum)
{
    User::setUserName(userName);
    User::setEmail(email);
    User::setAccountNum(accountNum);
    User::setPassword(password);

    setAddress(customerAddress);

    interest    = initInterest;
    keyCustomer = key;
}

bool Customer::operator >(const Customer& otherCustomer) const
{
    return this->getUserName() > otherCustomer.getUserName();
}

bool Customer::operator <(const Customer& otherCustomer) const
{
    return this->getUserName() < otherCustomer.getUserName();
}

QString Customer::getFullAddress() const
{
    return address1 + "\n" + address2 + "\n";
}

QString Customer::getAddressLine1() const
{
    return address1;
}

QString Customer::getAddressLine2() const
{
    return address2;
}

QString Customer::getInterest() const
{
    return interest;
}

QString Customer::getKey() const
{
    return keyCustomer;
}

void Customer::setAddress(QString customerAddress)
{

    int index;
    int stringIterator;

    QString inputString;

    index = 0;
    stringIterator = 0;
    while(index < customerAddress.size() && customerAddress[index] != '\n')
    {
        inputString[stringIterator] = customerAddress[index];
        index++;
        stringIterator ++;
    }

    index++;

    this->setAddressLine1(inputString);

    inputString.clear();

    stringIterator = 0;

    while(index < customerAddress.size() && customerAddress[index] != '\n')
    {
        inputString[stringIterator] = customerAddress[index];
        index++;
        stringIterator++;
    }

    this->setAddressLine2(inputString);

    inputString.clear();


}

void Customer::setAddressLine1(QString newAddress)
{
    address1 = newAddress;
}

void Customer::setAddressLine2(QString newAddress)
{
    address2 = newAddress;
}

void Customer::setInterest(QString newInterest)
{
    interest = newInterest;
}

void Customer::setKey(QString key)
{
    keyCustomer = key;
}

