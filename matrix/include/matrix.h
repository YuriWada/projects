#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>

typedef struct Matrix
{
    int **e;
    int r;
    int c;
} Mat;

Mat *createMatrix(int i, int j);
void initMatrix(Mat *m);
void deleteMatrix(Mat *m);


#endif