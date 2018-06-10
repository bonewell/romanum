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
