#ifndef ROMANNUMBER_H
#define ROMANNUMBER_H

#include <string>

/**
 * @startuml
 * class RomanNumber {
 *   - value_ : string
 *   - digits_ : string
 *   + RomanNumber()
 *   + Append(digit : char) : void
 *   + AllowedDigits() const : const string&
 *   + operator string() const
 *   - Concatenate(digit : char) : void
 *   - UpdateAllowedDigits() : void
 *   - GetAllowed() const : string
 *   - GetAllowedForSingleUse() const : string
 *   - Current() const : char
 *   - Previous() const : char
 *   - BeforePrevious() const : char
 *   - IsDouble() const : bool
 *   - IsTriple() const : bool
 *   - IsAllowed(digit : char) const : void
 * }
 * @enduml
 */
class RomanNumber
{
public:
    RomanNumber();
    void Append(char digit);
    const std::string& AllowedDigits() const;
    operator std::string() const;

private:
    void Concatenate(char digit);
    void UpdateAllowedDigits();
    std::string GetAllowed() const;
    std::string GetAllowedForSingleUse() const;

    char Current() const;
    char Previous() const;
    char BeforePrevious() const;

    bool IsDouble() const;
    bool IsTriple() const;
    void IsAllowed(char digit) const;

    std::string value_;
    std::string digits_;

    friend std::ostream& operator<<(std::ostream& out, const RomanNumber& number);
};

std::ostream& operator<<(std::ostream& out, const RomanNumber& number);

#endif // ROMANNUMBER_H
