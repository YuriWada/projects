#include <stdio.h>
#include <stdlib.h>

int actual_calc(int a, int b)
{
    int c = a / b;

    return c;
}

int calc()
{
    int a = 13;
    int b = 1; // inicializa com 1
    
    return actual_calc(a, b);
}

int main(){
    calc();
    return 0;
}
