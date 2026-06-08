#include "../include/calculator.h"

int Calculator::addition(int a, int b) {
    return a + b;
}

int Calculator::subtraction(int a, int b) {
    return a - b;
}

int Calculator::multiplication(int a, int b) {
    int result = 0;
    // TODO: Implement multiplication using addition and loop
    for (int i = 0; i < b; i++)
    {
        result = addition(result, a);
    }
    return result;
}

int Calculator::division(int a, int b) {
    int quotient = 0;
    // TODO: Implement division using subtraction and loop
    while (a >= b)
    {
        a = subtraction(a, b);
        quotient = addition(quotient, 1);
    }
    return quotient;
}

int Calculator::modulus(int a, int b) {
    // TODO: Implement modulus using division
    int quotient = division(a, b);
    return subtraction(a, multiplication(b, quotient));
}