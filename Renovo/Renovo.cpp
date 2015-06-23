#include "Renovo.h"

#include <QMessageBox>

#include "CheckoutCalc.h"

Renovo::Renovo(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	InitailizeUI();
	ConnnectSignalsAndSlots();

}

Renovo::~Renovo()
{

}

void Renovo::InitailizeUI()
{

}

void Renovo::ConnnectSignalsAndSlots()
{
	connect(ui.Total_Button, SIGNAL(pressed()), this, SLOT(TotalButtonPressed()));
	connect(ui.Clear_Button, SIGNAL(pressed()), this, SLOT(ClearButtonPressed()));
}

void Renovo::TotalButtonPressed()
{
	QString SKUString = ui.SKU_LineEdit->text();
	QStringList SKUList = SKUString.split(',');

	QVariant price = 0.0f;

	try
	{
		CheckoutCalc priceCalc;
		price = priceCalc.price(SKUList);
	}
	catch (int e)
	{
		QMessageBox::critical(0, "Cannot open database",
			"Unable to establish a connection to the checkout database.\n"
			"Checkout aborted.", QMessageBox::Ok);
		return;
	}

	ui.PriceOutput_Edit->append(price.toString() + '\n');
	ui.SKU_LineEdit->clear();
}

void Renovo::ClearButtonPressed()
{

}
