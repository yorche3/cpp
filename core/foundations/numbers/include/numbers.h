#ifndef NUMBERS_H
#define NUMBERS_H

class Numbers
{
    public:
        int sumOfFirstNRec(int n);
        int factorialRec(int n);
        int fibonacciRec(int n);
        int largestCommonDivisorRec(int a, int b);
        int leastCommonMultipleRec(int a, int b);

        int sumOfFirstNAcc(int n);
        int factorialAcc(int n);
        int fibonacciAcc(int n);
        int largestCommonDivisorAcc(int a, int b);
        int leastCommonMultipleAcc(int a, int b);

        int sumOfFirstNIter(int n);
        int factorialIter(int n);
        int fibonacciIter(int n);
        int largestCommonDivisorIter(int a, int b);
        int leastCommonMultipleIter(int a, int b);

    private:
        int sumOfFirstNHelp(int n, int acc);
        int factorialHelp(int n, int acc);
        int fibonacciHelp(int n, int acc);
        int largestCommonDivisorHelp(int a, int b, int acc);
        int leastCommonMultipleHelp(int a, int b, int acc);
};

#endif // NUMBERS_H