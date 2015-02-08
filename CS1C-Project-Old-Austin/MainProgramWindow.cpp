#include "MainProgramWindow.h"
#include <assert.h>

MainProgramWindow::MainProgramWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainProgramWindow),
	adminLogin(false),
	customerLogin(false),
	guestLogin(false),
	createAccount(false)
{
	// Hard code of admin login
	Admin testAdmin("","admin1234@gmail.com", 1234, "");

	ui->setupUi(this);

	// Determines if data base has been created

	try
	{
		if(!databaseCreated)
		{
			if(!(databaseCreated = CreateDatabase()))
			{
					throw "DATABASE FAILED";
			}

		}

	}
	catch(QString f)
	{
		QMessageBox terminate;
		terminate.setText(f);
		terminate.setWindowTitle("ERROR!");
		QApplication::quit();
	}

	ui->tempDisplay->setText(customerList.OutputList());

// Debuggin
qDebug() << "Admin window: Output List, Line 36";
qDebug() << customerList.OutputList();



    // Initialize
    hWindow = new HelpWindow;
    aWindow = new AdminWindow(this, customerList);
    bWindow = new BrochureWindow(this);
    gWindow = new GuestWindow;
    sWindow = new SignUpWindow;
    cWindow = new ContactUs(this);
    bWindow = new BrochureWindow;
    testWindow = new Testimonial;

    // ***DEBUG** List is read.
qDebug() << customerList.OutputList() << "Main Program Window: "
" customerList.OutputList - Line 27";

    connect(aWindow, SIGNAL(clicked()), this, SLOT(on_pushButton_Help_clicked()));

    connect(bWindow, SIGNAL(clicked()), this, SLOT(on_pushButton_Help_clicked()));

    connect(testWindow, SIGNAL(returnString(QString)),this, SLOT(updateTestimonial(QString)));

    // Shows the main program buttons when first logging in

}

MainProgramWindow::~MainProgramWindow()
{

	robotList.WriteToFile();
	robotList.ClearList();


    customerTestimonial = testWindow->getTestimonial();
    qDebug() << "My testimonials are : " << customerTestimonial;

	customerList.WriteToFile();
	customerList.ClearList();


	delete aWindow;
	delete bWindow;
	delete hWindow;
	delete gWindow;
	delete sWindow;
	delete cWindow;
	delete ui;
}

void MainProgramWindow::on_pushButton_Login_clicked()
{
	Admin	Administrator("admin","admin1234@gmail.com", 1234, "password");
	int		customerLocation;
	bool	validInput = false;
	QString tempName;
	QString tempPassword;
	Login   loginWindow;
	ErrorLogin errorWindow;
	Customer tempCustomer;


	customerLocation = 0;
	loginWindow.setModal(true);
	loginWindow.exec();
	loginWindow.on_buttonBox_loginPress_accepted(tempName, tempPassword);

	// Stores the tempname and password
	SetUsername(tempName);
	SetPassword(tempPassword);

	if(Administrator.checkAdmin(tempName, tempPassword ))
	{
		validInput = true;
		SetAdminLogin(true);
	}
	else
	{	// Compare user input to database
		tempCustomer =  customerList.VerifyCustomer(tempName, tempPassword);
		if(tempCustomer.getUserName() != " ")
		{
			validInput = true;
			SetCustomerLogin(true);
		}
	}
	if(!loginWindow.on_buttonBox_loginPress_rejected())
	{
		// ERROR MESSAGES LOGIN REJECTED DISPLAY
		errorWindow.setModal(true);
		errorWindow.exec();
		errorWindow.show();
	}
	if(validInput)
	{
		if(adminLogin)
		{
			aWindow->show();	// ADMIN
		}
		else if(customerLogin)
		{
			bWindow->show();    // BROCHURE
		}
	}
}
// Launches Window depending which button is clicked
void MainProgramWindow::Launcher()
{

}
void MainProgramWindow::on_exitProgram_clicked()
{
	QApplication::quit(); // <-----EXITS PROGRAM
}
// SET DATA MEMBER METHODS
void MainProgramWindow::SetAdminLogin(bool state)
{
	adminLogin = state;
}
void MainProgramWindow::SetCustomerLogin  (bool state)
{
	customerLogin = state;
}

void MainProgramWindow::SetGuestLogin  (bool state)
{
	guestLogin = state;
}
void MainProgramWindow::SetCreateAccount  (bool state)
{
	createAccount = state;
}
// G E T ~ M E T H O D S
bool MainProgramWindow::GetAdminLoginState()
{
	return adminLogin;
}
bool MainProgramWindow::GetCustomerLoginState()
{
	return customerLogin;
}
bool MainProgramWindow::GetGuestLoginState()
{
	return guestLogin;
}
bool MainProgramWindow::GetCreateAccountState()
{
	return createAccount;
}
QString MainProgramWindow::GetUsername()
{
	return userName;
}
QString MainProgramWindow::GetPassword()
{
	return password;
}
void MainProgramWindow::SetUsername(QString newUserName)
{
	userName = newUserName;
}
void MainProgramWindow::SetPassword(QString newPassword)
{
	password = newPassword;
}
// HELP WIDNOW - 2x Buttons Display 1 Window
void MainProgramWindow::on_pushButton_Help_clicked()
{
	hWindow->show();
}
void MainProgramWindow::on_actionHelp_triggered()
{
	hWindow->show();
}
// Updates Customer List
void MainProgramWindow::updateCustomerList(CustomerList *list)
{
	// if adminwindow is not open, update it's customer list.
	if (!aWindow->isVisible())
	{
		aWindow = new AdminWindow(this, customerList);
	}

	customerList = *list;
	ui->tempDisplay->clear();
	ui->tempDisplay->setText(customerList.OutputList());

//    customerList.WriteToFile();
}

void MainProgramWindow::on_pushButton_Guest_clicked()
{
	gWindow->show();
}


/*******************************************************************************
 *  CreateDatabase
 * -----------------------------------------------------------------------------
 * Instantiates the default database for each customer. Database will be update
 *  when a full execution cycle occurs, e.g. run executable, modify data,
 *  terminate program and repeat.
 * --------------------------------------------------------------------------
 * Returns boolean
 ************************************************************************/
bool MainProgramWindow::CreateDatabase()
{
	bool readStatus;
	readStatus = false;

	// Reads from default list
	if(!(readStatus = (this->robotList.ReadFile())))
	{
		Q_ASSERT(readStatus);
	}

	if(!(readStatus = (this->customerList.ReadFile())))
	{
		Q_ASSERT(readStatus);
	}

	return readStatus;
}
void MainProgramWindow::on_pushButton_RequestBrochure_clicked()
{
	Customer customer;
	bool properFields = false;
	sWindow->setModal(true);

QMessageBox::information(this, "lol", "lol");
	int submitSuccess = sWindow->exec();

	if (submitSuccess)
	{
		sWindow->on_buttonBox_accepted(customer, properFields);

		if (properFields)
		{
			// check if the customer is not taken
			if (!customerList.isExist(customer)
			&& !customerList.isExistSameName(customer.getUserName()))
			{
				customerList.Enqueue(customer);
				updateCustomerList(&customerList);
				QMessageBox::information(this, tr("Registration Successful"),tr("\"%1\", you will be notified shortly whether you have been accepted or rejected.").arg(customer.getUserName()));

			// SIGNALS & SLOTS
			// emit customerListChanged(&customerList);

			}
			else if (customerList.isExistSameName(customer.getUserName()))
			{
				QMessageBox::information(this, tr("Registration Unsuccessful"),tr("Please enter in another name,""\"%1\" is already taken").arg(customer.getUserName()));
			}
			else
			{

				QMessageBox::information(this, tr("Registration Unsuccessful"),
					tr("\"%1\" is already in your "
					"customer list.").arg(customer.getUserName()));

			}
		}
		qDebug() << customer.OutputData();
	}
}

void MainProgramWindow::on_actionContactUS_triggered()
{
	cWindow->show();
}

void MainProgramWindow::on_pushButton_clicked()
{
    QString mystring = "Here are recent customer testimonials!\n";
    testWindow->setTestimonial(mystring);
    testWindow->show();


}

void MainProgramWindow::updateTestimonial(QString newTestimonial)
{
    customerTestimonial = newTestimonial;
}
