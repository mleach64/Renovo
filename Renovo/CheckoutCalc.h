#ifndef CHECKOUTCALC_H
#define CHECKOUTCALC_H

#include <QStringList>
#include <QMap>
#include <QSqlDatabase>

// Class to handle Price calculation
class CheckoutCalc
{
public:
	//************************************
	// Method:    CheckoutCalc
	// FullName:  CheckoutCalc::CheckoutCalc
	// Access:    public 
	// Desc:	  Basic Constructor
	//************************************
	CheckoutCalc();

	//************************************
	// Method:    ~CheckoutCalc
	// FullName:  CheckoutCalc::~CheckoutCalc
	// Access:    public 
	// Desc:	  Basic Destructor
	//************************************
	~CheckoutCalc();

	//************************************
	// Method:    price
	// FullName:  CheckoutCalc::price
	// Access:    public 
	// Returns:   float - The total price of all SKUs
	// Desc:	  Calculates the total price of all SKUs
	// Parameter: QStringList inputSKUs - The list of SKUs inputted by the user.
	//************************************
	float Price(QStringList inputSKUs);

private:

	QMap<QString, int> m_SKUCounts; // The number of each SKU
	QSqlDatabase m_db;				// The Checkout Database
};
#endif // CHECKOUTCALC_H

