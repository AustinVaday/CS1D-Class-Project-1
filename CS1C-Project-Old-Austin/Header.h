#ifndef HEADER_H
#define HEADER_H
#include "customerlistclass.h"
#include <QFile>
#include <QTextStream>
#include <QLabel>
#include <QDebug>


void ReadCustomerFile(CustomerList& list, QString fileName = "/CustomerList.txt");

void WriteToCustomerFile(CustomerList&list, QString fileName);


#endif // HEADER_H
