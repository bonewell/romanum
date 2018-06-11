#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "validator.h"

using namespace testing;

class ValidatorTest : public Test {
public:
    Validator validator;
};

TEST_F(ValidatorTest, TheFirstDigitIsValid)
{
    ASSERT_TRUE(validator.Validate("I"));
    ASSERT_TRUE(validator.Validate("V"));
    ASSERT_TRUE(validator.Validate("X"));
    ASSERT_TRUE(validator.Validate("L"));
    ASSERT_TRUE(validator.Validate("C"));
    ASSERT_TRUE(validator.Validate("D"));
    ASSERT_TRUE(validator.Validate("M"));
}

TEST_F(ValidatorTest, TheEmptyValueIsInvalid) {
    ASSERT_FALSE(validator.Validate(""));
}

TEST_F(ValidatorTest, ANumberWithInvalidDigitIsInvalid) {
    ASSERT_FALSE(validator.Validate("MDCKI"));
}

TEST_F(ValidatorTest, ADigitAfterIShouldNotBeLCDOrM) {
    ASSERT_FALSE(validator.Validate("IL"));
    ASSERT_FALSE(validator.Validate("IC"));
    ASSERT_FALSE(validator.Validate("ID"));
    ASSERT_FALSE(validator.Validate("IM"));
}

TEST_F(ValidatorTest, ADigitAfterVShouldNotBeVXLCDOrM) {
    ASSERT_FALSE(validator.Validate("VV"));
    ASSERT_FALSE(validator.Validate("VX"));
    ASSERT_FALSE(validator.Validate("VL"));
    ASSERT_FALSE(validator.Validate("VC"));
    ASSERT_FALSE(validator.Validate("VD"));
    ASSERT_FALSE(validator.Validate("VM"));
}

TEST_F(ValidatorTest, ADigitAfterXShouldNotBeDM) {
    ASSERT_FALSE(validator.Validate("XD"));
    ASSERT_FALSE(validator.Validate("XM"));
}

TEST_F(ValidatorTest, ADigitAfterLShouldNotBeLCDOrM) {
    ASSERT_FALSE(validator.Validate("LL"));
    ASSERT_FALSE(validator.Validate("LC"));
    ASSERT_FALSE(validator.Validate("LD"));
    ASSERT_FALSE(validator.Validate("LM"));
}

TEST_F(ValidatorTest, ADigitAfterCMayBeAny) {
    ASSERT_TRUE(validator.Validate("CI"));
    ASSERT_TRUE(validator.Validate("CV"));
    ASSERT_TRUE(validator.Validate("CX"));
    ASSERT_TRUE(validator.Validate("CL"));
    ASSERT_TRUE(validator.Validate("CC"));
    ASSERT_TRUE(validator.Validate("CD"));
    ASSERT_TRUE(validator.Validate("CM"));
}

TEST_F(ValidatorTest, ADigitAfterDShouldNotBeDOrM) {
    ASSERT_FALSE(validator.Validate("DD"));
    ASSERT_FALSE(validator.Validate("DM"));
}

TEST_F(ValidatorTest, ADigitAfterMMayBeAny) {
    ASSERT_TRUE(validator.Validate("MI"));
    ASSERT_TRUE(validator.Validate("MV"));
    ASSERT_TRUE(validator.Validate("MX"));
    ASSERT_TRUE(validator.Validate("ML"));
    ASSERT_TRUE(validator.Validate("MC"));
    ASSERT_TRUE(validator.Validate("MD"));
    ASSERT_TRUE(validator.Validate("MM"));
}

TEST_F(ValidatorTest, ADigitAfterIIShouldNotBeVOrX) {
    ASSERT_FALSE(validator.Validate("IIV"));
    ASSERT_FALSE(validator.Validate("IIX"));
}

TEST_F(ValidatorTest, NoDigitsAfterIII) {
    ASSERT_FALSE(validator.Validate("IIII"));
}

TEST_F(ValidatorTest, NoDigitAfterIV) {
    ASSERT_FALSE(validator.Validate("IVI"));
}

TEST_F(ValidatorTest, ADigitAfterVIShouldNotBeVOrX) {
    ASSERT_FALSE(validator.Validate("VIV"));
    ASSERT_FALSE(validator.Validate("VIX"));
}

TEST_F(ValidatorTest, NoDigitAfterIX) {
    ASSERT_FALSE(validator.Validate("IXI"));
}

TEST_F(ValidatorTest, NumbersFromIToXXAreValid) {
    ASSERT_TRUE(validator.Validate("I"));
    ASSERT_TRUE(validator.Validate("II"));
    ASSERT_TRUE(validator.Validate("III"));
    ASSERT_TRUE(validator.Validate("IV"));
    ASSERT_TRUE(validator.Validate("V"));
    ASSERT_TRUE(validator.Validate("VI"));
    ASSERT_TRUE(validator.Validate("VII"));
    ASSERT_TRUE(validator.Validate("VIII"));
    ASSERT_TRUE(validator.Validate("IX"));
    ASSERT_TRUE(validator.Validate("X"));
    ASSERT_TRUE(validator.Validate("XI"));
    ASSERT_TRUE(validator.Validate("XII"));
    ASSERT_TRUE(validator.Validate("XII"));
    ASSERT_TRUE(validator.Validate("XIV"));
    ASSERT_TRUE(validator.Validate("XV"));
    ASSERT_TRUE(validator.Validate("XVI"));
    ASSERT_TRUE(validator.Validate("XVII"));
    ASSERT_TRUE(validator.Validate("XVIII"));
    ASSERT_TRUE(validator.Validate("XIX"));
    ASSERT_TRUE(validator.Validate("XX"));
}

TEST_F(ValidatorTest, ADigitAfterXXShouldNotBeLOrC) {
    ASSERT_FALSE(validator.Validate("XXL"));
    ASSERT_FALSE(validator.Validate("XXC"));
}

TEST_F(ValidatorTest, ADigitsAfterXXXShoudNotBeX) {
    ASSERT_FALSE(validator.Validate("XXXX"));
}

TEST_F(ValidatorTest, ADigitAfterXLShouldNotBeX) {
    ASSERT_FALSE(validator.Validate("XLX"));
}

TEST_F(ValidatorTest, ADigitAfterLXShouldNotBeLOrC) {
    ASSERT_FALSE(validator.Validate("LXL"));
    ASSERT_FALSE(validator.Validate("LXC"));
}

TEST_F(ValidatorTest, ADigitAfterXCShouldNotBeX) {
    ASSERT_FALSE(validator.Validate("XCX"));
}
