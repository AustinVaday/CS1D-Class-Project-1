//#ifndef SORTEDLIST_H
//#define SORTEDLIST_H


//#include <QFile>
//#include <QDir>
//#include <QTextStream>
//#include <QMessageBox>
//#include <QResource>
//#include <QMap>
//#include <QDebug>

///*************************************************************
// * 		HOW TO USE
// *
// * 	A_Type = the object
// * 	B_Type = the value you want the object to be sorted by
// *  C_Type = The data type object will be searched by **currently not implemented**
// *
// * ******example******
// *
// * 	SortedList<Object_Type, string, int> theList;
// *
// * 	theList.Add( Object_Name, "Kyle Serio", 20);
// *
// ************************************************************/

///*struct contactUsInfo
//{
//    QString name;
//    QString message;
//};

//struct testiInfo
//{
//    QString name;
//    QString message;
//};*/

////STRUCT - what the list is made out of
//template <class A_Type,class B_Type>
//struct node
//{
//    A_Type item = A_Type();
//    B_Type sortValue = B_Type();
//    node* next = NULL;
//    node* prev = NULL;
//};

//template <class A_Type,class B_Type>
//class SortedList
//{
//public:
//    SortedList();
////    SortedList(const SortedList<A_Type, B_Type>& otherList); // copy constructor
//    ~SortedList();
//    void   Add(A_Type newVariable,B_Type ValueOfNew);
//    node<A_Type, B_Type>* GetHead();
//    A_Type SearchFor(B_Type serch);
//    B_Type SearchForReverse(A_Type search);
//    bool   Remove(B_Type search);
//    A_Type operator[](int index) const;
//    SortedList<A_Type, B_Type>& operator= (const SortedList<A_Type, B_Type> &newList);
//    void   DeleteAll();
//    void   SaveContactMessages();
//    int    Size() const;
//    void   Print();
//    bool   SearchForBool(B_Type );
//    node<A_Type,B_Type>* SearchForPtrWrap(B_Type search);

//private:

//    node<A_Type,B_Type>* SearchForPtr(B_Type search);
//    void SortAsReadIn(node<A_Type,B_Type>* newNode);

//    node<A_Type,B_Type>* head;
//    node<A_Type,B_Type>* tail;
//    int size;
//};

//template <class A_Type,class B_Type>
//int SortedList<A_Type,B_Type>::Size() const
//{
////    node<A_Type,B_Type>* temp = head;
////    int count = 0;
////    while(temp != NULL)
////    {
////        temp = temp->next;
////        count++;
////    }
////    return count;

//    return size;
//}

//template <class A_Type,class B_Type>
//node<A_Type, B_Type>* SortedList<A_Type, B_Type>::GetHead()
//{
//    return head;
//}

//template <class A_Type,class B_Type>
//void SortedList<A_Type, B_Type>::Print()
//{
//    node<A_Type, B_Type>* temp = head;
//    while(temp != NULL)
//    {
////        QTextStream(stdout) << 1 << endl;
//        temp = temp->next;
//    }
//}
//template <class A_Type,class B_Type>
//A_Type SortedList<A_Type,B_Type>::operator[](int index) const
//{
//    if(index < size && index > -1)
//    {
//        node<A_Type,B_Type>* temp = head;

//        for(int i = 0; i != index; i++)
//        {
//            temp = temp->next;
//        }

//        if (temp!= NULL)
//        {
//        return temp->item;
//        }
//    }
//}

//template <class A_Type,class B_Type>
//SortedList<A_Type, B_Type>& SortedList<A_Type, B_Type>::operator= (const SortedList<A_Type, B_Type>& newList)
//{
//    qDebug() << "INSIDE op =";

//    if (head != NULL && this->size != 0 && tail != NULL)
//    {
//        qDebug() << "INSIDE if";
//        this->DeleteAll();
//        qDebug() << "INSIDE if 2 ";

//    }

//    this->size = newList.size;

//    qDebug() << "131";
//    for (int i = 0; i < newList.Size(); i++)
//    {
//        qDebug() << "134";

//        if (!SearchForBool(newList[i].GetName()))
//        {
//            qDebug() << "142";

//            this->Add(newList[i], newList[i].GetName());
//        }
//    }
//    qDebug() << "147";

//    return *this;
//}

//template <class A_Type,class B_Type>
//node<A_Type,B_Type>* SortedList<A_Type,B_Type>::SearchForPtr(B_Type search)
//{
//    node<A_Type,B_Type>* temp;
//    bool found = false;

//    temp = head;

//    while(!found && temp!=NULL)
//    {
//        if(temp->sortValue == search)
//        {
//            found = true;
//        }
//        else
//        {
//            temp = temp->next;
//        }
//    }

//    return temp;
//}
//template <class A_Type,class B_Type>
//bool SortedList<A_Type,B_Type>::Remove(B_Type search)
//{
//    node<A_Type,B_Type>* temp = SearchForPtr(search);
//    bool found = true;

//    // Checks if the item was found
//    if(temp != NULL)
//    {
//        // Checks if its the first item in the list
//        if(temp->prev == NULL)
//        {
//            // Checks if there is only one item in the list
//            if(temp->next != NULL)
//            {
//                head = temp->next;
//                temp->next->prev = NULL;
//            }
//            else
//            {
//                head = NULL;
//                tail = NULL;
//            }

//        }
//        // Checks if its the last item in the list
//        else if(temp->next == NULL)
//        {
//            tail = temp -> prev;
//            temp -> prev -> next = NULL;
//        }
//        // For items in the middle of the list
//        else
//        {
//            temp->prev->next = temp->next;
//            temp->next->prev = temp->prev;
//        }
//        size--;
//        delete temp;
//    }
//    else
//    {
//        found = false;
//    }

//    return found;
//}

//template <class A_Type,class B_Type>
//node<A_Type,B_Type>* SortedList<A_Type, B_Type>::SearchForPtrWrap(B_Type search)
//{
//    return SearchForPtr(search);
//}

//template <class A_Type,class B_Type>
//A_Type SortedList<A_Type,B_Type>::SearchFor(B_Type search)
//{
//    node<A_Type,B_Type>* temp;
//    bool found = false;

//    temp = head;

//    while(!found && temp!=NULL)
//    {
//        if(temp->sortValue == search)
//        {
//            found = true;
//        }
//        else
//        {
//            qDebug() << "LAAA" << temp->sortValue;
//            temp = temp->next;
//        }
//    }

//    return temp->item;
//}
//template <class A_Type,class B_Type>
//B_Type SortedList<A_Type,B_Type>::SearchForReverse(A_Type search)
//{
//    node<A_Type,B_Type>* temp;
//    bool found = false;

//    qDebug() << search.val;

//    temp = head;

//    while(!found && temp!=NULL)
//    {
//        if(temp->item == search)
//        {
//            found = true;
//        }
//        else
//        {
//            temp = temp->next;
//        }
//    }

//    return temp->sortValue;
//}


//template <class A_Type,class B_Type>
//bool SortedList<A_Type,B_Type>::SearchForBool(B_Type search)
//{
//    node<A_Type,B_Type>* temp;
//    bool found = false;

//    temp = head;

//    while(!found && temp!=NULL)
//    {
//        if(temp->sortValue == search)
//        {
//            found = true;
//        }
//        else
//        {
//            temp = temp->next;
//        }
//    }

//    return found;
//}

//template <class A_Type,class B_Type>
//SortedList<A_Type,B_Type>::SortedList()
//{
//    size = 0;
//    head = NULL;
//    tail = NULL;
//}

////template <class A_Type,class B_Type>
////SortedList<A_Type,B_Type>::SortedList(const SortedList<A_Type, B_Type>& otherList) // copy constructor
////{
////    if (this != &otherList)
////    {
////        qDebug() << "inside copy constructor";
////        this->operator=( otherList);
////    }
////}

//template <class A_Type,class B_Type>
//SortedList<A_Type,B_Type>::~SortedList()
//{
//    DeleteAll();
//}

//template <class A_Type,class B_Type>
//void SortedList<A_Type,B_Type>::Add(A_Type newVariable,B_Type ValueOfNew)
//{
//    node<A_Type,B_Type>* temp = new node<A_Type,B_Type>;
//    temp->item = newVariable;
//    temp->sortValue = ValueOfNew;


//    qDebug() << "\n\n\n\n\nSORT VL: " << temp->sortValue;
//    if(head == NULL)
//    {
//        head = temp;
//        tail = temp;
//        temp->next = NULL;
//        temp->prev = NULL;
//        size ++;
//    }
//    else
//    {
//        SortAsReadIn(temp);
//        size++;
//    }
//    temp = NULL;

//    qDebug() << " SORTEDLIST.H";

//}

//template <class A_Type,class B_Type>
//void SortedList<A_Type,B_Type>::SortAsReadIn(node<A_Type,B_Type>* newNode)
//{
//    node<A_Type,B_Type>* temp = head;

//    if(newNode->sortValue <= head->sortValue)
//    {
//        newNode->next = temp;
//        head->prev = newNode;
//        head = newNode;
//        newNode->prev = NULL;
//    }
//    else if(head->next == NULL && head->prev == NULL)
//    {
//        if(newNode->sortValue <= head->sortValue)
//        {
//            newNode->next = head;
//            head->prev = newNode;
//            head = newNode;
//            newNode->prev = NULL;
//        }
//        else
//        {
//            head->next = newNode;
//            newNode->prev = head;
//            newNode->next = NULL;
//            tail = newNode;
//        }
//    }
//    else
//    {
//        while(temp != NULL && newNode->sortValue > temp->sortValue)
//        {
//            temp = temp->next;
//        }

//        if(temp != NULL)
//        {
//            newNode->next = temp;
//            newNode->prev = temp->prev;
//            newNode->prev->next = newNode;
//            temp->prev = newNode;
//        }
//        else
//        {
//            newNode->next = NULL;
//            newNode->prev = tail;
//            newNode->prev->next = newNode;
//            tail = newNode;
//        }
//    }
//}

//template<class A_Type, class B_Type>
//void SortedList<A_Type, B_Type>::SaveContactMessages()
//{
//    QFile       listFile("ContactUs.txt");
//    QTextStream listFileOut(&listFile);

//    if(!listFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
//    {
//        QMessageBox::information(0,"Critical Failure","Contact message file has failed to load");
//    }
//    else
//    {
//        node<A_Type,B_Type>* temp = GetHead();

//        while(temp != NULL)
//        {
//            listFileOut << temp->item.name    << endl;
//            listFileOut << temp->item.message << endl;
//            temp = temp->next;
//        }
//    }
//    listFile.close();
//}

//template<class A_Type, class B_Type>
//void SortedList<A_Type,B_Type>::DeleteAll()
//{
//    qDebug() << "INSIDE DELETEALL";

//   node<A_Type,B_Type> *traversePtr;

//        traversePtr = head;
//        qDebug() << "430";


//        while(traversePtr != NULL)
//        {
//            qDebug() << "434";

//            qDebug() << "Size: " << this->size;
////            qDebug() << "data" <<
//            traversePtr = traversePtr->next;

//            qDebug() << "438";

//            delete head;


//            qDebug() << "442";

//            head = traversePtr;
//            qDebug() << "446";

//        }

//        head = NULL;
//        tail = NULL;
//        size = 0;
//}

//#endif // SORTEDLIST_H
