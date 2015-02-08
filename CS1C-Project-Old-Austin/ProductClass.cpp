/**************************************************************************
 * CS1C Class Project
 * -----------------------------------------------------------------------
 * Product Class Test
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

#include "ProductClass.h"
#include <QString>
#include <QTextStream>

// Default constructor
Product::Product()
{
    cost 					= 0;
    productName				= " ";
    productDescription		= " ";
    modelNumber				= 0;
    dateReleased			= 0;
}

Product::Product(QString initName,		// Starting name of product
                 QString description,	// Description of the product
                 float  initCost,		// Starting cost of product
                 int 	modelNum,
                 int	initReleaseDate)
{
    cost                = initCost;
    productName         = initName;
    productDescription  = description;
    modelNumber         = modelNum;
    dateReleased        = initReleaseDate;

}


Product::~Product()
{
    // PLACE HOLDER FOR OUTPUTTING THE SPECIFICATIONS LIST OF EACH
    //	PRODUCT
}
void Product::changeCost(float newCost)
{
    cost = newCost;
}

void Product::changeName(QString newName)
{
    productName = newName;
}

void Product::changeDescription(QString description)
{
    productDescription = description;
}

float Product::getCost() const
{
    return cost;
}

QString  Product::getName() const
{
    return productName;
}

QString  Product::getDescription() const
{
    return productDescription;
}

int  Product::getModelNumber() const
{
    return modelNumber;
}

int  Product::getReleaseDate() const
{
    return dateReleased;
}

// Overloading the equality operator **FOR SIMILARITY**
bool Product::operator &=(const Product otherProduct)
{
    bool same;

    same = false;

    // Compares names and account numbers, if either are the same it will
    //	throw a flag. We could compare objects completely but we don't want
    //	to throw a flag on a person who has the exact same password by
    //	some crazy chance.
    //

    if(	  otherProduct.getModelNumber() == this->getModelNumber()
       || otherProduct.getName() 	== this->getName())
    {
        same = true;
    }

    return same;
}

// Overloading the equality operator **FOR ABSOLUTE EQUALITY**
bool Product::operator ==(const Product otherProduct)
{
    bool same;

    same = false;

    // Compares names and account numbers, if either are the same it will
    //	throw a flag. We could compare objects completely but we don't want
    //	to throw a flag on a person who has the exact same password by
    //	some crazy chance.
    //

    if(	  otherProduct.getModelNumber() == this->getModelNumber()
       && otherProduct.getName() 	== this->getName()
       && otherProduct.getReleaseDate() == this->getReleaseDate()
       && otherProduct.getCost()   == this->getCost())
    {
        same = true;
    }

    return same;
}

QString  Product::OutputData() const
{
    QString str;

    QTextStream out(&str);
    out << "........................................................\n";
    out << "Product Name: " <<  productName << endl;
    out << "Description: " << productDescription  << endl;
    out << "Model Number: " <<  modelNumber << endl;
    out << "Cost: $" << cost << endl;
    out << "Date of Release: " << dateReleased << endl;
    out << "........................................................\n";

    return str;
}
