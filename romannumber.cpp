#include "romannumber.h"

#include <stdexcept>

namespace {
  const std::string kDigits = "IVXLCDM";

  void IsRoman(char digit) {
      if (kDigits.find(digit) == kDigits.npos)
          throw std::invalid_argument("Digit is not roman digit");
  }

  std::string SliceStrictly(char digit) {
      size_t pos = kDigits.find(digit);
      return kDigits.substr(0, pos);
  }

  std::string Slice(char digit) {
      size_t pos = kDigits.find(digit);
      return kDigits.substr(0, pos + 1);
  }

  char ShiftBack(char digit) {
      size_t pos = kDigits.find(digit);
      return pos == 0 ? kDigits.front() : kDigits[pos - 1];
  }

  char Shift(char digit) {
      size_t pos = kDigits.find(digit);
      size_t len = kDigits.length();
      return pos == len - 1 ? kDigits.back() : kDigits[pos + 1];
  }

  bool IsSingleUse(char digit) {
      size_t pos = kDigits.find(digit);
      return (pos + 1) % 2 == 0;
  }
}

RomanNumber::RomanNumber() : value_(), digits_(kDigits) {}

void RomanNumber::Append(char digit)
{
    IsRoman(digit);
    Concatenate(digit);
    UpdateAllowedDigits();
}

const std::string& RomanNumber::AllowedDigits() const
{
    return digits_;
}

void RomanNumber::Concatenate(char digit)
{
    value_ += digit;
}

void RomanNumber::UpdateAllowedDigits() {
    digits_ = IsSingleUse(Current()) ?
                GetAllowedForSingleUse() :
                GetAllowed();
}

std::string RomanNumber::GetAllowedForSingleUse() const
{
    return Previous() == ShiftBack(Current()) ?
                SliceStrictly(Previous()) :
                SliceStrictly(Current());
}

char RomanNumber::Current() const
{
    return *std::crbegin(value_);
}

char RomanNumber::Previous() const
{
    const int kOffset = 1;
    if (value_.length() > kOffset) {
        return *(std::crbegin(value_) + kOffset);
    }
    return 0;
}

char RomanNumber::BeforePrevious() const
{
    const int kOffset = 2;
    if (value_.length() > kOffset) {
        return *(std::crbegin(value_) + kOffset);
    }
    return 0;
}

bool RomanNumber::IsPreviousPresented() const
{
    return Previous() != 0;
}

bool RomanNumber::IsDouble() const
{
    return Current() == Previous() && Current() != BeforePrevious();
}

bool RomanNumber::IsTriple() const
{
    return Current() == Previous() && Current() == BeforePrevious();
}

std::string RomanNumber::GetAllowed() const
{
    if (IsDouble()) return Slice(Current());
    if (IsTriple()) return SliceStrictly(Current());
    if (Previous() == Shift(Current())) return Slice(Current());

    if (Previous() == ShiftBack(ShiftBack(Current())))
        return SliceStrictly(Previous());

    return Slice(Shift(Shift(Current())));
}

std::ostream& operator<<(std::ostream& out, const RomanNumber& number)
{
    return out << number.value_;
}
