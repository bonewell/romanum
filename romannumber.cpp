#include "romannumber.h"

namespace {
  const std::string kIVXLCDM = "IVXLCDM";
  const std::string kIVXLCD = "IVXLCD";
  const std::string kIVXLC = "IVXLC";
  const std::string kIVXL = "IVXL";
  const std::string kIVX = "IVX";
  const std::string kIV = "IV";
  const std::string kI = "I";
  const std::string kNone;
}

RomanNumber::RomanNumber()
    : value_(),
      preDigit_(0),
      prePreDigit_(0)
{

}

void RomanNumber::Append(char digit)
{
    prePreDigit_ = preDigit_;
    preDigit_ = digit;
}

std::string RomanNumber::AllowedDigits() const
{
    return UpdateForI();
}

std::string RomanNumber::UpdateForI() const {
    switch (preDigit_) {
        case 'I':
        case 'V':
            if (prePreDigit_ == 'I')
                return kNone;
            else
                return kI;
        break;
        default: return kIVX;
    }
}
