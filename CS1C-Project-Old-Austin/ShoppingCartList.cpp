#include <QTextStream>
#include <QMessageBox>
#include "ExceptionHandlers.h"
#include "activatedlist2.h"
#include <QDebug>
#include "ShoppingCartList.h"
#include "ProductClass.h"

/**************************************************************************
 * CS1C Class Project
 * -----------------------------------------------------------------------
 * CustomerListSource
 * -----------------------------------------------------------------------
 * Version: 0.0.1
 * -----------------------------------------------------------------------
 * Programmers:
 *		Austin 	Vaday
 *		Anthony Ramirez
 *		Annie	Raichev
 *		Erik 	Karlsson
 *
 *************************************************************************/


/**************************************************************************
 * List Constructor
 * ------------------------------------------------------------------------
 * This method will construct an object and initialize all object to 0;
 *************************************************************************/
ShoppingCartList::ShoppingCartList()
{
    _head      = NULL;
    _tail      = NULL;
    _nodeCount = 0;
    _listLimit = 100;
}


/**************************************************************************
 * D E S T R U C T O R
 * ------------------------------------------------------------------------
 * Destructs a list
 **************************************************************************/
ShoppingCartList::~ShoppingCartList()
{
        this->ClearList();
}

/**************************************************************************
 * isFull
 * ------------------------------------------------------------------------
 * This method will check if the list is full and determine the amount of
 * nodes left in the list
 *************************************************************************/
bool ShoppingCartList::isFull() const
{
    return _nodeCount == _listLimit;
}

Node<Product>* ShoppingCartList::GetHead() const
{
    return _head;
}

/**************************************************************************
 * IncrementCount
 * ------------------------------------------------------------------------
 * This method will increment the _nodeCount by one
 **************************************************************************/
void ShoppingCartList::IncrementCount()
{
    _nodeCount += 1;
}

/**************************************************************************
 * DecrementCount
 * ------------------------------------------------------------------------
 * This method will decrement the _nodeCount by one
 **************************************************************************/
void ShoppingCartList::DecrementCount()
{
    _nodeCount -= 1;
}

/**************************************************************************
 * OutputList
 * ------------------------------------------------------------------------
 * This method will return a string with the entire list
 **************************************************************************/
QString ShoppingCartList::OutputList () const
{
    //D E C L A R A T I O N
    Node<Product> * traverse;      //CALC - used to traverse the list
    QString  stringList;		   //OUT - used to store the content of the
                                    //	   list
    QTextStream out(&stringList);  //OUT - used to create a stream in which
                                     //	   the content of the list will be sent
                                    //	   too

    //I N I T I A L I Z A T I O N S

    traverse = _head;	//Sets the traverse pointer to _head so _head
                        //is not lost while traversing

    /**********************************************************************
     * While Loop Iterates until traverse (which is initialized to _head)
     * reaches NULL. Since this is a queue, the first node is output first
     **********************************************************************/

    if(!isEmpty())
    {//Begin While

//        out << endl << "***Current Linked List***" << endl;
//        out << "******************************************************************\n";

        int index = 0;
        while(traverse != NULL)
        {

            out << "List item #" << index + 1 << endl;


//            ui->listWidget->addItem(traverse->GetData().OutputData());
            out << traverse->GetData().OutputData();
            //Sets the traverse pointer to the next node
            traverse = traverse->GetNext();
            index++;
        }//End While

//        out << "******************************************************************\n";

    }
    else
    {
        out << endl << "List is empty" << endl;

    }


    traverse = NULL;
    return stringList;

}


/**************************************************************************
 * ClearList
 * ------------------------------------------------------------------------
 * This method Clears the entire list and points _head and _tail to NULL
 **************************************************************************/
void ShoppingCartList::ClearList()
{
    while(!isEmpty())
    {

        qDebug() << "******Debugging: Deleting customer in list.******\n";

        Dequeue();
    }
}

/**************************************************************************
 * Front
 * ------------------------------------------------------------------------
 * This method will return the first node in the list
 **************************************************************************/

 Product ShoppingCartList::Front() const
{
    //What if the list is empty?
    return _head->GetData();
}


 //Not sure if I need this anymore

  /****************************************************************
  * Enqueue
  * ------------------------------------------------------------------------
  * This method will allow the user to add a node to the queue. The list
  * will be limited to the size set in the constructor. If the user reaches
  * the limit, the Enqueue method will output an error message.
  **************************************************************************/
 void ShoppingCartList::Enqueue(Product data)
 {
    //D E C L A R A T I O N S
 //	Node<typeName> * temp;
        //D E C L A R A T I O N S
     Node<Product>*  _createNew;   //CALC - used to create dynamic memory

     //D E C L A R A T I O N S
     bool continueTraverse;
     Node<Product>* _cursor;


    //Begin If only if the list is empty
    if(isEmpty())
    {
        //Creates new dynamic memory
        _createNew  = new Node<Product>;

        //Sets the data of the newly created node
        _createNew->SetData(data);


        //Creates a new Object and stores data within it
      //Assigns _head and _tail to the new object created in dynamic memory
        _head = _createNew;
        _tail = _createNew;

        //		cout << "\nAdding " << _createNew->GetData() << " to the list.\n";
        //increments the _listCount
        IncrementCount();
    }
    else if(_nodeCount < _listLimit)
    {
        //I N I T I A L I Z A T I O N S
            _cursor          = _head;
            continueTraverse = true;
            //Creates new dynamic memory
            _createNew  = new Node<Product>;

             //Sets the data of the newly created node
             _createNew->SetData(data);
            //This "if-statement" is designed to add a node when there is only ONE node currently in the list
            // *
             if(_cursor->GetNext() == NULL)
             {
                if(_createNew->GetData().getName() < _cursor->GetData().getName())
                {
                    _createNew->SetNext(_cursor);
                    _head = _createNew;

                }
                else
                {
                    _createNew->SetPrevious(_cursor);
                    _cursor->SetNext(_createNew);
                    _tail = _createNew;
                }
             }
             else
             {    _cursor = _cursor->GetNext();
                //This loop is designed to traverse the current list and stop at a place to ensure
                //the node is added to the list according to alphabetical order
                while(_cursor != NULL && continueTraverse)
                {
                    if((_createNew->GetData().getName() < _cursor->GetData().getName()))
                    {
                        continueTraverse = false;
                        _createNew->SetNext(_cursor);
                        _createNew->SetPrevious(_cursor->GetPrevious());
                        _cursor-> SetPrevious(_createNew);
                        _createNew->GetPrevious()->SetNext(_createNew);
                   }
                    else
                    {
                        _cursor = _cursor->GetNext();
                    }
                }

                if(continueTraverse)
                {
                    _createNew->SetPrevious(_tail);
                    _tail->SetNext(_createNew);
                   _tail = _createNew;
                }

             }

        IncrementCount();


    }
    else
    {
        //Outputs error message
        QMessageBox messageBox;
        messageBox.critical(0,"Error","**List has reached its max size**");
        messageBox.setFixedSize(500,200);
    }

  }


/**************************************************************************
 * Dequeue
 * ------------------------------------------------------------------------
 * Removes the first node from the list
 **************************************************************************/
Product ShoppingCartList::Dequeue()
{
    Node<Product>* temp;
    Product tempProduct;

    if(isEmpty())
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","**Cannot dequeue empty list**");
        messageBox.setFixedSize(500,200);
    }
    else
    {
        //Assigns temp to head
        temp  = _head;

        _head = _head->GetNext();

        //Decrements the _nodeCount
        DecrementCount();


        //Calls Orphan to set all pointers to NULL

        temp->Orphan();

        tempProduct = temp->GetData();


        delete temp;

        temp = NULL;

        return tempProduct;

    }
}

/**************************************************************************
 * IsEmpty
 * ------------------------------------------------------------------------
 * This method will check to see if the list is Empty
 **************************************************************************/
bool ShoppingCartList::isEmpty() const
{

    return _head == NULL;

}

/**************************************************************************
 * Size
 * ------------------------------------------------------------------------
 * This method returns the size of the list
 **************************************************************************/
int ShoppingCartList::Size() const
{
    return _nodeCount;
}

void ShoppingCartList::RemoveProduct (Product &someProduct)
{
    Node<Product> * traversePtr;
    Node<Product> * actionPtr;

    if(isEmpty())
    {
//		cout << "Can't Dequeue an empty list" << endl;
        throw EmptyList();
    }

    traversePtr = _head;
    int index = 0;

    while (index < _listLimit && traversePtr != NULL && !(traversePtr->GetData() == someProduct))
    {

        traversePtr = traversePtr->GetNext();
        index++;
    }

    // overloaded operator
    if (traversePtr->GetData() == someProduct)
    {
        // head deletion
        if (traversePtr == _head)
        {
            Dequeue();

        }
        // end deletion
        else if (traversePtr == _tail)
        {
            _tail = _tail->GetPrevious();


            _tail->SetNext(NULL);
//				_tail->_next = NULL;

            traversePtr->Orphan();

            delete traversePtr;

            //Decrements the _nodeCount
            DecrementCount();

        }
        // middle deletion
        else
        {
//				actionPtr = traversePtr->_previous;
            actionPtr = traversePtr->GetPrevious();

//				actionPtr->_next = traversePtr->_next;
            actionPtr->SetNext(traversePtr->GetNext());

//				traversePtr->_next->_previous = actionPtr;

            traversePtr->SetNext(traversePtr->GetNext());
            traversePtr->SetPrevious(actionPtr);

            traversePtr->Orphan();

            delete traversePtr;

            //Decrements the _nodeCount
            DecrementCount();

        }

    }

    if (index == _listLimit && traversePtr == NULL)
    {
        // throw exception class if not found.
        traversePtr = NULL;
        throw NotFound();
    }
}

//Customer CustomerList::FindCustomer(QString userName)
//{
//    Node<Customer> * traversePtr;

//        if(isEmpty())
//        {
//            throw EmptyList();
//        }

//        // NEED TO MAKE SURE 2 ACCOUNT NUMBERS CANNOT BE THE SAME //
//        traversePtr = _head;
//        int index = 0;
//        while (index < _listLimit && traversePtr !=NULL &&
//                traversePtr->GetData().getUserName() != userName)
//        {
//            traversePtr = traversePtr->GetNext();

//            index++;
//        }
//        if (traversePtr == NULL)
//        {
//            // throw exception class if not found.
//            traversePtr = NULL;
//            throw NotFound();
//        }

//        return traversePtr->GetData();

//}

ShoppingCartList ShoppingCartList::SortList()
{
    ShoppingCartList tempList;

    tempList = *this;

    ShoppingCartList sortedList;


    while(tempList.GetHead() != NULL)
    {
        sortedList.Enqueue(tempList.Dequeue());
    }

    return sortedList;
}

   Product* ShoppingCartList::ReturnCustomerPtr(QString name)
  {
      Node<Product> * traversePtr;

          if(isEmpty())
          {
              throw EmptyList();
          }

          // NEED TO MAKE SURE 2 ACCOUNT NUMBERS CANNOT BE THE SAME //
          traversePtr = _head;
          int index = 0;
          while (index < _listLimit && traversePtr !=NULL &&
                  traversePtr->GetData().getName() != name)
          {
              traversePtr = traversePtr->GetNext();

              index++;
          }
          if (traversePtr == NULL)
          {
              // throw exception class if not found.
              traversePtr = NULL;
              throw NotFound();
          }

       Product *dataPtr = traversePtr->GetDataPtr();


          return dataPtr;
  }

//int ShoppingCartList::FindProductLocation (QString userName)
//{
//        Node<Product> * traversePtr;

//        if(isEmpty())
//        {
//            throw EmptyList();
//        }

//        // NEED TO MAKE SURE 2 ACCOUNT NUMBERS CANNOT BE THE SAME //
//        traversePtr = _head;
//        int index = 0;
//        while (index < Size() && traversePtr !=NULL &&
//                traversePtr->GetData().getUserName() != userName)
//        {
//            traversePtr = traversePtr->GetNext();

//            index++;
//        }
//        if (traversePtr == NULL)
//        {
//            qDebug() << "12";
//            // throw exception class if not found.
//            throw NotFound();
//        }

//        return index;
//}

Product ShoppingCartList::operator[](int index) const
{
    Node<Product> * traversePtr;

        if(isEmpty())
        {
            throw EmptyList();
        }

        if (index > _listLimit)
        {
            throw OutOfRange();
        }


        // NEED TO MAKE SURE 2 ACCOUNT NUMBERS CANNOT BE THE SAME //
        traversePtr = _head;
        int i = 0;
        while (i < _listLimit && traversePtr !=NULL &&
                i != index)
        {
            traversePtr = traversePtr->GetNext();

            i++;
        }

        if (traversePtr == NULL)
        {
            // throw exception class if not found.
            traversePtr = NULL;
            throw NotFound();
        }

        return traversePtr->GetData();
}




//Un-needed

//bool ShoppingCartList::isExistSameName(QString name)
//{
//    try
//    {
//        for (int i = 0; i < this->Size(); i++)
//        {
//            if (this->operator[](i).getName() == name)
//            {
//                return true;
//            }
//        }
//    }
//    catch(NotFound)
//    {
//        qDebug() << "customerListClass.cpp -- line 589";
//    }

//    return false;
//}

bool ShoppingCartList::isExist(Product someProduct)
{
        Node<Product> * traversePtr;

        if(isEmpty())
        {
            return false;
        }

        // NEED TO MAKE SURE 2 ACCOUNT NUMBERS CANNOT BE THE SAME //
        traversePtr = _head;
        int i = 0;

        while (i < Size() && traversePtr !=NULL)
        {

            if (someProduct == traversePtr->GetData())
            {
                return true;
            }

            traversePtr = traversePtr->GetNext();

            i++;
        }

        if (traversePtr == NULL)
        {
            // throw exception class if not found.
            return false;
        }

        return true;
}


//Unneeded

//void CustomerList::Swap(Node<Customer>* objectOne, Node<Customer>* objectTwo)
//{
//    QString tempName;
//    QString tempEmail;
//    QString tempPassword;
//    long    tempAccountNumber;
//    \


//    tempName          = objectOne->GetData().getUserName();
//    tempEmail         = objectOne->GetData().getEmail();
//    tempAccountNumber = objectOne->GetData().getAccountNum();
//    tempPassword      = objectOne->GetData().getPassword();

//    objectOne->GetData().setUserName(objectTwo->GetData().getUserName());
//    objectOne->GetData().setEmail(objectTwo->GetData().getEmail());
//    objectOne->GetData().setPassword(objectTwo->GetData().getPassword());
//    objectOne->GetData().setAccountNum(objectTwo->GetData().getAccountNum());
//    objectTwo->GetData().setUserName(tempName);
//    objectTwo->GetData().setEmail(tempEmail);
//    objectTwo->GetData().setPassword(tempPassword);
//    objectTwo->GetData().setAccountNum(tempAccountNumber);


//}


//Product ShoppingCartList::VerifyProduct(QString userName, QString password)
//{
//   Node<Customer>* cursor;
//   Customer        tempCustomer;
//   QString         name;
//   QString         pw;

//   tempCustomer.setValues(" "," ",0," ");

//   bool found;

//   cursor = _head;
//   found  = false;



//   while(cursor != NULL && !found)
//   {

//        name = cursor->GetData().getUserName();
//        pw   = cursor->GetData().getPassword();

//       if((name == userName) && (pw == password))
//       {
//           tempCustomer = cursor->GetData();
//           found = true;

//       }
//       else
//       {
//           cursor = cursor->GetNext();
//       }
//   }
//    cursor = NULL;

//   return tempCustomer;
//}

ShoppingCartList& ShoppingCartList::operator=(const ShoppingCartList& list)
{
        int index;
        Product copyProduct;
        index = 0;

//Before Assignment

qDebug() << "Line 590: Before CustomerLIst Assignment: " << this->OutputList();

this->ClearList();

// Only a temporary fix :( It's only adding to the queue not removing from it.
        if(!list.isEmpty())
        {
                for(index = 0; index < list.Size(); index++)
                {
                        copyProduct =list[index];
                        this->Enqueue(copyProduct);
                }

        }
// AFter
qDebug() << "Line 616: After CustomerLIst Assignment: " << this->OutputList();

        return *this;
}

