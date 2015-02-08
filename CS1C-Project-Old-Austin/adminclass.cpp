#include "adminclass.h"

//default
Admin::Admin()
{

    // initialize nothing because we have static vars
}

// non-default
Admin::Admin(QString userName,
              QString email,
              long accountNum,
              QString password
            ) : User(userName,email,accountNum,password)
{


}

// destructor
Admin::~Admin()
{

}


bool Admin::checkAdmin(QString name, QString password)
{
   return ((GetUserName() == name) && (GetPassword() == password));
}

QString Admin::GetUserName()
{
    return getUserName();
}
QString Admin::GetEmail()
{
    return getEmail();
}
long Admin::GetAccountNum()
{
    return getAccountNum();
}
QString Admin::GetPassword()
{
    return getPassword();
}
bool Admin::activationStatus()
{
    return getAccess();
}

//add a customer to the list of customers.
// pass by value so a copy will be added to the list.
void Admin::addCustomer(CustomerList &list, Customer customerToAdd)
{
    list.Enqueue(customerToAdd);
}


// move the customer from list 2 to list 1
void Admin::moveCustomer(CustomerList &list1,
                         CustomerList &list2,
                         Customer &customerToMove)
{
            // Removes a customer from list 2
            list2.RemoveCustomer(customerToMove);

            // Puts customer into list 1
            list1.Enqueue(customerToMove);
}

void Admin::deleteCustomer(CustomerList &list,
                            Customer &customerToDelete)
{
        // try and catch blocks or nahh??

        list.RemoveCustomer(customerToDelete);
}

// wipes out the whole list of deactivated customers.
void Admin::wipeList (CustomerList &list)
{
    list.ClearList();
}

// allow the admin to access, delete, or modify any
// customer reviews.
 void Admin::modifyCustomerReviews()
 {
        /*********************************************
         * THIS NEEDS TO BE COMPLETED !!
         * THIS IS A REQUIREMENT!!!!!
         **********************************************/
 }


 Customer Admin::findCustomer(CustomerList &list, QString userName)
 {
     return list.FindCustomer(userName);
 }


 QString Admin::displayCustomer(CustomerList &list, QString userName)
 {
     Customer temp;

     temp = findCustomer(list, userName);

     return temp.OutputData();
 }
