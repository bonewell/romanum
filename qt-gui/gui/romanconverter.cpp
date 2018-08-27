#include "romanconverter.h"

RomanConverter::RomanConverter(QObject *parent) : QObject(parent)
{
}

short RomanConverter::convert(const QString &input)
{
    return converter_.Convert(input.toStdString());
}
