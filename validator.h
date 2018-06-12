#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <array>
#include <algorithm>
#include <vector>

#include "romannumber.h"

class RomanNumber;

class Validator {
public:
    bool Validate(const std::string& value);

private:
    void SetDigits(const std::string& digits);
    void Reset();
    void Update(char currentDigit);
    bool Check(char currentDigit) const;

    RomanNumber number_;
    std::vector<char> digits_;
};

#endif // VALIDATOR_H
