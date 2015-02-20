#ifndef SORTEDLIST_H
#define SORTEDLIST_H


#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QResource>

/*************************************************************
 * 		HOW TO USE
 *
 * 	A_Type = the object
 * 	B_Type = the value you want the object to be sorted by
 *  C_Type = The data type object will be searched by
 *
 * ******example******
 *
 * 	SortedList<Object_Type, string, int> theList;
 *
 * 	theList.Add( Object_Name, "Kyle Serio", 20);
 ************************************************************/

struct contactUsInfo
{
    QString name;
    QString message;
};

struct testiInfo
{
    QString name;
    QString message;
};

//STRUCT - what the list is made out of
template <class A_Type,class B_Type, class C_Type>
struct node
{
    A_Type item;
    B_Type sortValue;
    C_Type searchValue;
    node* next;
    node* prev;
};

template <class A_Type,class B_Type>
class SortedList
{
public:
    SortedList();
    ~SortedList();
    void   Add(A_Type newVariable,B_Type ValueOfNew);
    node<A_Type, B_Type>* GetHead();
    A_Type SearchFor(B_Type serch);
    bool   Remove(B_Type search);
    A_Type operator[](int index);
    void   SaveCustList(SortedList<A_Type, B_Type> theList);
    void   SavePendingCustList(SortedList<A_Type, B_Type> theList);
    void   SaveTestimonials();
    void   DeleteAll();
    void   SaveContactMessages();
    int    Size() const;
    void   Print();
    bool   SearchForBool(B_Type );
    node<A_Type,B_Type>* SearchForPtrWrap(B_Type search);

private:

    node<A_Type,B_Type>* SearchForPtr(B_Type search);
    void SortAsReadIn(node<A_Type,B_Type>* newNode);

    node<A_Type,B_Type>* head;
    node<A_Type,B_Type>* tail;
    int size;
};

template <class A_Type,class B_Type>
int SortedList<A_Type,B_Type>::Size() const
{
    node<A_Type,B_Type>* temp = head;
    int count = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

template <class A_Type,class B_Type>
node<A_Type, B_Type>* SortedList<A_Type, B_Type>::GetHead()
{
    return head;
}

template <class A_Type,class B_Type>
void SortedList<A_Type, B_Type>::Print()
{
    node<A_Type, B_Type>* temp = head;
    while(temp != NULL)
    {
        //QTextStream(stdout) << 1 << endl;
        temp = temp->next;
    }
}
template <class A_Type,class B_Type>
A_Type SortedList<A_Type,B_Type>::operator[](int index)
{
    if(index < size && index > -1)
    {
        node<A_Type,B_Type>* temp = head;

        for(int i = 0; i != index; i++)
        {
            temp = temp->next;
        }

        return temp->item;
    }
}

template <class A_Type,class B_Type>
node<A_Type,B_Type>* SortedList<A_Type,B_Type>::SearchForPtr(B_Type search)
{
    node<A_Type,B_Type>* temp;
    bool found = false;

    temp = head;

    while(!found && temp!=NULL)
    {
        if(temp->sortValue == search)
        {
            found = true;
        }
        else
        {
            temp = temp->next;
        }
    }

    return temp;
}
template <class A_Type,class B_Type>
bool SortedList<A_Type,B_Type>::Remove(B_Type search)
{
    node<A_Type,B_Type>* temp = SearchForPtr(search);
    bool found = true;

    // Checks if the item was found
    if(temp != NULL)
    {
        // Checks if its the first item in the list
        if(temp->prev == NULL)
        {
            // Checks if there is only one item in the list
            if(temp->next != NULL)
            {
                head = temp->next;
                temp->next->prev = NULL;
            }
            else
            {
                head = NULL;
                tail = NULL;
            }

        }
        // Checks if its the last item in the list
        else if(temp->next == NULL)
        {
            tail = temp -> prev;
            temp -> prev -> next = NULL;
        }
        // For items in the middle of the list
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        size--;
        delete temp;
    }
    else
    {
        found = false;
    }

    return found;
}

template <class A_Type,class B_Type>
node<A_Type,B_Type>* SortedList<A_Type, B_Type>::SearchForPtrWrap(B_Type search)
{
    return SearchForPtr(search);
}

template <class A_Type,class B_Type>
A_Type SortedList<A_Type,B_Type>::SearchFor(B_Type search)
{
    node<A_Type,B_Type>* temp;
    bool found = false;

    temp = head;

    while(!found && temp!=NULL)
    {
        if(temp->sortValue == search)
        {
            found = true;
        }
        else
        {
            temp = temp->next;
        }
    }

    return temp->item;
}

template <class A_Type,class B_Type>
bool SortedList<A_Type,B_Type>::SearchForBool(B_Type search)
{
    node<A_Type,B_Type>* temp;
    bool found = false;

    temp = head;

    while(!found && temp!=NULL)
    {
        if(temp->sortValue == search)
        {
            found = true;
        }
        else
        {
            temp = temp->next;
        }
    }

    return found;
}

template <class A_Type,class B_Type>
SortedList<A_Type,B_Type>::SortedList()
{
    size = 0;
    head = NULL;
    tail = NULL;
}

template <class A_Type,class B_Type>
SortedList<A_Type,B_Type>::~SortedList()
{
}

template <class A_Type,class B_Type>
void SortedList<A_Type,B_Type>::Add(A_Type newVariable,B_Type ValueOfNew)
{
    node<A_Type,B_Type>* temp = new node<A_Type,B_Type>;
    temp->item = newVariable;
    temp->sortValue = ValueOfNew;

    if(head == NULL)
    {
        head = temp;
        tail = temp;
        temp->next = NULL;
        temp->prev = NULL;
        size ++;
    }
    else
    {
        SortAsReadIn(temp);
        size++;
    }
}

template <class A_Type,class B_Type>
void SortedList<A_Type,B_Type>::SortAsReadIn(node<A_Type,B_Type>* newNode)
{
    node<A_Type,B_Type>* temp = head;

    if(newNode->sortValue <= head->sortValue)
    {
        newNode->next = temp;
        head->prev = newNode;
        head = newNode;
        newNode->prev = NULL;
    }
    else if(head->next == NULL && head->prev == NULL)
    {
        if(newNode->sortValue <= head->sortValue)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            newNode->prev = NULL;
        }
        else
        {
            head->next = newNode;
            newNode->prev = head;
            newNode->next = NULL;
            tail = newNode;
        }
    }
    else
    {
        while(temp != NULL && newNode->sortValue > temp->sortValue)
        {
            temp = temp->next;
        }

        if(temp != NULL)
        {
            newNode->next = temp;
            newNode->prev = temp->prev;
            newNode->prev->next = newNode;
            temp->prev = newNode;
        }
        else
        {
            newNode->next = NULL;
            newNode->prev = tail;
            newNode->prev->next = newNode;
            tail = newNode;
        }
    }
}

template<class A_Type, class B_Type>
void SortedList<A_Type, B_Type>::SaveCustList(SortedList<A_Type, B_Type> theList)
{
    QFile       common("CustomerList.txt");
    QTextStream listFileOut(&common);
    QString     listFileString;

    if(!common.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QMessageBox::information(0,"Critical Failure","Customer list file has failed to load");
    }
    else
    {
        node<A_Type,B_Type>* temp = theList.GetHead();

        while(temp != NULL)
        {
            listFileString = temp->item.GetCompName();
            listFileOut << listFileString << endl;
            listFileString = temp->item.GetAddress();
            listFileOut << listFileString << endl;
            listFileString = temp->item.GetInterest();
            listFileOut << listFileString << endl;
            listFileString = temp->item.GetKey();
            listFileOut << listFileString << endl;
            listFileString = temp->item.GetBrochureStat();
            listFileOut << listFileString << endl;
            listFileString = temp->item.GetTestimonial();
            listFileOut << listFileString << endl << endl;
            temp = temp->next;
        }
    }
}

template<class A_Type, class B_Type>
void SortedList<A_Type, B_Type>::SavePendingCustList(SortedList<A_Type, B_Type> theList)
{
    QFile       common("PendingAcc.txt");
    QTextStream listFileOut(&common);
    QString     listFileString;

    if(!common.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QMessageBox::information(0,"Critical Failure","Customer list file has failed to load");
    }
    else
    {
        node<A_Type,B_Type>* temp = theList.GetHead();

        while(temp != NULL)
        {
            listFileString = temp->item.GetCompName();
            listFileOut << listFileString << endl;
            listFileString = temp->item.GetAddress();
            listFileOut << listFileString << endl;
            listFileString = temp->item.GetInterest();
            listFileOut << listFileString << endl << endl;
            temp = temp->next;
        }
    }
}

template<class A_Type, class B_Type>
void SortedList<A_Type, B_Type>::SaveTestimonials()
{
    QFile       testiFile("testi.txt");
    QTextStream listFileOut(&testiFile);

    if(!testiFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QMessageBox::information(0,"Critical Failure","Testimonial file has failed to load");
    }
    else
    {
        node<A_Type,B_Type>* temp = GetHead();

        while(temp != NULL)
        {
            listFileOut << temp->item.name    << endl;
            listFileOut << temp->item.message << endl;
            temp = temp->next;
        }
    }
}

template<class A_Type, class B_Type>
void SortedList<A_Type, B_Type>::SaveContactMessages()
{
    QFile       listFile("ContactUs.txt");
    QTextStream listFileOut(&listFile);

    if(!listFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QMessageBox::information(0,"Critical Failure","Contact message file has failed to load");
    }
    else
    {
        node<A_Type,B_Type>* temp = GetHead();

        while(temp != NULL)
        {
            listFileOut << temp->item.name    << endl;
            listFileOut << temp->item.message << endl;
            temp = temp->next;
        }
    }
    listFile.close();
}

template<class A_Type, class B_Type>
void SortedList<A_Type,B_Type>::DeleteAll()
{
    //While List is not empty, delete from front
    while(head != NULL){
        node<A_Type,B_Type>* temp = head;
        if(head == tail){
            head = NULL;
            tail = NULL;
            --size;
        }
        else
        {
            head->next->prev = NULL;
            head = head->next;
            --size;
        }
        delete temp;
    }
}

#endif // SORTEDLIST_H
