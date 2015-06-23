#include "CheckoutCalc.h"
#include <QSqlQuery>
#include <QVariant>

CheckoutCalc::CheckoutCalc()
{
	m_db = QSqlDatabase::addDatabase("QSQLITE");
	m_db.setDatabaseName("CheckoutDB.sqlite");
	if (!m_db.open())
	{
		//TODO: Move Database error message back to here
		throw 0;
	}
}

CheckoutCalc::~CheckoutCalc()
{
	m_db.close();
}

float CheckoutCalc::price(QStringList inputSKUs)
{
	for (auto itr = inputSKUs.begin(); itr != inputSKUs.end(); ++itr)
	{
		m_SKUCounts.insert(*itr, m_SKUCounts.value(*itr, 0) + 1);
	}

	//////////////////////////////////////////////////////////////////////////

	float grandTotal = 0.0f;

	for(auto itr2 = m_SKUCounts.begin(); itr2 != m_SKUCounts.end(); ++itr2)
	{
		//TODO: Guard against SQL injection
		QSqlQuery query;
		query.exec("SELECT SKU.OfferAmount, SKU.Price, SKU.OfferPrice FROM SKU WHERE SKU.Item == \"" + itr2.key() + "\"");
		query.next();
		QVariant offerAmount = query.value(0);
		if (!offerAmount.isNull() && itr2.value() >= offerAmount.toInt())
		{
			int evenMult = itr2.value() / offerAmount.toFloat();
			int remainder = itr2.value() % offerAmount.toInt();

			float offerTotal = evenMult * query.value(2).toFloat();
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
