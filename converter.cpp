#include "converter.h"

#include <unordered_map>

namespace {
    const std::unordered_map<char, short> digits = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    short Value(char digit) {
        return digits.at(digit);
    }
}

short Converter::Convert(const std::string& value)
{
    Reset();
    for (auto digit: value) {
        auto current = Value(digit);
        if (IsPreviousLess(current)) Amend();
        Add(current);
    }
    return Result();
}

void Converter::Reset()
{
    sum_ = 0;
    previous_ = 0;
}

void Converter::Add(short value)
{
    sum_ += value;
    previous_ = value;
}

short Converter::Result() const
{
    return sum_;
}

bool Converter::IsPreviousLess(short value) const
{
    return previous_ < value;
}

void Converter::Amend()
{
    sum_ = sum_ - (2 * previous_);
}
