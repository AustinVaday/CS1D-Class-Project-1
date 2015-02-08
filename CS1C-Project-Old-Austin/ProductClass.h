/**************************************************************************
 * CS1C Class Project
 * -----------------------------------------------------------------------
 * Product Class Header
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


#ifndef PRODUCTCLASS_H_
#define PRODUCTCLASS_H_
#include <QString>
#include "userclass.h"

/**************************************************************************
 * Product Class
 * -----------------------------------------------------------------------
 * Product class will be used to store data of each current product that is
 * 	available for sale by Extreme Robot Cat Coderz. The class will
 *
 *************************************************************************/
class Product  : public User
{
    public:
        Product();
        // Default Constructor

        Product(QString initName,			// Starting name of product
                QString description,        // Description of the product
                float  	initCost,			// Starting cost of product
                int		modelNum,           // Model Number of the product
                int		initReleaseDate);	// The date the product was released

        // Non-default Constructor
        //	Pass in: Cost, name, description and the specifications

        ~Product();
        // Deconstructor

        /*****************************************************************
         * Mutators
         ****************************************************************/

        void changeCost(float  newCost);
        // Changes cost of the product
        //	Passes in a new float value of product and modifies the
        //	cost member of the class.
        // Returns: Nothing

        void changeName(QString newName);
        // Changes the name of the product.
        //	Passes in a new string to replace the productName string
        //	value of the class.
        // Returns: Nothing

        void changeDescription(QString description);
        // Changes the description of the product
        //	Passes in a new string to replace the productDescription
        //	string value of the class.
        // Returns: Nothing

        /*****************************************************************
         * Accessors
         ****************************************************************/
        float getCost() const;
        // Returns the cost of the product

        QString getName() const;
        // Returns the name of the product

        QString getDescription() const;
        // Returns the description of the product

        int getReleaseDate() const;
        // Returns date the product was released

        int getModelNumber() const;
        // Returns the model number of the product

        bool operator &=(const Product otherProduct);

        bool operator ==(const Product otherProduct);

        QString OutputData() const;

        //void

    private:
        // Data members
        float		 cost;					// Cost of the product
        QString  	 productName;			// Name of the product
        QString		 productDescription;	// Description of the product
        int			 modelNumber;			// Model number of the product
        int			 dateReleased;			// Stores the date the product
                                            //	was released
};


#endif /* PRODUCTCLASS_H_ */


