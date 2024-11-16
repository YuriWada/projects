 #include <stdlib.h>

void f(void)
{
    int* x = malloc(11 * sizeof(int)); // aloca espaco suficiente
    x[10] = 0;
    free(x); // libera memoria
}

int main(void) {
    f();

    return 0;
}


