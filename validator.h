#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <array>
#include <algorithm>
#include <vector>

#include "romannumber.h"

class RomanNumber;

class Validator {
public:
    bool Validate(const std::string& value);

private:
    RomanNumber number_;
    std::vector<char> digits_;

    template<size_t N>
    void SetDigits(const std::array<char, N>& digits);
    void SetDigits(const std::string& digits);
    void Reset();
    void Update(char currentDigit);
    void UpdateForX();
    void UpdateForL();
    void UpdateForC();
    void UpdateForD();
    void UpdateForM();
    bool Check(char currentDigit) const;
};

#endif // VALIDATOR_H
