#include "TheUser.h"

User::User(QString newName) :name(newName)
{
}

User::~User()
{
}

void User::SetName(QString newName)
{
    name = newName;
}

QString User::GetName()
{
    return name;
}

void User::Print()
{
    //list.Print();
}
