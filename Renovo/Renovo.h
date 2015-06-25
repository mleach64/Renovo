#ifndef RENOVO_H
#define RENOVO_H

#include <QtWidgets/QDialog>
#include "ui_Renovo.h"

// The main application class
class Renovo : public QDialog
{
	Q_OBJECT

public:
	//************************************
	// Method:    Renovo
	// FullName:  Renovo::Renovo
	// Access:    public 
	// Desc:	  Basic Constructor
	// Parameter: QWidget * parent
	//************************************
	Renovo(QWidget *parent = 0);

	//************************************
	// Method:    ~Renovo
	// FullName:  Renovo::~Renovo
	// Access:    public 
	// Desc:	  Basic Destructor
	//************************************
	~Renovo();

private:
	//************************************
	// Method:    InitailizeUI
	// FullName:  Renovo::InitailizeUI
	// Access:    public 
	// Returns:   void
	// Desc:	  Initialize UI elements
	//************************************
	void InitailizeUI();

	//************************************
	// Method:    ConnnectSignalsAndSlots
	// FullName:  Renovo::ConnnectSignalsAndSlots
	// Access:    public 
	// Returns:   void
	// Desc:	  Connect all Signals and Slots
	//************************************
	void ConnnectSignalsAndSlots();

private:
	Ui::CheckoutUI ui;  //The main UI object

private slots:

	//************************************
	// Method:    TotalButtonPressed
	// FullName:  Renovo::TotalButtonPressed
	// Access:    private 
	// Returns:   void
	// Desc:	  Handle when the Total button is pressed
	//************************************
	void TotalButtonPressed();

	//************************************
	// Method:    ClearButtonPressed
	// FullName:  Renovo::ClearButtonPressed
	// Access:    private 
	// Returns:   void
	// Desc:	  Handle when the Clear button is pressed
	//************************************
	void ClearButtonPressed();
};

#endif // RENOVO_H