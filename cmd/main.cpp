#include <iostream>

#include <romannumber.h>
#include <validator.h>
#include <converter.h>

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
        short value = Converter().Convert(number);
        std::cout << "Number: " << number;
        std::cout << "(" << value << ")\n";
    }
    std::cout << "Finished\n";

    return 0;
}
