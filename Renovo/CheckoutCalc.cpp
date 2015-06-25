#include "CheckoutCalc.h"
#include <QSqlQuery>
#include <QVariant>
#include <QMessageBox>

CheckoutCalc::CheckoutCalc()
{
	m_db = QSqlDatabase::addDatabase("QSQLITE");
	m_db.setDatabaseName("CheckoutDB.sqlite");
	if (!m_db.open())
	{
		QMessageBox::critical(0, "Cannot open database",
			"Unable to establish a connection to the checkout database.\n"
			"Checkout aborted.", QMessageBox::Ok);
		throw 0;
	}
}

CheckoutCalc::~CheckoutCalc()
{
	m_db.close();
}

float CheckoutCalc::Price(QStringList inputSKUs)
{
	//Total up the number of each SKU
	for (auto itr = inputSKUs.begin(); itr != inputSKUs.end(); ++itr)
	{
		m_SKUCounts.insert(*itr, m_SKUCounts.value(*itr, 0) + 1);
	}

	//////////////////////////////////////////////////////////////////////////

	float grandTotal = 0.0f;

	//Determine the price for each group of SKUs and add it to the grand total
	for(auto itr2 = m_SKUCounts.begin(); itr2 != m_SKUCounts.end(); ++itr2)
	{
		//get price info for the current SKU from DB
		QSqlQuery query;
		query.exec("SELECT SKU.OfferAmount, SKU.Price, SKU.OfferPrice FROM SKU WHERE SKU.Item == \"" + itr2.key() + "\"");
		query.next();
		QVariant offerAmount = query.value(0);
		if (!offerAmount.isNull() && itr2.value() >= offerAmount.toInt())
		{
			int evenQuotient = itr2.value() / offerAmount.toFloat();
			int remainder = itr2.value() % offerAmount.toInt();

			float offerTotal = evenQuotient * query.value(2).toFloat();
			float remainderTotal = remainder * query.value(1).toFloat();

			grandTotal += (offerTotal + remainderTotal);
		}
		else
		{
			grandTotal += (itr2.value() * query.value(1).toFloat());
		}
	}

	//////////////////////////////////////////////////////////////////////////

	return grandTotal;
}
