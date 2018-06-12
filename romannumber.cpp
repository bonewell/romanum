#include "romannumber.h"

namespace {
  const std::string kIVXLCDM = "IVXLCDM";
  const std::string kIVXLCD = "IVXLCD";
  const std::string kIVXLC = "IVXLC";
  const std::string kIVXL = "IVXL";
  const std::string kIVX = "IVX";
  const std::string kIV = "IV";
  const std::string kI = "I";
  const std::string kNone = "";

  std::string Slice(char digit) {
      size_t pos = kIVXLCDM.find(digit);
      // throw exception: digit is not supported if pos == npos
      return kIVXLCDM.substr(0, pos);
  }
}

RomanNumber::RomanNumber()
    : value_(),
      digits_(kIVXLCDM),
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
    digits_ = Update();
}

const std::string& RomanNumber::AllowedDigits() const
{
    return digits_;
}

std::string RomanNumber::Update() {
    switch (currentDigit_) {
        case 'I': return UpdateForI();
        case 'X': return UpdateForX();
        case 'C': return UpdateForC();
        case 'M': return UpdateForM();
        case 'V':
        case 'L':
        case 'D': return Update5();
        default: return kIVXLCDM;
    }
}

std::string RomanNumber::Update5() const
{
    return Slice(preDigit_ == 0 ? currentDigit_ : preDigit_);
}

std::string RomanNumber::UpdateForI() const {
    switch (preDigit_) {
        case 'I':
        case 'V': return (prePreDigit_ == 'I') ? kNone : kI;
        default: return kIVX;
    }
}

std::string RomanNumber::UpdateForX() const
{
    switch (preDigit_) {
        case 'I': return kNone;
        case 'X': return (prePreDigit_ == 'X') ? kIV : kIVX;
        case 'L': return kIVX;
        default: return kIVXLC;
    }
}

std::string RomanNumber::UpdateForC() const
{
    switch (preDigit_) {
        case 'X': return kIV;
        case 'C': return (prePreDigit_ == 'C') ? kIVXL : kIVXLC;
        case 'D': return kIVXLC;
        default: return kIVXLCDM;
    }
}

std::string RomanNumber::UpdateForM() const
{
    switch (preDigit_) {
        case 'C': return kIVXL;
        case 'M': return (prePreDigit_ == 'M') ? kIVXLCD : kIVXLCDM;
        default: return kIVXLCDM;
    }
}
