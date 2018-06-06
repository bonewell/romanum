#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <array>
#include <algorithm>

using namespace testing;

bool validate(const std::string& value) {
    const std::array<char, 7> kDigits{'I', 'V', 'X', 'L', 'C', 'D', 'M'};

    if (value.length() > 0) {
        return std::any_of(std::begin(kDigits), std::end(kDigits),
                           [&value](char item) { return value[0] == item; });
    }
    return false;
}

TEST(ValidatorTest, TheFirstDigitIsValid)
{
    ASSERT_TRUE(validate("I"));
    ASSERT_TRUE(validate("V"));
    ASSERT_TRUE(validate("X"));
    ASSERT_TRUE(validate("L"));
    ASSERT_TRUE(validate("C"));
    ASSERT_TRUE(validate("D"));
    ASSERT_TRUE(validate("M"));
}

TEST(ValidatorTest, EmptyValueIsInvalid) {
    ASSERT_FALSE(validate(""));
}
