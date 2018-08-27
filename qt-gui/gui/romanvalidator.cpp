#include "romanvalidator.h"

RomanValidator::RomanValidator(QObject *parent) : QValidator(parent)
{
}

QValidator::State RomanValidator::validate(QString & input, int & pos) const
{
    if (pos == 0) return Intermediate;
    if (validator_.Validate(input.toStdString())) {
        return Acceptable;
    } else {
        return Invalid;
    }
}
