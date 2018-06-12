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
}

RomanNumber::RomanNumber()
    : value_(),
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
}

std::string RomanNumber::AllowedDigits() const
{
    switch (currentDigit_) {
        case 'I': return UpdateForI();
        case 'V': return UpdateForV();
        case 'X': return UpdateForX();
        case 'L': return UpdateForL();
        case 'C': return UpdateForC();
        case 'D': return UpdateForD();
        case 'M': return UpdateForM();
        default: return kIVXLCDM;
    }
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

std::string RomanNumber::UpdateForV() const
{
    switch (preDigit_) {
        case 'I': return kNone;
        default: return kI;
    }
}

std::string RomanNumber::UpdateForX() const
{
    switch (preDigit_) {
        case 'I': return kNone;
        case 'X':
            if (prePreDigit_ == 'X')
                return kIV;
            else
                return kIVX;
        break;
        case 'L': return kIVX;
        default: return kIVXLC;
    }
}

std::string RomanNumber::UpdateForL() const
{
    switch (preDigit_) {
        case 'X': return kIV;
        default: return kIVX;
    }
}

std::string RomanNumber::UpdateForC() const
{
    switch (preDigit_) {
        case 'X': return kIV;
        case 'C':
            if (prePreDigit_ == 'C')
                return kIVXL;
            else
                return kIVXLC;
        break;
        case 'D': return kIVXLC;
        default: return kIVXLCDM;
    }
}

std::string RomanNumber::UpdateForD() const
{
    switch (preDigit_) {
        case 'C': return kIVXL;
        default: return kIVXLC;
    }
}

std::string RomanNumber::UpdateForM() const
{
    switch (preDigit_) {
        case 'C': return kIVXL;
        case 'M':
            if (prePreDigit_ == 'M')
                return kIVXLCD;
            else
                return kIVXLCDM;
        break;
        default: return kIVXLCDM;
    }
}
