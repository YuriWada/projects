#include "../include/fatorial.h"

long long fatorial_recursivo(int n) {
    // caso base
    if (n <= 1) return 1;

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