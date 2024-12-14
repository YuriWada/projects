#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
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

Mat *multMat(Mat *a, Mat *b);
Mat *sumMat(Mat *a, Mat *b);

#endif