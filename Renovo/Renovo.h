#ifndef RENOVO_H
#define RENOVO_H

#include <QtWidgets/QDialog>
#include "ui_Renovo.h"

class Renovo : public QDialog
{
	Q_OBJECT

public:
	Renovo(QWidget *parent = 0);
	~Renovo();

private:
	Ui::CheckoutUI ui;
};

#endif // RENOVO_H