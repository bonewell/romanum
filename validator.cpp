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
    const auto& digits = number_.AllowedDigits();
    return digits.find(digit) != digits.npos;
}
