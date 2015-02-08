#ifndef GENERICNODECLASS_H
#define GENERICNODECLASS_H
#include <QDebug>
#include <QString>
#include "ExceptionHandlers.h"

/**************************************************************************
 * CS1C Class Project
 * -----------------------------------------------------------------------
 * Product Class Test
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
 * 							[N O D E ~ C L A S S]
 **************************************************************************/
template <class typeName>
class Node
{/**************************************************************************
 * P R I V A T E
 * ------------------------------------------------------------------------
 * The private section begins here
 **************************************************************************/
private:
    Node*     _next;
    Node*     _previous;
    typeName  _data;

    typeName* _dataPtr;

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
     * This is the Default constructor for the Node template
     **********************************************************************/
    Node();

    /**********************************************************************
     * D E S T R U C T O R
     * --------------------------------------------------------------------
     * This is the Default constructor for the Node template
     **********************************************************************/
    ~Node();

    /**********************************************************************
     * SetData
     * --------------------------------------------------------------------
     * This template method is used to set the data within the node
     **********************************************************************/
    void SetData(typeName _newData);

    /**********************************************************************
     * SetPointer
     * --------------------------------------------------------------------
     * This template method is used to set pointer in node
     **********************************************************************/
    void SetPointer(typeName* _newPointer);

    void SetNext(Node* newNext);

    void SetPrevious(Node* newPrev);

    void Orphan();

/*********************
 * A C C E S S O R S *
 *********************/
    /**********************************************************************
     * GetData
     * --------------------------------------------------------------------
     * This method will return the data in the node
     **********************************************************************/
    typeName GetData() const;

    typeName* GetDataPtr() const;

    Node<typeName>* GetPrevious() const;

    Node<typeName>* GetNext() const;

    Node<typeName>* operator[](int index) const;

   int GetListSize();


};




template<class typeName>
int Node<typeName>::GetListSize()
{
    //D E C L A R A T I O N S
    int size;
    Node<typeName>* traverse;

    traverse = this;
    //I N I T I A L I Z A T I O N S
    size = 0;



   while( traverse != NULL)
   {
       traverse = traverse->_next;
       size++;
   }

   return size;

}


//template <class typeName>
//Node<typeName>* Node<typeName>::operator[](int index) const
//{
//    Node<typeName>* traversePtr;

//    //        if(this->_next == NULL)
//    //        {
//    //            throw EmptyList();
//    //        }
////        else if(this->GetListSize() < index)
////        {
////            throw OutOfRange();
////        }

//        traversePtr = this;

//        // NEED TO MAKE SURE 2 ACCOUNT NUMBERS CANNOT BE THE SAME //

//        int i = 0;
//        while (traversePtr !=NULL &&
//                i <= index)
//        {
//            traversePtr = traversePtr->GetNext();

//            i++;
//        }

//        if (traversePtr == NULL)
//        {
//            // throw exception class if not found.
//            traversePtr = NULL;
//            throw NotFound();
//        }

//        return traversePtr;
//}




/**************************************************************************
 * Node Constructor
 * ------------------------------------------------------------------------
 * Initializes _next
 **************************************************************************/
template <class typeName>
Node<typeName>::Node()
{
    _next     = NULL;
    _previous = NULL;
    _data     = typeName();
    _dataPtr = &_data;
}

/**************************************************************************
 * D E S T R U C T O R
 * ------------------------------------------------------------------------
 * This is the Default constructor for the Node template
 **************************************************************************/
template <class typeName>
Node<typeName>::~Node()
{
qDebug() << "******Debugging: Deconstructor - _next node.******\n";



}

/**************************************************************************
 * Orphan
 * ------------------------------------------------------------------------
 * Sets All pointers to NULL so when it is deleted it is not associated with
 * any other nodes.
 **************************************************************************/
template <class typeName>
void Node<typeName>::Orphan()
{
        _next 	  = NULL;
    _previous = NULL;
}

/**************************************************************************
 * GetNext
 * ------------------------------------------------------------------------
 * Returns the next pointer
 **************************************************************************/
template <class typeName>
Node<typeName>* Node<typeName>::GetNext() const
{
    return _next;
}


template <class typeName>
Node<typeName>* Node<typeName>::GetPrevious() const
{
    return _previous;
}
/**************************************************************************
 * SetNext
 * ------------------------------------------------------------------------
 * Sets the _next pointer
 **************************************************************************/
template <class typeName>
void Node<typeName>::SetNext(Node* next)
{
    _next = next;
}

template <class typeName>
void Node<typeName>::SetPrevious(Node* newPrev)
{
    _previous = newPrev;
}

/**************************************************************************
 * SetData
 * ------------------------------------------------------------------------
 * Sets the data for the Node object
 **************************************************************************/
template <class typeName>
void Node<typeName>::SetData(typeName newData)
{
    _data = newData;
}

/**************************************************************************
 * SetPointer
 * ------------------------------------------------------------------------
 * Sets the _next pointer to a pointer argument
 **************************************************************************/
template <class typeName>
void Node<typeName>::SetPointer(typeName* newPointer)
{
    _next = newPointer;
}

/**************************************************************************
 * GetData
 * ------------------------------------------------------------------------
 * Returns the data of the node
 **************************************************************************/
template <class typeName>
typeName Node<typeName>::GetData() const
{
        return _data;
}

template <class typeName>
 typeName* Node<typeName>::GetDataPtr() const
{

    return _dataPtr;
}


#endif // GENERICNODECLASS_H
