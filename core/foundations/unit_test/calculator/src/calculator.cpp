#include "../include/calculator.h"

int Calculator::addition(int a, int b) {
    return a + b;
}

int Calculator::subtraction(int a, int b) {
    return a - b;
}

int Calculator::multiplication(int a, int b) {
    int result = 0;
    // Multiplicación educativa: a sumado a sí mismo b veces.
    for (int i = 0; i < b; i++)
    {
        result = addition(result, a);
    }
    return result;
}

int Calculator::division(int a, int b) {
    int quotient = 0;
    // División educativa: cuántas veces cabe b en a por restas sucesivas.
    while (a >= b)
    {
        a = subtraction(a, b);
        quotient = addition(quotient, 1);
    }
    return quotient;
}

int Calculator::modulus(int a, int b) {
    // Resto construido con la división y la multiplicación: a - (cociente * b).
    int quotient = division(a, b);
    return subtraction(a, multiplication(b, quotient));
}