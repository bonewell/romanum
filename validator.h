#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "romannumber.h"

class Validator {
public:
    bool Validate(const std::string& value);

private:
    bool Check(char digit) const;

    RomanNumber number_;
};

#endif // VALIDATOR_H
