#ifndef CHECKOUTCALC_H
#define CHECKOUTCALC_H

#include <QStringList>
#include <QMap>
#include <QSqlDatabase>

class CheckoutCalc
{
public:
	CheckoutCalc();
	~CheckoutCalc();

	float price(QStringList inputSKUs);

private:

	QMap<QString, int> m_SKUs;
	QSqlDatabase m_db;
};
#endif // CHECKOUTCALC_H

