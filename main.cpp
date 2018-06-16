#include <iostream>

#include <romannumber.h>
#include <validator.h>

int main(int argc, char* args[]) {
    if (argc > 1) {
        bool res = Validator().Validate(args[1]);
        std::cout << "Roman number is " << std::boolalpha << res << std::endl;
        return 0;
    }

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
