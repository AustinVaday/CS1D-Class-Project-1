#-------------------------------------------------
#
# Project created by QtCreator 2014-11-14T15:41:36
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT_NO_DEBUG_OUTPUT

TARGET = MainProgram
TEMPLATE = app



SOURCES += main.cpp\
        MainProgramWindow.cpp \
        adminclass.cpp \
        userclass.cpp \
        customerlistclass.cpp \
        customerclass.cpp \
        ReadCustomerFile.cpp \
        newactivatedlist.cpp\
        maindisplay.cpp \
        AdminWindow.cpp \
        ProductClass.cpp \
        ProductListClass.cpp\
        customeraddressbook.cpp\
        errorlogin.cpp\
        firstdialog.cpp \
        helpwindow.cpp \
        login.cpp \
        loginhelp.cpp \
        navigatingapp.cpp \
        requestbrochure.cpp\
        orderproduct.cpp \
    BrochureWindow.cpp \
    CustomerPlaceOrder.cpp \
    ViewProducts.cpp\
    find.cpp \
    WriteToCustomerFile.cpp \
    customeraccountwindow.cpp \
    ImageViewer.cpp \
    sellpoint.cpp \
    guarantee.cpp \
    guestwindow.cpp \
    maintplan.cpp \
    environments.cpp \
    signupwindow.cpp \
    contactus.cpp \
    shoppingcartwindownew.cpp \
    ExceptionHandlers.cpp\
    conceptofops.cpp \
    testimonial.cpp

HEADERS += MainProgramWindow.h \
	adminclass.h \
	userclass.h \
	customerlistclass.h \
	customerclass.h \
	genericnodeclass.h \
	ExceptionHandlers.h \
	Header.h \
	newactivatedlist.h\
	maindisplay.h \
	AdminWindow.h \
	ProductClass.h \
	ProductListClass.h \
	customeraddressbook.h\
	errorlogin.h\
	firstdialog.h\
	helpwindow.h\
	login.h\
	loginhelp.h\
	navigatingapp.h\
	requestbrochure.h\
	orderproduct.h \
    BrochureWindow.h \
    CustomerPlaceOrder.h \
    ViewProducts.h\
    find.h \
    customeraccountwindow.h \
    ImageViewer.h \
    sellpoint.h \
    guarantee.h \
    guestwindow.h \
    maintplan.h \
    environments.h \
    signupwindow.h \
    contactus.h \
    ShoppingCartList.h\
    shoppingcartwindownew.h\
    conceptofops.h \
    testimonial.h


FORMS   += mainprogramwindow.ui \
	newactivatedlist.ui \
	maindisplay.ui \
	AdminWindow.ui\
	customeraddressbook.ui\
	errorlogin.ui\
	firstdialog.ui\
	helpwindow.ui\
	login.ui\
	loginhelp.ui\
	navigatingapp.ui\
	requestbrochure.ui\
	orderproduct.ui \
    BrochureWindow.ui \
    CustomerPlaceOrder.ui \
    ViewProducts.ui\
    find.ui \
    customeraccountwindow.ui \
    ImageViewer.ui \
    sellpoint.ui \
    guarantee.ui \
    guestwindow.ui \
    maintplan.ui \
    environments.ui \
    signupwindow.ui \
    contactus.ui \
    shoppingcartwindownew.ui\
    conceptofops.ui \
    testimonial.ui

RESOURCES += \
    Images.qrc \
    Database.qrc

OTHER_FILES += \
    ProductDatabase.txt\
    CustomerDatabase.txt


# QMAKE OUTPUTS
#       DO NOT REMOVE!!!!!!
#
 message($$QMAKESPEC)

# Mac OS Specific path
 macx{
        _PATH = "../../../../CS1C-Project-Master"
 }


 message(Qt version: $$[QT_VERSION])
 message(Qt is installed in $$[QT_INSTALL_PREFIX])
 message(Qt resources can be found in the following locations:)
 message(Documentation: $$[QT_INSTALL_DOCS])
 message(Header files: $$[QT_INSTALL_HEADERS])
 message(Libraries: $$[QT_INSTALL_LIBS])
 message(Binary files (executables): $$[QT_INSTALL_BINS])
 message(Plugins: $$[QT_INSTALL_PLUGINS])
 message(Data files: $$[QT_INSTALL_DATA])
 message(Translation files: $$[QT_INSTALL_TRANSLATIONS])
 message(Settings: $$[QT_INSTALL_SETTINGS])
 message(Examples: $$[QT_INSTALL_EXAMPLES])
 message(Demonstrations: $$[QT_INSTALL_DEMOS])
