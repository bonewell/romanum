#include "romannumber.h"

namespace {
  const std::string kDigits = "IVXLCDM";

  std::string SliceStrictly(char digit) {
      size_t pos = kDigits.find(digit);
      return kDigits.substr(0, pos);
  }

  std::string Slice(char digit) {
      size_t pos = kDigits.find(digit);
      return kDigits.substr(0, pos + 1);
  }

  char Shift10(char digit) {
      size_t pos = kDigits.find(digit);
      size_t len = kDigits.length();
      return kDigits[std::min(pos + 2, len - 1)];
  }

  char Before(char digit) {
      if (digit == -1) return -1;
      size_t pos = kDigits.find(digit);
      return pos == 0 ? -1 : kDigits[pos - 1];
  }

  char After(char digit) {
      size_t pos = kDigits.find(digit);
      size_t len = kDigits.length();
      return pos == len - 1 ? -1 : kDigits[pos + 1];
  }

  bool Is5(char digit) {
      size_t pos = kDigits.find(digit);
      return (pos + 1) % 2 == 0;
  }
}

RomanNumber::RomanNumber()
    : value_(),
      digits_(kDigits),
      preDigit_(0),
      prePreDigit_(0),
      currentDigit_(0)
{

}

void RomanNumber::Append(char digit)
{
    prePreDigit_ = preDigit_;
    preDigit_ = currentDigit_;
    currentDigit_ = digit;
    // TODO: check that digit is valid simbol
    digits_ = Update();
    value_ += digit;
}

const std::string& RomanNumber::AllowedDigits() const
{
    return digits_;
}

std::string RomanNumber::Update() {
    if (Is5(currentDigit_)) {
        return Update5();
    }
    return Update1();
}

std::string RomanNumber::Update5() const
{
    return SliceStrictly(preDigit_ == 0 ? currentDigit_ : preDigit_);
}

std::string RomanNumber::Update1() const
{
    if (currentDigit_ == preDigit_) {
        return (currentDigit_ == prePreDigit_) ? SliceStrictly(preDigit_) : Slice(preDigit_);
    }

    if (preDigit_ == Before(Before(currentDigit_)) || preDigit_ == After(currentDigit_))
        return SliceStrictly(preDigit_);

    return Slice(Shift10(currentDigit_));
}
