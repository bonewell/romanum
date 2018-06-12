#include "validator.h"

#include <algorithm>

bool Validator::Validate(const std::string& value)
{
    if (value.empty()) return false;
    number_ = RomanNumber();
    for (auto digit: value) {
        if (!Check(digit)) return false;
        number_.Append(digit);
    }
    return true;
}

bool Validator::Check(char digit) const
{
    std::string digits = number_.AllowedDigits();
    return std::any_of(std::begin(digits), std::end(digits),
                       [digit](char item) {
                            return digit == item;
    });
}
