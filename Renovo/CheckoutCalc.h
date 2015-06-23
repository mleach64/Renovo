#ifndef CHECKOUTCALC_H
#define CHECKOUTCALC_H

#include <QStringList>

class CheckoutCalc
{
public:
	CheckoutCalc();
	~CheckoutCalc();

	float price(QStringList SKUs);
};
#endif // CHECKOUTCALC_H

