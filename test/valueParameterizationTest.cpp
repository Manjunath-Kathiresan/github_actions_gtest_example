#include "gtest/gtest.h"

int divFun(int numerator, int denominator)
{
    if (denominator <= 0)
    {
        return 0;
    }

    return numerator / denominator;
}

class DivFunTestSuite : public testing::TestWithParam<std::tuple<int, int, int>>
{
    protected:
    DivFunTestSuite(){}
    ~DivFunTestSuite(){}
};

TEST_P(DivFunTestSuite, HandleValidInputs) 
{
    int numerator = std::get<0>(GetParam());
    int denominator = std::get<1>(GetParam());
    int expected_value = std::get<2>(GetParam());

    int actual_value = divFun(numerator, denominator);

    ASSERT_EQ(actual_value, expected_value);
}

INSTANTIATE_TEST_SUITE_P(
        DivFunTestSuiteParameterExample,
        DivFunTestSuite,
        ::testing::Values(
                std::make_tuple(10, 5, 2),
                std::make_tuple(10, 0, 0),
                std::make_tuple(10, -5, 0)));

/*TEST(DivFunTestSuite, HandleValidInputs)
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
}*/