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

    return m;
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

void printMat(Mat *m)
{
    if (!m->e)
    {
        printf("Cannot print null matrix!");
        return;
    }

    for (int i = 0; i < m->r; i++)
    {
        for (int j = 0; j < m->c; j++)
        {
            printf("%d ", m->e[i][j]);
        }
        printf("\n");
    }
}

/**
 * Mult matrices follows the formula
 * c(ij) = sum(k->n)[a(ik)*b(kj)]
 */
Mat *multMat(Mat *a, Mat *b)
{
    if (a->c != b->r)
    {
        printf("Matrices doesn't follow the requirements!");
        return NULL;
    }

    Mat *c = createMatrix(a->r, b->c);
    initMatrix(c);

    for (int i = 0; i < a->r; i++)
    {
        for (int j = 0; j < b->c; j++)
        {
            for (int k = 0; k < a->c; k++)
            {
                c->e[i][j] += a->e[i][k] * b->e[k][j];
            }
        }
    }

    return c;
}

Mat *sumMat(Mat *a, Mat *b)
{
    if (a->r != b->r || a->c != b->c)
    {
        printf("Matrices doesn't follow the requirements");
        return NULL;
    }

    Mat *c = createMatrix(a->r, a->c);
    initMatrix(c);

    for (int i = 0; i < c->r; i++)
    {
        for (int j = 0; j < c->c; j++)
        {
            c->e[i][j] = a->e[i][j] + b->e[i][j];
        }
    }
    
    return c;
}

Mat *subsMat(Mat *a, Mat *b)
{
    if (a->r != b->r || a->c != b->c)
    {
        printf("Matrices doesn't follow the requirements");
        return NULL;
    }

    Mat *c = createMatrix(a->r, a->c);
    initMatrix(c);

    for (int i = 0; i < c->r; i++)
    {
        for (int j = 0; j < c->c; j++)
        {
            c->e[i][j] = a->e[i][j] - b->e[i][j];
        }
    }
    
    return c;
}

Mat *transposed(Mat *m)
{
    Mat *mt = createMatrix(m->r, m->c);
    initMatrix(mt);

    for (int i = 0; i < m->c; i++)
    {
        for (int j = 0; j < m->r; j++)
        {
            mt->e[i][j] = m->e[j][i];
        }
    }

    return mt;
}


