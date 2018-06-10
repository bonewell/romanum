#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <array>
#include <algorithm>
#include <vector>

class Validator {
public:
    bool Validate(const std::string& value);

private:
    std::vector<char> digits_;
    char preDigit_;

    template<size_t N>
    void SetDigits(const std::array<char, N>& digits);
    void Reset();
    void Update(char currentDigit);
    void UpdateForI();
    bool Check(char currentDigit) const;
};

#endif // VALIDATOR_H
