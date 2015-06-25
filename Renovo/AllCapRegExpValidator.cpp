#include "AllCapRegExpValidator.h"

AllCapRegExpValidator::AllCapRegExpValidator(QObject *parent)
	: QRegExpValidator(parent)
{

}

AllCapRegExpValidator::AllCapRegExpValidator(const QRegExp &rx, QObject *parent /*= NULL*/)
	: QRegExpValidator(rx, parent)
{

}

AllCapRegExpValidator::~AllCapRegExpValidator()
{

}

QValidator::State AllCapRegExpValidator::validate(QString & input, int & pos) const
{
	input = input.toUpper();
	return QRegExpValidator::validate(input, pos);
}
