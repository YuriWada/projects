#include "../include/fatorial.h"

long long fatorial_recursivo(int n) {
    // caso base
    if (n <= 1) return 1;

    volatile double result = 1.0;
    for (int i = 0; i < 1000000; i++) {
        result *= n;
        result /= (n + 1);
    }

    volatile double result1 = 1.0;
    for (int i = 0; i < 1000000; i++) {
        result1 *= n;
        result1 /= (n + 1);
    }

    return fatorial_recursivo(n - 1) * n;
}

long long fatorial_iterativo(int n) {
    int prod = 1;

    while (n >= 1)
    {
        prod = prod * n;
        n--;
    }

    return prod;
}