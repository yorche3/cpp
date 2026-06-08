#include "../include/numbers.h"

int Numbers::sumOfFirstNRec(int n)
{
    if (n == 0) return 0;
    return n + sumOfFirstNRec(n - 1);
}

int Numbers::factorialRec(int n)
{
    if (n == 0 || n == 1) return 1;
    return n * factorialRec(n - 1);
}

int Numbers::fibonacciRec(int n)
{
    if (n <= 1) return n;
    return fibonacciRec(n - 1) + fibonacciRec(n - 2);
}

int Numbers::largestCommonDivisorRec(int a, int b)
{
    if (b == 0) return a;
    return largestCommonDivisorRec(b, a % b);
}

int Numbers::leastCommonMultipleRec(int a, int b)
{
    return (a * b) / largestCommonDivisorRec(a, b);
}

int Numbers::sumOfFirstNHelp(int n, int acc)
{
    if (n == 0) return acc;
    return sumOfFirstNHelp(n - 1, acc + n);
}

int Numbers::factorialHelp(int n, int acc)
{
    if (n == 0 || n == 1) return acc;
    return factorialHelp(n - 1, acc * n);
}

int Numbers::fibonacciHelp(int n, int acc)
{
    if (n <= 1) return acc;
    return fibonacciHelp(n - 1, acc + n);
}

int Numbers::largestCommonDivisorHelp(int a, int b, int acc)
{
    if (b == 0) return acc;
    return largestCommonDivisorHelp(b, a % b, acc);
}

int Numbers::sumOfFirstNIter(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int Numbers::factorialIter(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int Numbers::fibonacciIter(int n)
{
    if (n <= 1) return n;
    int acc1 = 0;
    int acc2 = 1;
    for (int i = 2; i <= n; i++)
    {
        int temp = acc2;
        acc2 = acc1 + acc2;
        acc1 = temp;
    }
    return acc2;
}

int Numbers::largestCommonDivisorIter(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int Numbers::leastCommonMultipleIter(int a, int b)
{
    return (a * b) / largestCommonDivisorIter(a, b);
}