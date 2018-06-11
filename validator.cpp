#include "validator.h"

namespace {
  const std::array<char, 7> kDigits{'I', 'V', 'X', 'L', 'C', 'D', 'M'};
  const std::array<char, 5> kIVXLC{'I', 'V', 'X', 'L', 'C'};
  const std::array<char, 3> kIVX{'I', 'V', 'X'};
  const std::array<char, 2> kIV{'I', 'V'};
  const std::array<char, 1> kI{'I'};
  const std::array<char, 0> kNone;
}

bool Validator::Validate(const std::string& value) {
    if (value.empty()) return false;
    Reset();
    for (auto digit: value) {
        if (!Check(digit)) return false;
        Update(digit);
    }
    return true;
}

template<size_t N>
void Validator::SetDigits(const std::array<char, N> &digits)
{
    digits_.assign(std::begin(digits), std::end(digits));
}

void Validator::Reset() {
    SetDigits(kDigits);
    preDigit_ = 0;
    prePreDigit_ = 0;
}

void Validator::UpdateForI() {
    switch (preDigit_) {
        case 'I':
        case 'V':
            if (prePreDigit_ == 'I')
                SetDigits(kNone);
            else
                SetDigits(kI);
        break;
        default: SetDigits(kIVX);
    }
}

void Validator::UpdateForV() {
    switch (preDigit_) {
        case 'I': SetDigits(kNone); break;
        default: SetDigits(kI);
    }
}

void Validator::UpdateForX() {
    switch (preDigit_) {
        case 'I': SetDigits(kNone); break;
        case 'X':
            if (prePreDigit_ == 'X')
                SetDigits(kIV);
            else
                SetDigits(kIVX);
        break;
        default: SetDigits(kIVXLC);
    }
}

void Validator::UpdateForL()
{
    switch (preDigit_) {
        case 'X': SetDigits(kIV); break;
        default: SetDigits(kIVX);
    }
}

void Validator::Update(char currentDigit) {
    switch (currentDigit) {
        case 'I': UpdateForI(); break;
        case 'V': UpdateForV(); break;
        case 'X': UpdateForX(); break;
        case 'L': UpdateForL(); break;
        case 'D': SetDigits(kIVXLC); break;
    }
    prePreDigit_ = preDigit_;
    preDigit_ = currentDigit;
}

bool Validator::Check(char currentDigit) const {
    return std::any_of(std::begin(digits_), std::end(digits_),
                       [currentDigit](char item) {
                            return currentDigit == item;
    });
}
