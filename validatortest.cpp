#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <array>
#include <algorithm>

using namespace testing;

static const std::array<char, 7> kDigits{'I', 'V', 'X', 'L', 'C', 'D', 'M'};
static const std::array<char, 5> kIVXLC{'I', 'V', 'X', 'L', 'C'};
static const std::array<char, 3> kIVX{'I', 'V', 'X'};
static const std::array<char, 1> kI{'I'};

class Validator {
public:
    bool Validate(const std::string& value) {
        if (value.empty()) { return false; }
        Reset();
        for (auto digit: value) {
            if (!Check(digit)) return false;
        }
        return true;
    }

private:
    std::vector<char> digits;

    void Reset() {
        digits.assign(std::begin(kDigits), std::end(kDigits));
    }

    void Update(char currentDigit) {
        switch (currentDigit) {
        case 'I': digits.assign(std::begin(kIVX), std::end(kIVX)); break;
        case 'V':
        case 'L': digits.assign(std::begin(kI), std::end(kI)); break;
        case 'X': digits.assign(std::begin(kIVXLC), std::end(kIVXLC)); break;
        }
    }

    bool Check(char currentDigit) {
        if (std::any_of(std::begin(digits), std::end(digits),
                           [currentDigit](char item) {
                        return currentDigit == item; }
                        )) {
                Update(currentDigit);
                return true;
        }
        return false;
    }
};

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
