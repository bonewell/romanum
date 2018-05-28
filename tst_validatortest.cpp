#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <array>

using namespace testing;

bool validate(const std::string& value) {
    const std::array<const char, 7> kDigits{'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    if (value.length() == 1) {
        return std::find(std::begin(kDigits), std::end(kDigits), value[0]) != std::end(kDigits);
    }
    return false;
}

TEST(ValidatorTest, IsValidDigit)
{
    ASSERT_TRUE(validate("I"));
    ASSERT_TRUE(validate("V"));
    ASSERT_TRUE(validate("X"));
    ASSERT_TRUE(validate("L"));
    ASSERT_TRUE(validate("C"));
    ASSERT_TRUE(validate("D"));
    ASSERT_TRUE(validate("M"));
}

TEST(ValidatorTest, IsValidAllDigits) {
    ASSERT_TRUE(validate("CIX"));
}
