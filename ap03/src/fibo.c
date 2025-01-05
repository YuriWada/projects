#include "../include/fibo.h"

long long fibo_recursivo(int n) {
    // caso base
    if (n <= 2) return 1;

    // volatile double result = 1.0;
    // for (int i = 0; i < 1000000; i++) {
    //     result *= n;
    //     result /= (n + 1);
    // }

    return fibo_recursivo(n - 1) + fibo_recursivo(n - 2);
}

long long fibo_iterativo(int n) {
    if (n == 0) return 1;
    
    int ant = 0;
    int sum = 0;
    int aux = 1;

    while(n > 0) 
    {
        // @ant eh o valor anterior a atualizacao de @sum
        ant = sum;
        sum += aux;
        aux = ant;
        n--;
    }

    return sum;
}