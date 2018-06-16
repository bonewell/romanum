#include <iostream>

#include <romannumber.h>

int main() {
    char digit;
    RomanNumber number;
    const auto& allowed = number.AllowedDigits();
    while (!allowed.empty()) {
        std::cout << "Input roman digit (" + allowed + "): ";
        std::cin >> digit;
        number.Append(digit);
        std::cout << "Number: " << number << std::endl;
    }
    std::cout << "Finished\n";

    return 0;
}
