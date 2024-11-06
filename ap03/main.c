#include "src/fatorial.c"
#include <stdio.h>

int main() {

    int n = 0;
    printf("Insira um numero inteiro positivo: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Valor invalido!\n");
        return 1;
    }

    printf("O fatorial (recursivo) de %d eh %d \n", n, fatorial_recursivo(n));
    printf("O fatorial (iterativo) de %d eh %d \n", n, fatorial_iterativo(n));

    return 0;
}