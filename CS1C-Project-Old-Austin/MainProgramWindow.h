#ifndef MAINPROGRAMWINDOW_H
#define MAINPROGRAMWINDOW_H

#include <QMainWindow>
#include "adminclass.h"
#include "login.h"
#include "loginhelp.h"
#include "LoginWindow.h"
#include "errorlogin.h"
#include "AdminWindow.h"
#include "ui_mainprogramwindow.h"
#include "WelcomeWidget.h"
#include "newactivatedlist.h"
#include "customerclass.h"
#include "customerlistclass.h"
#include "ui_AdminWindow.h"
#include "Header.h"
#include "helpwindow.h"
#include "BrochureWindow.h"
#include "ProductListClass.h"
#include "ProductClass.h"
#include "ViewProducts.h"
//#include "customerlistclass.h"
#include "ExceptionHandlers.h"
#include "sellpoint.h"
#include "guarantee.h"
#include "guestwindow.h"
#include "maintplan.h"
#include "environments.h"
#include "signupwindow.h"
#include "contactus.h"
#include "conceptofops.h"
#include "testimonial.h"

#include <QDebug>

namespace Ui {
class MainProgramWindow;
}

class MainProgramWindow : public QMainWindow
{
		Q_OBJECT

	public:         // Main Program, Initial Interface
		explicit MainProgramWindow(QWidget *parent = 0);

	// Sets Login state of the customer, Login state determines what list &
	//  window type / widget / dialogue to launch & types of data transfers
	//  of the customer list and the product list
		void SetAdminLogin     (bool state);
		void SetCustomerLogin  (bool state);
		void SetGuestLogin     (bool state);
		void SetCreateAccount  (bool state);

	// These get methods will be used to detemine what type of window to launch
		bool GetAdminLoginState();
		bool GetCustomerLoginState();
		bool GetGuestLoginState();
		bool GetCreateAccountState();

		// COMPOSITION gets product list
		ProductList* getProductList() const;

		// Gets user name and password for any login
		QString GetUsername();
		QString GetPassword();

		// Determines if to instatiate a database
		bool CreateDatabase();

		//  Accessors
		void SetUsername(QString newUsername);
		// Sets user name

		void SetPassword(QString newPassword);
		// Sets users password

		// user state == Admin || Brochure -> window
		void Launcher();

		~MainProgramWindow();

	signals:
		void clicked();
		// Signal to emit if anything is clicked on mainprogram window
		//  or main bar, commonly used signal

	public slots:
		// Displays Respective Windows

		void on_pushButton_Help_clicked();
		void on_exitProgram_clicked();
		void updateCustomerList(CustomerList *list);

	private slots:

		void on_pushButton_Login_clicked();
		//  Login Window Process Executes
		//      Login -> Customer || Admin || Denied
		void on_pushButton_clicked();
		void on_actionHelp_triggered();
		//  Help Window Appear

		void on_pushButton_Guest_clicked();
		void on_pushButton_RequestBrochure_clicked();
		void on_actionContactUS_triggered();
		void updateTestimonial(QString newTestimonial);

	private:
		Ui::MainProgramWindow *ui;
		QString customerTestimonial;
		Testimonial *testWindow;

		// PROGRAM SECTION WINDOWS
		AdminWindow *aWindow;
		// Pointer towards the admin window

		HelpWindow  *hWindow;
		GuestWindow *gWindow;
		// Pointer of type HelpWindow
		//  Used to create a help window for the user

		BrochureWindow* bWindow;
		SignUpWindow*   sWindow;
		ContactUs *     cWindow;

		ProductList     robotList;
		CustomerList    customerList;
		bool            databaseCreated = false;

		bool		adminLogin;
		bool		customerLogin;
		bool		createAccount;
		bool		guestLogin;

		QString		userName;
		QString		password;
};

#endif // MAINPROGRAMWINDOW_H
