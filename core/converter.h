#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>

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
