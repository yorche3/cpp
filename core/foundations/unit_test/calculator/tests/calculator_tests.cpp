#include <gtest/gtest.h>
#include "../include/calculator.h"

class CalculatorTests : public ::testing::Test
{
protected:
    Calculator _calculator;
};

TEST_F(CalculatorTests, Addition)
{
    EXPECT_EQ(_calculator.addition(2, 3), 5);
}

TEST_F(CalculatorTests, Subtraction)
{
    EXPECT_EQ(_calculator.subtraction(5, 3), 2);
}

TEST_F(CalculatorTests, Multiplication)
{
    EXPECT_EQ(_calculator.multiplication(4, 3), 12);
}

TEST_F(CalculatorTests, Division)
{
    EXPECT_EQ(_calculator.division(10, 3), 3);
}

TEST_F(CalculatorTests, Modulus)
{
    EXPECT_EQ(_calculator.modulus(10, 3), 1);
}
