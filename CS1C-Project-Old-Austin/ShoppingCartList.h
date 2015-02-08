#ifndef SHOPPINGCARTLIST_H
#define SHOPPINGCARTLIST_H

#include "genericnodeclass.h"
#include "ProductClass.h"


/**************************************************************************
 * 							[L I S T ~ C L A S S]
 **************************************************************************/

class ShoppingCartList
{
/**************************************************************************
 * P R I V A T E
 * ------------------------------------------------------------------------
 * The private section begins here
 **************************************************************************/
private:
    //M E M B E R ~ D E C L A R A T I O N S

    Node<Product>*         _head;
    Node<Product>*         _tail;
    Node<Product>*         _ptr;
    int      		  	   _nodeCount;
    int 			  	   _listLimit;

/**************************************************************************
 * P U B L I C
 * ------------------------------------------------------------------------
 * The public section begins here
 **************************************************************************/
public:

/*******************
 * M U T A T O R S *
 *******************/
    /**********************************************************************
     * C O N S T R U C T O R
     * --------------------------------------------------------------------
     * Constructs an object and initializes
     **********************************************************************/
    ShoppingCartList();

    /**********************************************************************
     * D E S T R U C T O R
     * --------------------------------------------------------------------
     * Destructs a list
     **********************************************************************/
    ~ShoppingCartList();
    /**********************************************************************
     * Enqueue
     * --------------------------------------------------------------------
     * Adds a node to the end of the list
     **********************************************************************/
    void Enqueue(Product data);

    void Swap(Node<Product>* objectOne,
              Node<Product>* objectTwo);

    /**********************************************************************
     * Dequeue
     * --------------------------------------------------------------------
     * Removes the first node from the list
     **********************************************************************/
    Product Dequeue();


    Node<Product>* GetHead() const;

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


    /**********************************************************************
     * clearList
     * --------------------------------------------------------------------
     * This method will clear the entire list
     ***********************************************************************/
    void ClearList();



/*********************
 * A C C E S S O R S *
 *********************/
    /**********************************************************************
     * Front
     * --------------------------------------------------------------------
     * Returns the
     **********************************************************************/
    Product Front() const;

    /**********************************************************************
     * Size
     * --------------------------------------------------------------------
     * This method will return the size of the list
     **********************************************************************/
    int      Size() const;

    /**********************************************************************
     * IsEmpty
     * --------------------------------------------------------------------
     * This method will check to see if the list is Empty
     **********************************************************************/
    bool     isEmpty() const;

    /**********************************************************************
     * isFull
     * --------------------------------------------------------------------
     * This method will check to see if the list is full
     **********************************************************************/
    bool     isFull() const;

    /**********************************************************************
     * OutputList
     * --------------------------------------------------------------------
     * This method will return a QString containing the list
     **********************************************************************/
    QString   OutputList() const;



   ShoppingCartList SortList();


   void RemoveProduct (Product &someProduct)
    // Removes customer from list
    //   Returns customer by reference

    Product FindCustomer(QString userName);
    // Finds customer in list
    //   Returns customer object

    Product* ReturnCustomerPtr(QString userName);
    // Returns customer pointer to calling function


    // Returns the integer location of customer

    Product operator[](int index) const;

    ShoppingCartList& operator=(const ShoppingCartList&);

    bool isExistSameName(QString name);

    bool isExist(Product someProduct);


};

//CustomerNode& CustomerList::operator[] (const int index)
//{
//
//	return _head[index];
//}
//





//CustomerNode* CustomerList::FindCustomer(Customer someCustomer) const
//{
//	CustomerNode * traversePtr;
//
//	traversePtr = _head;
//	int index = 0;
//	while (index < _listLimit && traversePtr != NULL)
//	{
//		// overloaded operator
//		if (traversePtr->GetData() == someCustomer)
//		{
//			return traversePtr;
//		}
//	}
//
//
//	if (index == _listLimit && traversePtr == NULL)
//	{
//		// throw exception class if not found.
//		traversePtr = NULL;
//		throw NotFound();
//	}
//
//
//
//}

#endif // SHOPPINGCARTLIST_H
