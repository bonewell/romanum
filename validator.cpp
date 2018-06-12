#include "validator.h"

bool Validator::Validate(const std::string& value)
{
    if (value.empty()) return false;
    Reset();
    for (auto digit: value) {
        if (!Check(digit)) return false;
        Update(digit);
    }
    return true;
}

void Validator::SetDigits(const std::string& digits)
{
    digits_.assign(std::begin(digits), std::end(digits));
}

void Validator::Reset()
{
    number_ = RomanNumber();
    SetDigits(number_.AllowedDigits());
}

void Validator::Update(char currentDigit)
{
    SetDigits(number_.AllowedDigits(currentDigit));
    number_.Append(currentDigit);
}

bool Validator::Check(char currentDigit) const
{
    return std::any_of(std::begin(digits_), std::end(digits_),
                       [currentDigit](char item) {
                            return currentDigit == item;
    });
}
