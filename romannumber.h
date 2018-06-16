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
    void Concatenate(char digit);
    void UpdateAllowedDigits();
    std::string GetAllowed() const;
    std::string GetAllowedForSingleUse() const;

    char Current() const;
    char Previous() const;
    char BeforePrevious() const;

    bool IsPreviousPresented() const;
    bool IsDouble() const;
    bool IsTriple() const;

    std::string value_;
    std::string digits_;

    friend std::ostream& operator<<(std::ostream& out, const RomanNumber& number);
};

std::ostream& operator<<(std::ostream& out, const RomanNumber& number);

#endif // ROMANNUMBER_H
