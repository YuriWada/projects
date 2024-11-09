#include "src/fatorial.c"
#include "src/fibo.c"
#include <stdio.h>

int main() {

    int n = 0;
    printf("Insira um numero inteiro positivo: ");
    scanf("%d", &n);

    if (n < 0) 
    {
        // tratamento dos dados de entrada aqui
        printf("Valor invalido!\n");
        return 1;
    }

    // printf("O fatorial (recursivo) de %d eh %d \n", n, fatorial_recursivo(n));
    // printf("O fatorial (iterativo) de %d eh %d \n", n, fatorial_iterativo(n));

    printf("O fibonacci (recursivo) de %d eh %d \n", n, fibo_recursivo(n));
    printf("O fibonacci (iterativo) de %d eh %d \n", n, fibo_iterativo(n));


    return 0;
}