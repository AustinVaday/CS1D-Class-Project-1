#include "userclass.h"
#include <QTextStream>
#include <QDebug>

// Default constructor
User::User()
{
    userName 		= " ";
    userEmail		= " ";
    accountNum 		= 0;
    userPassword 	= " ";
    accountAccess 	= false;
}

// Non default constructor
User::User(QString name,
           QString email,
           long 	acctNum,
           QString password)
{


    userName            = name;
    userEmail            = email;
    accountNum 		= acctNum;
    userPassword 	= password;

}

void User:: setValues(QString newName,
                      QString newEmail,
                      long 	newAccountNum,
                      QString newPassword)
{
    userName           = newName;
    userEmail            = newEmail;
    accountNum       = newAccountNum;
    userPassword   = newPassword;

}

void User::setAccountNum(long newId)
{
    accountNum = newId;
}
// Set name
void User::setUserName(QString newUserName)
{
    userName = newUserName;
}

void User::setEmail(QString newEmail)
{
    userEmail = newEmail;
}

void User::setPassword(QString newPassword)
{
    userPassword = newPassword;
}

void User::setAccountAccess(bool access)
{
    accountAccess = access;
}

long User::getAccountNum() const
{
    return accountNum;
}

QString User::getUserName() const
{
    return userName;
}

QString User::getEmail() const
{
    return userEmail;
}

QString User::getPassword() const
{
    return userPassword;
}


bool User::getAccess() const
{
    return accountAccess;
}
// Overloading the equality operator **FOR SIMILARITY**
bool User::operator &=(const User& otherUser)
{
    bool same;

    same = false;

    // Compares names and account numbers, if either are the same it will
    //	throw a flag. We could compare objects completely but we don't want
    //	to throw a flag on a person who has the exact same password by
    //	some crazy chance.
    //

    if(	  otherUser.getAccountNum() == this->getAccountNum()
       || otherUser.getUserName() 	== this->getUserName())
    {
        same = true;
    }

    return same;
}

// Overloading the equality operator **FOR ABSOLUTE EQUALITY**
bool User::operator ==(const User& otherUser)
{
    bool same;

    qDebug() << "INSIDE userclass.cpp .. operator= .. line 117";
    same = false;

    // Compares names and account numbers, if either are the same it will
    //	throw a flag. We could compare objects completely but we don't want
    //	to throw a flag on a person who has the exact same password by
    //	some crazy chance.
    //

    if(	  otherUser.getAccountNum() == this->getAccountNum()
       && otherUser.getUserName() 	== this->getUserName()
       && otherUser.getAccountNum() == this->getAccountNum()
       && otherUser.getPassword()   == this->getPassword()
       && otherUser.getAccess()     == this->getAccess())
    {
        same = true;
    }

    return same;
}

QString  User::OutputData() const
{
    QString str;

    QTextStream out(&str);
    out << "........................................................\n";
    out << "Data for: " <<  userName << endl;
    out << "Email address: " << userEmail << endl;
    out << "Account number: " <<  accountNum << endl;
    out << "Password: " << userPassword << endl;
    out << "Temp... Account Access: " << accountAccess << endl;
    out << "........................................................\n";

    return str;
}
