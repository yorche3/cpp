#include <gtest/gtest.h>
#include "../include/numbers.h"

class NumbersIterativeTests : public ::testing::Test
{
protected:
    Numbers _numbers;
};

TEST_F(NumbersIterativeTests, sumOfFirstNIter)
{
    EXPECT_EQ(_numbers.sumOfFirstNIter(0), 0);
    EXPECT_EQ(_numbers.sumOfFirstNIter(3), 6);
}

TEST_F(NumbersIterativeTests, factorialIter)
{
    EXPECT_EQ(_numbers.factorialIter(0), 1);
    EXPECT_EQ(_numbers.factorialIter(4), 24);
}

TEST_F(NumbersIterativeTests, fibonacciIter)
{
    EXPECT_EQ(_numbers.fibonacciIter(0), 0);
    EXPECT_EQ(_numbers.fibonacciIter(1), 1);
    EXPECT_EQ(_numbers.fibonacciIter(6), 8);
}

TEST_F(NumbersIterativeTests, largestCommonDivisorIter)
{
    EXPECT_EQ(_numbers.largestCommonDivisorIter(12, 8), 4);
    EXPECT_EQ(_numbers.largestCommonDivisorIter(7, 5), 1);
}

TEST_F(NumbersIterativeTests, leastCommonMultipleIter)
{
    EXPECT_EQ(_numbers.leastCommonMultipleIter(6, 8), 24);
    EXPECT_EQ(_numbers.leastCommonMultipleIter(4, 6), 12);
}