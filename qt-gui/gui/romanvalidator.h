#ifndef ROMANVALIDATOR_H
#define ROMANVALIDATOR_H

#include <QValidator>

#include "core/validator.h"

class RomanValidator : public QValidator
{
    Q_OBJECT
public:
    explicit RomanValidator(QObject *parent = nullptr);
    State validate(QString& input, int& pos) const override;
private:
    Validator validator_;
};

#endif // ROMANVALIDATOR_H
