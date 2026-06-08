#include <gtest/gtest.h>
#include "../include/numbers.h"

class NumbersRecursiveTests : public ::testing::Test
{
protected:
    Numbers _numbers;
};

TEST_F(NumbersRecursiveTests, sumOfFirstNRec)
{
    EXPECT_EQ(_numbers.sumOfFirstNRec(0), 0);
    EXPECT_EQ(_numbers.sumOfFirstNRec(3), 6);
}

TEST_F(NumbersRecursiveTests, factorialRec)
{
    EXPECT_EQ(_numbers.factorialRec(0), 1);
    EXPECT_EQ(_numbers.factorialRec(4), 24);
}

TEST_F(NumbersRecursiveTests, fibonacciRec)
{
    EXPECT_EQ(_numbers.fibonacciRec(0), 0);
    EXPECT_EQ(_numbers.fibonacciRec(1), 1);
    EXPECT_EQ(_numbers.fibonacciRec(6), 8);
}

TEST_F(NumbersRecursiveTests, largestCommonDivisorRec)
{
    EXPECT_EQ(_numbers.largestCommonDivisorRec(12, 8), 4);
    EXPECT_EQ(_numbers.largestCommonDivisorRec(7, 5), 1);
}

TEST_F(NumbersRecursiveTests, leastCommonMultipleRec)
{
    EXPECT_EQ(_numbers.leastCommonMultipleRec(6, 8), 24);
    EXPECT_EQ(_numbers.leastCommonMultipleRec(4, 6), 12);
}