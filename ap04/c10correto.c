#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int *p;
    while(1)
    {
        p = malloc(128);
        printf("%ld\n", (long)p);
        free(p); // libera memoria
    }
    return (0);
}
