#ifndef ROMANCONVERTER_H
#define ROMANCONVERTER_H

#include <QObject>

#include "core/converter.h"

class RomanConverter : public QObject
{
    Q_OBJECT
public:
    explicit RomanConverter(QObject *parent = nullptr);
    Q_INVOKABLE short convert(const QString& input);
private:
    Converter converter_;
};

#endif // ROMANCONVERTER_H
