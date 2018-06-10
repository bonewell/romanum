#include "validator.h"

namespace {
  const std::array<char, 7> kDigits{'I', 'V', 'X', 'L', 'C', 'D', 'M'};
  const std::array<char, 5> kIVXLC{'I', 'V', 'X', 'L', 'C'};
  const std::array<char, 3> kIVX{'I', 'V', 'X'};
  const std::array<char, 1> kI{'I'};
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
}

void Validator::UpdateForI() {
    switch (preDigit_) {
        case 'I': SetDigits(kI); break;
        default: SetDigits(kIVX);
    }
}

void Validator::Update(char currentDigit) {
    switch (currentDigit) {
        case 'I': UpdateForI(); break;
        case 'V':
        case 'L': SetDigits(kI); break;
        case 'X':
        case 'D': SetDigits(kIVXLC); break;
    }
    preDigit_ = currentDigit;
}

bool Validator::Check(char currentDigit) const {
    return std::any_of(std::begin(digits_), std::end(digits_),
                       [currentDigit](char item) {
                            return currentDigit == item;
    });
}
