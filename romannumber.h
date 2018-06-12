#ifndef ROMANNUMBER_H
#define ROMANNUMBER_H

#include <string>

class RomanNumber
{
public:
    RomanNumber();
    void Append(char digit);
    std::string AllowedDigits() const;

private:
    std::string UpdateForI() const;
    std::string UpdateForV() const;
    std::string UpdateForX() const;
    std::string UpdateForL() const;
    std::string UpdateForC() const;
    std::string UpdateForD() const;
    std::string UpdateForM() const;

    std::string value_;
    char preDigit_;
    char prePreDigit_;
    char currentDigit_;
};

#endif // ROMANNUMBER_H
