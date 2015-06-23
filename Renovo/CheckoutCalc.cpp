#include "CheckoutCalc.h"

CheckoutCalc::CheckoutCalc()
{
	m_db = QSqlDatabase::addDatabase("QSQLITE");
	m_db.setDatabaseName("CheckoutDB");
	if (!m_db.open())
	{
		throw 0;
	}
}


CheckoutCalc::~CheckoutCalc()
{
	m_db.close();
}

float CheckoutCalc::price(QStringList inputSKUs)
{
	for (QStringList::iterator itr = inputSKUs.begin(); itr != inputSKUs.end(); ++itr)
	{
		this->m_SKUs.insert(*itr, this->m_SKUs.value(*itr, 0) + 1);
	}

	return 0.0f;
}
