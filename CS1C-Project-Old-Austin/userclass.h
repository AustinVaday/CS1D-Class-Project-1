#ifndef USERCLASS_H
#define USERCLASS_H
#include <QString>
class User
{

    public:
        User();
        // default

        User(QString userName,
                QString email,
                long accountNum,
                QString password);

        void setValues(QString userName,
                 QString email,
                 long 	accountNum,
                 QString password);

        // Mutators
        bool operator&=(const User& otherUser);
        // Overloading the equality operator **FOR SIMILARITY**


        bool operator==(const User& otherUser);
        // Overloading the equality operator **FOR ABSOLUTE EQUALITY**


        void setUserName(QString newUsterName);
        void setEmail(QString newEmail);
        void setAccountNum(long newId);
        void setPassword(QString newPassword);
        void setAccountAccess(bool access);

        //Accessors
        QString     getUserName() 	const;
        QString     getEmail() 	 	const;
        long           getAccountNum()	const;
        QString 	getPassword()   const;
        bool        getAccess()     const;

        QString     OutputData()    const;

    private:
        QString 	userName;
        QString 	userEmail;
        long        accountNum;
        QString     userPassword;
        bool        accountAccess;


};


#endif // USERCLASS_H
