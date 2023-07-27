#include "gtest/gtest.h"

int divFun(int numerator, int denominator)
{
    if (denominator <= 0)
    {
        return 0;
    }

    return numerator / denominator;
}

TEST(DivFunTestSuite, HandleValidInputs)
{
    int numerator = 10;
    int denominator = 5;
    int expected_value = 2;

    int actual_value = divFun(numerator, denominator);

    ASSERT_EQ(actual_value, expected_value);
}

TEST(DivFunTestSuite, HandleDivideByZero)
{
    int numerator = 10;
    int denominator = 0;
    int expected_value = 0;

    int actual_value = divFun(numerator, denominator);

    ASSERT_EQ(actual_value, expected_value);
}

TEST(DivFunTestSuite, HandleNegativeDenominator)
{
    int numerator = 10;
    int denominator = -5;
    int expected_value = 0;

    int actual_value = divFun(numerator, denominator);

    ASSERT_EQ(actual_value, expected_value);
}