#include "include/matrix.h"

int main(int argc, char *argv[])
{

    Mat *m;
    m = createMatrix(3, 3);
    initMatrix(m);

    printf("Enter the matrix values:");
    for (int i = 0; i < m->r; i++)
    {
        for (int j = 0; j < m->c; j++)
        {
            scanf("%d", &m->e[i][j]);
        }
    }

    printMat(m);

    Mat *mt = transposed(m);
    printMat(mt);

    deleteMatrix(mt);
    deleteMatrix(m);
    return 0;
}