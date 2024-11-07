#include "../include/fibo.h"

int fibo_recursivo(int n) {
    if (n <= 2) {
        return 1;
    }

    return fibo_recursivo(n - 1) + fibo_recursivo(n - 2);
}

int fibo_iterativo(int n) {
    if (n == 0) return 1;
    int ant = 0;
    int sum = 0;
    int aux = 1;
    while(n > 0) {
        ant = sum;
        sum += aux;
        aux = ant;
        n--;
    }
    return sum;
}