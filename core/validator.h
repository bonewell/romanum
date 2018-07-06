#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>

/**
 * @startuml
 * Validator : + Validate(value : string) : bool
 * Validator ..> RomanNumber
 * RomanNumber : + Append(digit : char) : void
 * @enduml
 */
class Validator {
public:
    bool Validate(const std::string& value);
};

#endif // VALIDATOR_H
