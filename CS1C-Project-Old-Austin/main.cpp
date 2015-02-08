#include "MainProgramWindow.h"
#include <QApplication>
#include <QString>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

int main(int argc, char *argv[])
{
	// DECLARATIONS BEFORE APPLICATION STARTS
	QApplication a(argc, argv);
	QDir	directory = QDir::current();
	bool	directoryMade;

	directoryMade = false;

	while(directory.dirName() != "Class-Project")
	{
		directory.cdUp();
qDebug() << "Currently in - " << directory.dirName();
	}

	if(!directory.cd("Database-Files"))
	{
		directory.mkpath("Database-Files");



		directory.cd("Database-Files");
	}


	QFile::copy(":/CustomerDatabase.txt",(directory.path() +  "/CustomerList.txt"));


	QFile::copy(":/ProductDatabase.txt",(directory.path() +  "/ProductList.txt"));


	// MAIN WINDOW HAS TO STAY DOWN HERE OR IT WILL TRY TO INITIALIZE BEFORE
	//	CHECKING FOR DIRECTORY
	MainProgramWindow MainProgramWindow;
	// DISPLAYS MAIN WINDOW
    MainProgramWindow.show();

    return a.exec();
}
