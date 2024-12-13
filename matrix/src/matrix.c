#include "../include/matrix.h"

Mat *createMatrix(int i, int j)
{
    Mat *m = (Mat*)malloc(sizeof(Mat));
    if (m == NULL)
    {
        printf("Matrix Mem Alloc ERR");
        exit(1);
    }

    m->r = i;
    m->c = j;

    m->e = (int**)malloc(i * sizeof(int*));
    if (m->e == NULL)
    {
        printf("Matrix Rows Mem Alloc ERR");
        free(m);
        exit(1);
    }

    for (int x = 0; x < i; x++)
    {
        m->e[x] = (int*)malloc(j * sizeof(int));
        if (m->e[x] == NULL)
        {
            printf("Matrix Cols Mem Alloc ERR");
            for (int y = 0; y < x; y++) free(m->e[y]);
            free(m->e);
            free(m);
            exit(1);
        }
    }
}

void initMatrix(Mat *m)
{
    for(int x = 0; x < m->r; x++)
    {
        for(int y = 0; y < m->c; y++)
        {
            m->e[x][y] = 0;
        }
    }
}

void deleteMatrix(Mat *m)
{
    for (int i = 0; i < m->r; i++)
    {
        free(m->e[i]);
    }
    free(m->e);
    free(m);
}