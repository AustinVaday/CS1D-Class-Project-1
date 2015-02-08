#include "AddressClass.h"

AddressClass::AddressClass()
{
    address = " ";
    city    = " ";
    zipCode = 0;
    state   = " ";
}

AddressClass::~AddressClass()
{

}

QString AddressClass::getStreet() const
{
    return street;
}
