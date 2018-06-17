#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <unordered_map>

using namespace ::testing;

short Convert(const std::string& value)
{
    const std::unordered_map<char, short> digits = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    short sum = 0;
    for (auto digit: value) {
        sum += digits.at(digit);
    }
    return sum;
}

TEST(ConverterTest, ConvertOneDigit) {
    ASSERT_THAT(Convert("I"), Eq(1));
    ASSERT_THAT(Convert("V"), Eq(5));
    ASSERT_THAT(Convert("X"), Eq(10));
    ASSERT_THAT(Convert("L"), Eq(50));
    ASSERT_THAT(Convert("C"), Eq(100));
    ASSERT_THAT(Convert("D"), Eq(500));
    ASSERT_THAT(Convert("M"), Eq(1000));
}

TEST(ConverterTest, ConvertFewDigits) {
    ASSERT_THAT(Convert("XVI"), 16);
}
