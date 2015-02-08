#include "customeraddressbook.h"
#include "ui_customeraddressbook.h"


CustomerAddressBook::
CustomerAddressBook(QWidget* parent, CustomerList &list, int listNum)
				:	QDialog(parent), ui(new Ui::CustomerAddressBook)
{
	// Creates a copy of the list to be modified
    customerList = list;
    Customer  customer;

	// CONNECT THE EDIT, REMOVE, AND SUBMIT BUTTONS
	//	Connects signals to the parent window, Allows for communication of
	//	data between windows and objects
    connect(this, SIGNAL(customerListChanged(CustomerList*)), parent, SLOT(updateCustomerList(CustomerList*)));

   ui->setupUi(this);

    // name title
    setWindowTitle(tr("List of Customers"));

    // set read only text on construct
    ui->EDIT_name->setReadOnly(true);
    ui->EDIT_email->setReadOnly(true);
    ui->EDIT_account->setReadOnly(true);
    ui->EDIT_password->setReadOnly(true);
    ui->ActivatedCustomer->setEnabled(false);
    ui->EDIT_addressLine1->setEnabled(true);
    ui->EDIT_addressLine2->setEnabled(true);
    ui->EDIT_interest->setEnabled(true);
    ui->EDIT_value->setEnabled(true);
    ui->addButton->show();
    ui->submitButton->hide();
    ui->cancelButton->hide();

    //disable the next and previous buttons
    if (list.isEmpty())
    {
        ui->nextCustomerButton->setEnabled(false);
        ui->prevCustomerButton->setEnabled(false);

        // disable the edit and remove buttons
        ui->editButton->setEnabled(false);
        ui->removeButton->setEnabled(false);
    }
   else
    {
        // set the current display to whatever was clicked!!
        if (listNum >= 0 && listNum <= customerList.Size())
        {
            // both lists start at 0
           customer = customerList[listNum];

           SetCurrentDisplay(&customer);
		} // End if
	} // End Else
}// End Constructor

CustomerAddressBook::~CustomerAddressBook()
{
	// CUSTOMER LIST NEEDS TO BE CLEARED
	customerList.ClearList();
    delete ui;
}

void CustomerAddressBook::updateInterface (Mode mode)
{
    currentMode = mode;
    switch(currentMode)
    {
    case ADDING_MODE:
    case EDITING_MODE:
        qDebug() << "Line 74 customerAddressBook.cpp";

        // set read only text on construct
        ui->EDIT_name->setReadOnly(false);
        ui->EDIT_email->setReadOnly(false);
        ui->EDIT_account->setReadOnly(false);
        ui->EDIT_password->setReadOnly(false);
        ui->EDIT_addressLine1->setReadOnly(false);
        ui->EDIT_addressLine2->setReadOnly(false);
        ui->EDIT_value->setReadOnly(false);
        ui->EDIT_interest->setReadOnly(false);

        if (currentMode == EDITING_MODE)
        {
            ui->ActivatedCustomer->setEnabled(true);
        }
        else
        {
            ui->ActivatedCustomer->hide();
        }

        ui->EDIT_name->setFocus(Qt::OtherFocusReason);
        ui->addButton->setEnabled(false);
        ui->editButton->setEnabled(false);
        ui->removeButton->setEnabled(false);

        //disable the next and previous buttons
        ui->nextCustomerButton->setEnabled(false);
        ui->prevCustomerButton->setEnabled(false);

        // disable the edit and remove buttons
        ui->submitButton->show();
        ui->cancelButton->show();

		break;

    case NAVIGATION_MODE:

        ui->ActivatedCustomer->show();
        if (customerList.isEmpty())
        {
            ui->EDIT_name->clear();
            ui->EDIT_email->clear();
            ui->EDIT_account->clear();
            ui->EDIT_password->clear();
            ui->EDIT_addressLine1->clear();
            ui->EDIT_addressLine2->clear();
            ui->EDIT_interest->clear();
            ui->EDIT_value->clear();
            ui->ActivatedCustomer->setChecked(false);
        }

        // set read only text on construct
        ui->EDIT_name->setReadOnly(true);
        ui->EDIT_email->setReadOnly(true);
        ui->EDIT_account->setReadOnly(true);
        ui->EDIT_password->setReadOnly(true);
        ui->ActivatedCustomer->setEnabled(false);
        ui->EDIT_addressLine1->setEnabled(true);
        ui->EDIT_addressLine2->setEnabled(true);
        ui->EDIT_value->setReadOnly(true);
        ui->EDIT_interest->setReadOnly(true);

        int number = customerList.Size();

        // enables
        ui->editButton->setEnabled(number>=1);
        ui->removeButton->setEnabled(number>=1);
        ui->nextCustomerButton->setEnabled(number>1);
        ui->prevCustomerButton->setEnabled(number>1);
        ui->addButton->setEnabled(true);
        ui->submitButton->hide();
        ui->cancelButton->hide();
		break; // END NAVIGATION MODE
    }
}

void CustomerAddressBook::importList(CustomerList list)
{
    customerList = list;
}

void CustomerAddressBook::SetCurrentDisplay(Customer* someCustomer)
{
    // update the fields with next customer!
    ui->EDIT_name->setText(someCustomer->getUserName());
    ui->EDIT_email->setText(someCustomer->getEmail());
    ui->EDIT_account->setText(QString::number(someCustomer->getAccountNum()));
    ui->EDIT_password->setText(someCustomer->getPassword());
    ui->EDIT_addressLine1->setText(someCustomer->getAddressLine1());
    ui->EDIT_addressLine2->setText(someCustomer->getAddressLine2());
    ui->EDIT_value->setText(someCustomer->getKey());
    ui->EDIT_interest->setText(someCustomer->getInterest());

    if(someCustomer->getAccess())
    {
        ui->ActivatedCustomer->setChecked(true);
    }
    else
    {
        ui->ActivatedCustomer->setChecked(false);
    }
}

void CustomerAddressBook::on_addButton_clicked()
{

    // store old information into variables
    // (in case they submition)

    oldName         = ui->EDIT_name->text();
    oldEmail        = ui->EDIT_email->text();
    oldId           = ui->EDIT_account->text();
    oldPassword     = ui->EDIT_password->text();
    oldAddressLine1 = ui->EDIT_addressLine1->text();
    oldAddressLine2 = ui->EDIT_addressLine2->text();
    oldKey          = ui->EDIT_value->text();
    oldInterest     = ui->EDIT_interest->text();

    oldIsActivated = ui->ActivatedCustomer->isChecked();

    //disable the next and previous buttons
    ui->nextCustomerButton->setEnabled(false);
    ui->prevCustomerButton->setEnabled(false);

    // clear the fields, prepare for new entry
    ui->EDIT_name->clear();
    ui->EDIT_email->clear();
    ui->EDIT_account->clear();
    ui->EDIT_password->clear();
    ui->EDIT_addressLine1->clear();
    ui->EDIT_addressLine2->clear();
    ui->EDIT_interest->clear();
    ui->EDIT_value->clear();
    ui->ActivatedCustomer->setChecked(false);

    updateInterface(ADDING_MODE);
}

void CustomerAddressBook::on_submitButton_clicked()
{
    // store new contact details in variables

    QString name         = ui->EDIT_name->text();
    QString email        = ui->EDIT_email->text();
    QString idString     = ui->EDIT_account->text();
    QString pass         = ui->EDIT_password->text();
    QString addressLine1 = ui->EDIT_addressLine1->text() + "\n";
    QString addressLine2 = ui->EDIT_addressLine2->text() + "\n";
    QString interest     = ui->EDIT_interest->text();
    QString key          = ui->EDIT_value->text();
    QString address      = addressLine1 + "\n" + addressLine2;

	bool  activationStatus = false;

    if(ui->ActivatedCustomer->isChecked())
    {
        activationStatus = true;
    }

	if (currentMode == ADDING_MODE)
    {
        Customer customer (name, address, interest,key, pass, email, idString.toLong());
        customer.setAccountAccess(activationStatus);

        // check if any field is empty
        if (name.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                       tr("Please enter in a name."));
            on_cancelButton_clicked();
        }
        else if (email.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                       tr("Please enter in an email address."));
            on_cancelButton_clicked();

        }
        else if (addressLine1.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                       tr("Please enter in an Address in line 1."));
            on_cancelButton_clicked();
        }
        else if (addressLine2.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                       tr("Please enter in an Address in line 1."));
            on_cancelButton_clicked();
        }
        else if (interest.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                       tr("Please enter the customer interest."));
            on_cancelButton_clicked();
        }
        else if (key.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                       tr("Please enter the customer key."));
            on_cancelButton_clicked();
        }
        else if (idString.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                       tr("Please enter in an ID number."));
            on_cancelButton_clicked();

        }
        else if (pass.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                       tr("Please enter in a password."));
            on_cancelButton_clicked();
        }
        else
         {
            // check if the customer is not taken
           if (!customerList.isExist(customer) && !customerList.isExistSameName(name))
           {
               customerList.Enqueue(customer);

               QMessageBox::information(this, tr("Add Successful"),
                tr("\"%1\" has been added to the customer list.").arg(name));

               // SIGNALS & SLOTS
               emit customerListChanged(&customerList);
            }
           else if (customerList.isExistSameName(name))
           {
               QMessageBox::information(this, tr("Add Unsuccessful"),
                tr("Please enter in another name, \"%1\" is already in your customer list.").arg(name));
               on_cancelButton_clicked();
			}// Else if
			else
            {
				QMessageBox::information(this, tr("Add Unsuccessful"),
                tr("\"%1\" is already in your customer list.").arg(name));
				on_cancelButton_clicked();
			}// END ELSE
  }// END
            //Restore the buttons to their normal state.
            ui->addButton->setEnabled(true);
            ui->submitButton->hide();
            ui->cancelButton->hide();

            // if list greater than one, enable the next and prev buttons
            int sizeList = customerList.Size();
            ui->nextCustomerButton->setEnabled(sizeList>1);
            ui->prevCustomerButton->setEnabled(sizeList>1);

            // set read only text on construct
            ui->EDIT_name->setReadOnly(true);
            ui->EDIT_email->setReadOnly(true);
            ui->EDIT_account->setReadOnly(true);
            ui->EDIT_password->setReadOnly(true);
            ui->ActivatedCustomer->setEnabled(false);
            ui->EDIT_interest->setEnabled(true);
            ui->EDIT_value->setEnabled(true);
            ui->EDIT_addressLine1->setEnabled(true);
            ui->EDIT_addressLine2->setEnabled(true);


    }
    else if (currentMode == EDITING_MODE)
    {
        qDebug() << "ooo4";
        bool change = false;

		Customer newCust (name, address, interest,
						  key,  pass,      email, idString.toLong());

        newCust.setAccountAccess(activationStatus);

        try
        {
         Customer* customerPtr = customerList.ReturnCustomerPtr(oldName);
         customerPtr->setAccountAccess(oldIsActivated);

         if (oldName != name || oldEmail != email || oldId != idString || oldPassword != pass || oldIsActivated != activationStatus)
         {
             change = true;
         }
         // check if any field is empty
         if (name.isEmpty())
         {

             QMessageBox::information(this, tr("Empty Field"),
                        tr("Please enter in a name."));
             on_cancelButton_clicked();
         }
         else if (email.isEmpty())
         {
             QMessageBox::information(this, tr("Empty Field"),
                        tr("Please enter in an email address."));
             on_cancelButton_clicked();

         }
         else if (idString.isEmpty())
         {
             QMessageBox::information(this, tr("Empty Field"),
                        tr("Please enter in an ID number."));
             on_cancelButton_clicked();

         }
         else if (pass.isEmpty())
         {
             QMessageBox::information(this, tr("Empty Field"),
                        tr("Please enter in a password."));
             on_cancelButton_clicked();

         }
         else if (key.isEmpty())
         {
            QMessageBox::information(this, tr("Empty Field"),
                        tr("Please enter in a key value."));
             on_cancelButton_clicked();
         }
         else if (addressLine1.isEmpty() || addressLine2.isEmpty())
         {
            QMessageBox::information(this, tr("Empty Field"),
                        tr("Please enter in an address."));
             on_cancelButton_clicked();
         }
         else if (interest.isEmpty())
         {
            QMessageBox::information(this, tr("Empty Field"),
                        tr("Please enter in the customer's interest."));
             on_cancelButton_clicked();
         }
         else if (!change)
         {
             QMessageBox::information(this, tr("Edit Unsuccessful"),
               tr("No changes were made."));
             on_cancelButton_clicked();
         }
         else if (customerList.isExist(newCust))
         {
             QMessageBox::information(this, tr("Edit Unsuccessful"),
               tr("Sorry, \"%1\" is already in your address book.").arg(name));
             on_cancelButton_clicked();
         }
         else
         {
            QMessageBox::information(this, tr("Edit Successful"),
               tr("\"%1\" has been edited in your address book.").arg(oldName));

			// SETS CUSTOMER DATA
            customerPtr->setUserName(name);
            customerPtr->setEmail(email);
            customerPtr->setAccountNum(idString.toLong());
            customerPtr->setPassword(pass);
            customerPtr->setAccountAccess(activationStatus);
            customerPtr->setAddress(address);
            customerPtr->setInterest(interest);
            customerPtr->setKey(key);

			  // EMIT - > PARENT SIGNAL
              emit customerListChanged(&customerList);
         }
         customerPtr = NULL;
        }
        catch (...)
        {
            QMessageBox::information(this, tr("Edit Unsuccessful"),
              tr("Sorry, \"%1\" an exception/error has occured.").arg(name));
            on_cancelButton_clicked();
        }
    }
//	SIGNALS & SLOTS THIS IS EXCESSIVE
	emit customerListChanged(&customerList);
    updateInterface(NAVIGATION_MODE);
}

void CustomerAddressBook::on_cancelButton_clicked()
{
    // reset all old data
    ui->EDIT_name->setText(oldName);
    ui->EDIT_email->setText(oldEmail);
    ui->EDIT_account->setText(oldId);
    ui->EDIT_password->setText(oldPassword);
    ui->EDIT_addressLine1->setText(oldAddressLine1);
    ui->EDIT_addressLine2->setText(oldAddressLine2);
    ui->EDIT_interest->setText(oldInterest);
    ui->EDIT_value->setText(oldKey);

    if (oldIsActivated)
    {
        ui->ActivatedCustomer->setChecked(true);
    }
    else
    {
        ui->ActivatedCustomer->setChecked(false);
	}
    updateInterface(NAVIGATION_MODE);
}

void CustomerAddressBook::on_nextCustomerButton_clicked()
{
    // get the next element, if out of range... re-loop...
    QString name = ui->EDIT_name->text();
    Customer someCustomer;

    try
    {
        int index = customerList.FindCustomerLocation(name);

        if (!customerList.isEmpty() && customerList.Size() != 1)
         {
            // if index is the last one, start from beginning of list.
            if ((index+1) == customerList.Size())
            {

                someCustomer = customerList[0];
                ui->warningLabel->setText("You've reached the end of the list, re-starting from the beginning!");
            }
            else
            {
                // get next customer!
                someCustomer = customerList[++index];
                ui->warningLabel->setText("");
			}
              SetCurrentDisplay(&someCustomer);
        }
        else
		{
		// ************** REPLACE WITH EXCEPTION ****************
			qDebug() << "11";
        }
    }
    catch(...)
    {
	// ************** REPLACE WITH EXCEPTION ****************
		qDebug() << "12";
    }
}

void CustomerAddressBook::on_prevCustomerButton_clicked()
{
    // get the next element, if out of range... re-loop...

    QString name = ui->EDIT_name->text();
    Customer someCustomer;
    int index = customerList.FindCustomerLocation(name);


    if (!customerList.isEmpty() && customerList.Size() != 1)
    {
        // if index is the first one, start from end of list.
        if (index == 0)
        {

            someCustomer = customerList[customerList.Size() - 1];
            ui->warningLabel->setText("You've reached the beginning of the list, re-starting from the end!");
        }
        else
        {
            // get next customer!
            someCustomer = customerList[--index];
            ui->warningLabel->setText("");
        }

        // update the fields with next customer!
        SetCurrentDisplay(&someCustomer);
    }
    else
    {
        ui->nextCustomerButton->setEnabled(false);
        ui->prevCustomerButton->setEnabled(false);
    }
}

void CustomerAddressBook::on_editButton_clicked()
{
    // store old information into variables
    // (in case they cancel edit)
    oldName        = ui->EDIT_name->text();
    oldEmail       = ui->EDIT_email->text();
    oldId          = ui->EDIT_account->text();
    oldPassword    = ui->EDIT_password->text();
    oldIsActivated = ui->ActivatedCustomer->isChecked();

    updateInterface(EDITING_MODE);
}

void CustomerAddressBook::on_removeButton_clicked()
{

	// INPUT DECLARATIONS
	//  RETRIEVES ALL DATA TO CREATE AN OBJECT TO COMPARE AND DELETE FROM THE
	//  CUSTOMER LIST
	QString name		 = ui->EDIT_name->text();
	QString email		 = ui->EDIT_email->text();
	QString idString	 = ui->EDIT_account->text();
	QString pass		 = ui->EDIT_password->text();
    QString addressLine1 = ui->EDIT_addressLine1->text() + "\n";
    QString addressLine2 = ui->EDIT_addressLine2->text() + "\n";
	QString interest	 = ui->EDIT_interest->text();
	QString key			 = ui->EDIT_value->text();
	QString address		 = addressLine1 + addressLine2; // CONCATENATES STRINGS


    bool  activationStatus = false;

    if(ui->ActivatedCustomer->isChecked())
    {
        activationStatus = true;
    }

	Customer customer (name, address, interest, key,
					   pass, email, idString.toLong());

    customer.setAccountAccess(activationStatus);

    if (customerList.isExist(customer))
    {
        if (customer.getAccess())
        {
			QMessageBox::information(this, "Remove Insuccessful",
									 "Sorry, you can only delete "
									 "deactivated customers.\n If "
									 "you wish to delete this customer,"
									 "please deactivate it first. ");
        }
        else
        {
            int button = QMessageBox::question(this,
            tr("Confirm Remove"),
            tr("Are you sure you want to remove \"%1\"?").arg(name),
            QMessageBox::Yes | QMessageBox::No);

            if (button == QMessageBox::Yes)
            {
                on_prevCustomerButton_clicked();
                customerList.RemoveCustomer(customer);
                QMessageBox::information(this, tr("Remove Successful"),
                                 tr("\"%1\" has been removed from your address book.").arg(name));
                emit customerListChanged(&customerList);
            }
        }
    }
    updateInterface(NAVIGATION_MODE);
}
void CustomerAddressBook::on_searchButton_clicked()
{
	QString		name;
	Find*		searchName = new Find();
	Customer*	someCustomer;

	// Sets search for name to modal till found
    searchName->setModal(true);
    searchName->exec();
    name = searchName->return_searched_name();

    try
    {
        customerList.FindCustomer(name);
        QMessageBox::information(this, tr("Success!"),
							  tr("\"%1\" was found!").arg(name));

        someCustomer = customerList.ReturnCustomerPtr(name);
        SetCurrentDisplay(someCustomer);
        updateInterface(NAVIGATION_MODE);
    }
    catch (...)
    {

        if (name != "")
        {
            QMessageBox::information(this, tr("Sorry"),
                             tr("\"%1\" was not found").arg(name));
		}
	}// CATCH
}

void CustomerAddressBook::on_ActivatedCustomer_clicked()
{
    QString name = ui->EDIT_name->text();
    Customer *custPtr = customerList.ReturnCustomerPtr(name);
    custPtr->setAccountAccess(true);
    custPtr = NULL;

}
