#ifndef GENERICNODE_H
#define GENERICNODE_H

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
    Node*    _next;
    Node*    _previous;
    typeName _data;

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
    void SetPointer(typeName _newPointer);

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

    Node<typeName>* GetPrevious() const;

    Node<typeName>* GetNext() const;

};
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
}

/**************************************************************************
 * D E S T R U C T O R
 * ------------------------------------------------------------------------
 * This is the Default constructor for the Node template
 **************************************************************************/
template <class typeName>
Node<typeName>::~Node()
{
    delete _next;
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
void Node<typeName>::SetPointer(typeName newPointer)
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



#endif // GENERICNODE_H
