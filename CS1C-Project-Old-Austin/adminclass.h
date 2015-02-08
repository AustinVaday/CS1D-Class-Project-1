#ifndef ADMINCLASS_H
#define ADMINCLASS_H
#include "userclass.h"
#include "customerclass.h"
#include "customerlistclass.h"

#include <QString>

//void AdminMain( CustomerList activatedList,
//				CustomerList listOfPrevPurchasers,
//				CustomerList deactivatedList,
//				List<string> customerReviews,
//				AdminMenu overrideSelection,
//				bool overrideInput);


class Admin : public User
{
    public:
        Admin();
        //default

        Admin(QString userName,
              QString email,
              long accountNum,
              QString password
             );
        // non-default

        ~Admin();
        //  Deconstructor

        // Accessors
        QString GetUserName();
        QString GetEmail();
        long GetAccountNum();
        QString GetPassword();
        bool activationStatus();

        //Mutators

        void addCustomer(CustomerList &list, Customer customerToAdd);
        //add a customer to the list of customers.

        void moveCustomer(CustomerList &list1,
                             CustomerList &list2,
                             Customer &customerToMove);

        void deleteCustomer(CustomerList &list, Customer &customerToDelete);

        void wipeList (CustomerList &list);
        // wipes out the whole list of deactivated customers.

        void modifyCustomerReviews();
         // allow the admin to access, delete, or modify any
         // customer reviews.

        Customer findCustomer(CustomerList &list, QString userName);

        QString displayCustomer(CustomerList &list, QString userName);

        //NEW
        bool checkAdmin(QString name, QString password);


    private:

};


#endif // ADMINCLASS_H
