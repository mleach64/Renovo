#ifndef ALLCAPREGEXPVALIDATOR_H
#define ALLCAPREGEXPVALIDATOR_H

#include <QRegExpValidator>

// Custom Validator to convert text to ALL CAPS before validating again RegExp
class AllCapRegExpValidator : public QRegExpValidator
{
	Q_OBJECT

public:
	//************************************
	// Method:    AllCapRegExpValidator
	// FullName:  AllCapRegExpValidator::AllCapRegExpValidator
	// Access:    public 
	// Desc:	  Basic Constructor
	// Parameter: QObject * parent - The parent class
	//************************************
	AllCapRegExpValidator(QObject *parent);

	//************************************
	// Method:    AllCapRegExpValidator
	// FullName:  AllCapRegExpValidator::AllCapRegExpValidator
	// Access:    public 
	// Desc:	  Constructor that takes a RegExp
	// Parameter: const QRegExp & rx - RegExp to use for validation
	// Parameter: QObject * parent - The parent class
	//************************************
	AllCapRegExpValidator(const QRegExp &rx, QObject *parent = NULL);

	//************************************
	// Method:    ~AllCapRegExpValidator
	// FullName:  AllCapRegExpValidator::~AllCapRegExpValidator
	// Access:    public 
	// Desc:	  Basic Destructor
	//************************************
	~AllCapRegExpValidator();

	//************************************
	// Method:    validate
	// FullName:  AllCapRegExpValidator::validate
	// Access:    public 
	// Returns:   QValidator::State
	// Qualifier: const
	// Desc:	  Convert to ALL CAPS and validate against RegExp
	// Parameter: QString & input - the string to validate
	// Parameter: int & pos the length of the input string
	//************************************
	QValidator::State validate(QString & input, int & pos) const;
	
};

#endif // ALLCAPREGEXPVALIDATOR_H
