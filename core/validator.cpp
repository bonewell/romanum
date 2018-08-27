#include "validator.h"

#include <iostream>
#include <stdexcept>

#include "romannumber.h"

bool Validator::Validate(const std::string& value) const
{
    if (value.empty()) return false;
    try {
        RomanNumber number;
        for (auto digit: value) number.Append(digit);
        return true;
    } catch (const std::invalid_argument&) {
        return false;
    }
}
