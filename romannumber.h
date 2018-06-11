#ifndef ROMANNUMBER_H
#define ROMANNUMBER_H

#include <string>

class RomanNumber
{
public:
    RomanNumber();
    void Append(char digit);
    std::string AllowedDigits() const;
    char preDigit() const {
        return preDigit_;
    }
    char prePreDigit() const {
        return prePreDigit_;
    }

private:
    std::string UpdateForI() const;

    std::string value_;
    char preDigit_;
    char prePreDigit_;
};

#endif // ROMANNUMBER_H
