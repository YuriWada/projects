#include "../include/fatorial.h"

int fatorial_recursivo(int n) {
    if (n <= 1) {
        return 1;
    }

    return fatorial_recursivo(n - 1) * n;
}

int fatorial_iterativo(int n) {
    int prod = 1;
    while(n >= 1) {
        prod = prod * n;
        n--;
    }
    return prod;
}