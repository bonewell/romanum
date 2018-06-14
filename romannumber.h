#ifndef ROMANNUMBER_H
#define ROMANNUMBER_H

#include <string>

class RomanNumber
{
public:
    RomanNumber();
    void Append(char digit);
    const std::string& AllowedDigits() const;

private:
    std::string Update();
    std::string Update1() const;
    std::string Update5() const;

    std::string value_;
    std::string digits_;
    char preDigit_;
    char prePreDigit_;
    char currentDigit_;
};

#endif // ROMANNUMBER_H
