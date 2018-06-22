#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "converter.h"

using namespace ::testing;

class ConverterTest: public Test
{
public:
    Converter converter;
};

TEST_F(ConverterTest, ConvertOneDigit) {
    ASSERT_THAT(converter.Convert("I"), Eq(1));
    ASSERT_THAT(converter.Convert("V"), Eq(5));
    ASSERT_THAT(converter.Convert("X"), Eq(10));
    ASSERT_THAT(converter.Convert("L"), Eq(50));
    ASSERT_THAT(converter.Convert("C"), Eq(100));
    ASSERT_THAT(converter.Convert("D"), Eq(500));
    ASSERT_THAT(converter.Convert("M"), Eq(1000));
}

TEST_F(ConverterTest, ConvertFewDigits) {
    ASSERT_THAT(converter.Convert("XVI"), Eq(16));
}

TEST_F(ConverterTest, MinusIfCurrentBiggerPrevious) {
    ASSERT_THAT(converter.Convert("XIV"), Eq(14));
    ASSERT_THAT(converter.Convert("MCMXCIX"), Eq(1999));
}
