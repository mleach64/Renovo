#include "Renovo.h"
#include "CheckoutCalc.h"
#include "AllCapRegExpValidator.h"

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
	QValidator *validator = new AllCapRegExpValidator(QRegExp("^[A-Z]+$"), this);
	ui.SKU_LineEdit->setValidator(validator);
}

void Renovo::ConnnectSignalsAndSlots()
{
	connect(ui.Total_Button, SIGNAL(pressed()), this, SLOT(TotalButtonPressed()));
	connect(ui.Clear_Button, SIGNAL(pressed()), this, SLOT(ClearButtonPressed()));
}

void Renovo::TotalButtonPressed()
{
	QString SKUString = ui.SKU_LineEdit->text();
	QStringList SKUList = SKUString.split("");

	QVariant price = 0.0f;

	try
	{
		CheckoutCalc priceCalc;
		price = priceCalc.Price(SKUList);
	}
	catch (int e)
	{
		//Database connection failed. BAIL!!!!
		return;
	}

	ui.PriceOutput_Edit->append(price.toString() + '\n');
	ui.SKU_LineEdit->clear();
}

void Renovo::ClearButtonPressed()
{
	ui.PriceOutput_Edit->clear();
}
