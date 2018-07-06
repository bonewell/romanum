#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>

/**
* @startuml
* class RomanNumber {
*   - sum_ : short
*   - previous_ : short
*   + Append(digit : char) : void
*   - Reset() : void
*   - Add(value : short) : void
*   - Result() const : short
*   - IsPreviousLess(value : short) const : bool
*   - Amend() : void
* }
* @enduml
 */
class Converter
{
public:
    short Convert(const std::string& value);

private:
    void Reset();
    void Add(short value);
    short Result() const;
    bool IsPreviousLess(short value) const;
    void Amend();

    short sum_;
    short previous_;
};

#endif // CONVERTER_H
