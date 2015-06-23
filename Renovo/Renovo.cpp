#include "Renovo.h"
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
	ui.SKU_LineEdit->clear();

	QStringList SKUList = SKUString.split(',');

	CheckoutCalc priceCalc;
	QVariant price = priceCalc.price(SKUList);

	ui.PriceOutput_Edit->append(price.toString() + '\n');
}

void Renovo::ClearButtonPressed()
{

}
