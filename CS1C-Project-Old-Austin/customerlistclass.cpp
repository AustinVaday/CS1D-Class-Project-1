#include "customerlistclass.h"
#include <QTextStream>
#include <QMessageBox>
#include "ExceptionHandlers.h"
#include "activatedlist2.h"
#include "customerclass.h"

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
CustomerList::CustomerList()
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
CustomerList::~CustomerList()
{
	this->ClearList();
}

/**************************************************************************
* isFull
* ------------------------------------------------------------------------
* This method will check if the list is full and determine the amount of
* nodes left in the list
*************************************************************************/
bool CustomerList::isFull() const
{
	return _nodeCount == _listLimit;
}

Node<Customer>* CustomerList::GetHead() const
{
	return _head;
}

/**************************************************************************
* IncrementCount
* ------------------------------------------------------------------------
* This method will increment the _nodeCount by one
**************************************************************************/
void CustomerList::IncrementCount()
{
	_nodeCount += 1;
}

/**************************************************************************
* DecrementCount
* ------------------------------------------------------------------------
* This method will decrement the _nodeCount by one
**************************************************************************/
void CustomerList::DecrementCount()
{
	_nodeCount -= 1;
}

/**************************************************************************
* OutputList
* ------------------------------------------------------------------------
* This method will return a string with the entire list
**************************************************************************/
QString CustomerList::OutputList () const
{
	//D E C L A R A T I O N
	Node<Customer> * traverse;      //CALC - used to traverse the list
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
void CustomerList::ClearList()
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

Customer CustomerList::Front() const
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
void CustomerList::Enqueue(Customer data)
{
	//D E C L A R A T I O N S
	//	Node<typeName> * temp;
	//D E C L A R A T I O N S
	Node<Customer>*  _createNew;   //CALC - used to create dynamic memory

	//D E C L A R A T I O N S
	bool continueTraverse;
	Node<Customer>* _cursor;


	//Begin If only if the list is empty
	if(isEmpty())
	{
		//Creates new dynamic memory
		_createNew  = new Node<Customer>;

		//Sets the data of the newly created node
		_createNew->SetData(data);


		//Creates a new Object and stores data within it
		//Assigns _head and _tail to the new object created in dynamic memory
		_head = _createNew;
		_tail = _createNew;

		//		cout << "\nAdding " << _createNew->GetData() << " to the list.\n";
		//increments the _listCount

		_createNew = NULL;  /* ADDED BY AUSTIN */

		IncrementCount();
	}
	else if(_nodeCount < _listLimit)
	{

		//I N I T I A L I Z A T I O N S
		_cursor          = _head;
		continueTraverse = true;
		//Creates new dynamic memory
		_createNew  = new Node<Customer>;

		//Sets the data of the newly created node
		_createNew->SetData(data);
		//This "if-statement" is designed to add a node when there is only ONE node currently in the list
		// *
		if(_cursor->GetNext() == NULL)
		{

			if(_createNew->GetData().getUserName().toUpper() < _cursor->GetData().getUserName().toUpper())
			{

				_createNew->SetNext(_cursor);

				_cursor->SetPrevious(_createNew); /* ADDED BY AUSTIN */

				_head = _createNew;


			}
			else
			{

				_createNew->SetPrevious(_cursor);
				_cursor->SetNext(_createNew);
				_tail = _createNew;
			}

			_createNew = NULL; /* ADDED BY AUSTIN */

		}
		else // if _cursor->GetNext() != NULL
		{

			_cursor = _cursor->GetNext();

			//This loop is designed to traverse the current list and stop at a place to ensure
			//the node is added to the list according to alphabetical order
			while(_cursor != NULL && continueTraverse)
			{
				if((_createNew->GetData().getUserName().toUpper() < _cursor->GetData().getUserName().toUpper()))
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


		//Increments the current Count
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
Customer CustomerList::Dequeue()
{
	Node<Customer>* temp;
	Customer tempCustomer;

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

		tempCustomer = temp->GetData();


		delete temp;

		temp = NULL;
		}
	return tempCustomer;
}

/**************************************************************************
* IsEmpty
* ------------------------------------------------------------------------
* This method will check to see if the list is Empty
**************************************************************************/
bool CustomerList::isEmpty() const
{

	return _head == NULL;

}

/**************************************************************************
* Size
* ------------------------------------------------------------------------
* This method returns the size of the list
**************************************************************************/
int CustomerList::Size() const
{
	return _nodeCount;
}

void CustomerList::RemoveCustomer(Customer &someCustomer)
{
	Node<Customer> * traversePtr;
	Node<Customer> * actionPtr;

	if(isEmpty())
	{
		//		cout << "Can't Dequeue an empty list" << endl;
		throw EmptyList();
	}

	traversePtr = _head;
	int index = 0;

	while (index < _listLimit && traversePtr != NULL && !(traversePtr->GetData() == someCustomer))
	{

		traversePtr = traversePtr->GetNext();
		index++;
	}

	// overloaded operator
	if (traversePtr->GetData() == someCustomer)
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

Customer CustomerList::FindCustomer(QString userName)
{
	Node<Customer> * traversePtr;

	if(isEmpty())
	{
		throw EmptyList();
	}

	// NEED TO MAKE SURE 2 ACCOUNT NUMBERS CANNOT BE THE SAME //
	traversePtr = _head;
	int index = 0;
	while (index < _listLimit && traversePtr !=NULL &&
		   traversePtr->GetData().getUserName() != userName)
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

	return traversePtr->GetData();

}

Customer* CustomerList::ReturnCustomerPtr(QString userName)
{
	Node<Customer> * traversePtr;

	if(isEmpty())
	{
		throw EmptyList();
	}

	// NEED TO MAKE SURE 2 ACCOUNT NUMBERS CANNOT BE THE SAME //
	traversePtr = _head;
	int index = 0;
	while (index < _listLimit && traversePtr !=NULL &&
		   traversePtr->GetData().getUserName() != userName)
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

	Customer *dataPtr = traversePtr->GetDataPtr();


	return dataPtr;
}

int CustomerList::FindCustomerLocation (QString userName)
{
	Node<Customer> * traversePtr;

	if(isEmpty())
	{
		throw EmptyList();
	}

	// NEED TO MAKE SURE 2 ACCOUNT NUMBERS CANNOT BE THE SAME //
	traversePtr = _head;
	int index = 0;
	while (index < Size() && traversePtr !=NULL &&
		   traversePtr->GetData().getUserName() != userName)
	{
		traversePtr = traversePtr->GetNext();

		index++;
	}
	if (traversePtr == NULL)
	{
		qDebug() << "12";
		// throw exception class if not found.
		throw NotFound();
	}

	return index;
}

Customer CustomerList::operator[](int index) const
{
	Node<Customer> * traversePtr;

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

bool CustomerList::isExistSameName(QString name)
{
	try
	{
		for (int i = 0; i < this->Size(); i++)
		{
			if (this->operator[](i).getUserName() == name)
			{
				return true;
			}
		}
	}
	catch(NotFound)
	{
		qDebug() << "CATCH : customerListClass.cpp -- line 589";
	}

	return false;
}

bool CustomerList::isExist(Customer someCustomer)
{
	Node<Customer> * traversePtr;

	if(isEmpty())
	{
		return false;
	}

	traversePtr = _head;
	int i = 0;

	while (i < Size() && traversePtr !=NULL)
	{

		if (someCustomer == traversePtr->GetData())
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

void CustomerList::SortList(Node<Customer>* head)
{
	Node<Customer>* tempHead;
	int index;
	int temp;


	tempHead = head;

	for(index = 1; index < Size(); index++)
	{
		temp = index;

		while(temp > 0 && tempHead[temp-1].GetData().getUserName()> tempHead[temp].GetData().getUserName())
		{
			Swap(&tempHead[temp-1], &tempHead[temp]);


			temp--;
		}


	}
}// **** END METHOD **** //


void CustomerList::Swap(Node<Customer>* objectOne, Node<Customer>* objectTwo)
{
	QString tempString;
	long        tempLong;
	bool        tempBool;

	// SWAP USERNAME
	tempString = objectOne->GetData().getUserName();
	objectOne->GetData().setUserName(objectTwo->GetData().getUserName());
	objectTwo->GetData().setUserName(tempString);

	// SWAP EMAIL
	tempString = objectOne->GetData().getEmail();
	objectOne->GetData().setEmail(objectTwo->GetData().getEmail());
	objectTwo->GetData().setEmail(tempString);

	// SWAP PASSWORD
	tempString = objectOne->GetData().getPassword();
	objectOne->GetData().setPassword(objectTwo->GetData().getPassword());
	objectTwo->GetData().setPassword(tempString);

	// SWAP ACCOUNT NUM
	tempLong = objectOne->GetData().getAccountNum();
	objectOne->GetData().setAccountNum(objectTwo->GetData().getAccountNum());
	objectTwo->GetData().setAccountNum(tempLong);

	// SWAP ADDRESS LINE 1
	tempString = objectOne->GetData().getAddressLine1();
	objectOne->GetData().setAddressLine1(objectTwo->GetData().getAddressLine1());
	objectTwo->GetData().setAddressLine1(tempString);

	// SWAP ADDRESS LINE 2
	tempString = objectOne->GetData().getAddressLine2();
	objectOne->GetData().setAddressLine2(objectTwo->GetData().getAddressLine2());
	objectTwo->GetData().setAddressLine2(tempString);

	// SWAP INTEREST
	tempString = objectOne->GetData().getInterest();
	objectOne->GetData().setInterest(objectTwo->GetData().getInterest());
	objectTwo->GetData().setInterest(tempString);

	// SWAP KEY
	tempString = objectOne->GetData().getKey();
	objectOne->GetData().setKey(objectTwo->GetData().getKey());
	objectTwo->GetData().setKey(tempString);

	// SWAP ACTIVATED STATUS
	tempBool = objectOne->GetData().getAccess();
	objectOne->GetData().setAccountAccess(objectTwo->GetData().getAccess());
	objectTwo->GetData().setAccountAccess(tempBool);

}

Customer CustomerList::VerifyCustomer(QString userName, QString password)
{
	// DECLARATIONS
	Node<Customer>* cursor;
	Customer        tempCustomer;
	QString         name;
	QString         pw;
	bool			found;

	tempCustomer.setValues(" "," ",0," ");
	cursor = _head;
	found  = false;

	while(cursor != NULL && !found)
	{

		name = cursor->GetData().getUserName();
		pw   = cursor->GetData().getPassword();

		if((name == userName) && (pw == password))
		{
			tempCustomer = cursor->GetData();
			found = true;

		}
		else
		{
			cursor = cursor->GetNext();
		}
	}
	cursor = NULL;

	return tempCustomer;
}// **** END METHOD **** //


/****************************************************************
* Overload =    (assignment operators)
* --------------------------------------------------------------
*
*****************************************************************/
CustomerList& CustomerList::operator=(const CustomerList& list)
{

	if (this != &list)
	{
		int index;
		Customer copyCustomer;
		index = 0;

		//Before Assignment

		qDebug() << "Line 765 : Before CustomerLIst Assignment: " << this->OutputList();

		this->ClearList();

		// Only a temporary fix :( It's only adding to the queue not removing from it.
		if(!list.isEmpty())
		{
			for(index = 0; index < list.Size(); index++)
			{
				copyCustomer =list[index];
				this->Enqueue(copyCustomer);
			}

		}
		// After
	}
	return *this;
}// **** END METHOD **** //

/************************************************************
* WriteToFile
* -----------------------------------------------------------
* - Overloaded
*	- see WriteToFile(Qstring)
* Returns true only if it successfully writes
* Returns false if it fails to open, write or if there are
*  no customers in the list.
* ------------------------------------------------------------
* File path is set when first establishing the database
*************************************************************/
bool CustomerList::WriteToFile()
{
	Node<Customer>* _customerPtr;
	QDir dataPath = QDir::current();
	bool writeStatus;

	// Failstate signal
	writeStatus = false;

	// Initialize QFile and write failed, Appended File to path, QFile Creates

	while(dataPath.dirName() != "Class-Project")
	{
		dataPath.cdUp();
	}

	dataPath.cd("Database-Files");

	dataPath.remove((dataPath.path() + "/CustomerList.txt"));

	qDebug() << "Does the customer list file exist in the directory?" << dataPath.exists((dataPath.path() + "/CustomerList.txt"));

qDebug() << "Customer path: line 896 : " << dataPath.path();
	QFile customerDataFile((dataPath.path() + "/CustomerList.txt"));

qDebug() << "1) Is it open? "<< customerDataFile.isOpen() << "and can it be written? " <<
customerDataFile.isWritable();

	if(customerDataFile.open((QIODevice::ReadWrite | QIODevice::Text)|QIODevice::Truncate) && !isEmpty())
	{

	qDebug() << "1) Is it open? "<< customerDataFile.isOpen() << "and can it be written? " <<
customerDataFile.isWritable();
		qDebug() << "Debugging:: WRITE Customer :::  It opened ::: ";
		QTextStream out(&customerDataFile);
		_customerPtr = _head;

		while(_customerPtr != 0)
		{
			out << _customerPtr->GetData().getUserName() << "\n";
			out << _customerPtr->GetData().getAddressLine1()  << "\n";
			out << _customerPtr->GetData().getAddressLine2()  << "\n";
			out << _customerPtr->GetData().getInterest() << "\n";
			out << _customerPtr->GetData().getKey()      << "\n";
			out << _customerPtr->GetData().getPassword() << "\n";
			out << _customerPtr->GetData().getEmail() << "\n";
			out << _customerPtr->GetData().getAccountNum() << "\n";

			if((_customerPtr = _customerPtr->GetNext()) != 0)
			{
				out << "\n";
			}

		}// END WHILE
		// Flushes output buffer

		out.flush();
		writeStatus = true;

// Flushes and coses the data file
	customerDataFile.flush();
	customerDataFile.close();
	} // END OPEN FILE IF


	// Returns True or False status
	return writeStatus;

}// **** END METHOD **** //

/************************************************************
* ReadFile (Overloaded, DOES NOT allow to specify filePath)
* ----------------------------------------------------------
* Returns true only if it successfully reads
* Returns false if it fails to open, read or if there are no
*	customers in the database
* ----------------------------------------------------------
* File path is set when first establishing the database
*************************************************************/
bool CustomerList::ReadFile()
{
	bool readSuccessFull;
	QDir dataPath = QDir::current();

qDebug() << "Current path when reading " << dataPath.path();
	readSuccessFull = false;

	// QDir datapath is a pointer that points towards each directory

	while(dataPath.dirName() != "Class-Project")
	{
		dataPath.cdUp();
	}

	dataPath.cd("Database-Files");

	QFile customerDataFile((dataPath.path() + "/CustomerList.txt"));

	// This checks if the file opens, if it does not, it will display an
	//  error message
	if(customerDataFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{

		QString inputData[10];

		// Points Text stream to input file to read in.
		QTextStream inFile(&customerDataFile);
		while(!inFile.atEnd() && !this->isFull())
		{
											  // Data Type			| TXT FILE
			inputData[0] = inFile.readLine(); // Customer Name		| Line 1
			inputData[1] = inFile.readLine(); // Address Part 1		| Line 2
			inputData[2] = inFile.readLine(); // Address Part 2		| Line 3
			inputData[1] = inputData[1]		  // Concatenate		| N/A
						 + "\n"+ inputData[2];// addresses
			inputData[3] = inFile.readLine(); // Customer Interest	| Line 4
			inputData[4] = inFile.readLine(); // Customer Key		| Line 5
			inputData[5] = inFile.readLine(); // Passowrd			| Line 6
			inputData[6] = inFile.readLine(); // Email				| Line 7
			inputData[7] = inFile.readLine(); // Account ID			| Line 8

			// Adds the customer to customer list
			this->Enqueue(Customer(inputData[0], inputData[1], inputData[3],
								   inputData[4], inputData[5], inputData[6],
								   inputData[7].toLong()));
					inFile.skipWhiteSpace();
					inFile.flush();
		}
		// sets read true, flushes the Qtextstream buffer
		readSuccessFull = true;

		customerDataFile.flush();
		customerDataFile.close();
	}
	return readSuccessFull;

}// **** END METHOD **** //
