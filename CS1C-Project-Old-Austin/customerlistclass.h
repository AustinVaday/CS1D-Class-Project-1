#ifndef CUSTOMERLISTCLASS_H
#define CUSTOMERLISTCLASS_H

#include "customerclass.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include "genericnodeclass.h"

/******************************************************************
 * Customer list
 * --------------------------------------------------------------
 *
 *****************************************************************/


class CustomerList
{
 // P R I V A T E
private:
    //M E M B E R ~ D E C L A R A T I O N S

    Node<Customer>*         _head;
    Node<Customer>*         _tail;
    int      		  	 	_nodeCount;
    int 			  		_listLimit;

//P U B L I C
public:
// M U T A T O R S
    // C O N S T R U C T O R
    CustomerList();
    // Constructs an object and initializes

     // D E S T R U C T O R
    ~CustomerList();
    // Destructs a list

    void Enqueue(Customer data);
    // Adds a node to the end of the list, copy daya members into list node
    //      Returns: Nothing, node stays in list*

    void Swap(Node<Customer>* objectOne, Node<Customer>* objectTwo);
    // Swaps the values of both the customer pointers to data members
    //      Pointers Return: Objects have swapped identical values permanently

    Customer Dequeue();
    // Removes the first node from the list

    Node<Customer>* GetHead() const;

    /**********************************************************************
     * IncrementCount
     * --------------------------------------------------------------------
     * This method will increment the _nodeCount by one
     **********************************************************************/
    void IncrementCount();

    /**********************************************************************
     * DecrementCount
     * --------------------------------------------------------------------
     * This method will Decrement the _nodeCount by one
     **********************************************************************/
    void DecrementCount();

//	/**********************************************************************
//	 * CreateObject
//	 * --------------------------------------------------------------------
//	 * This method will create an object and fill it with data
//	 **********************************************************************/
//	Node<Customer>* CreateObject( data);

    /**********************************************************************
     * clearList
     * --------------------------------------------------------------------
     * This method will clear the entire list
     ***********************************************************************/
    void ClearList();




// A C C E S S O R S


    Customer Front() const;
    // Returns the Front customer of the list
    //      returns customer value

    int      Size() const;
    // This method will return the size of the list
    //      returns integer

    bool     isEmpty() const;
    //This method will check to see if the list is Empty

    bool     isFull() const;
    // This method will check to see if the list is full

    QString   OutputList() const;
    // This method will return a QString containing the list

    void SortList(Node<Customer>* head);

    void RemoveCustomer(Customer &someCustomer);
    // Removes customer from list
    //   Returns customer by reference

    Customer FindCustomer(QString userName);
    // Finds customer in list
    //   Returns customer object

    Customer* ReturnCustomerPtr(QString userName);
    // Returns customer pointer to calling function

    Customer VerifyCustomer(QString userName, QString password);


    int FindCustomerLocation (QString userName);
    // Returns the integer location of customer

    Customer operator[](int index) const;

    CustomerList& operator=(const CustomerList&);

    bool isExistSameName(QString name);

    bool isExist(Customer someCustomer);

    bool    WriteToFile();

	bool    ReadFile();
};

#endif // CUSTOMERLISTCLASS_H
