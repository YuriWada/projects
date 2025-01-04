#ifndef EVALENUM_H
#define EVALENUM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

#define ALGINSERTION 1
#define ALGSELECTION 2
#define ALGQSORT     3
#define ALGQSORT3    4
#define ALGQSORTINS  5
#define ALGQSORT3INS 6
#define ALGSHELLSORT 7
#define ALGRECSEL    8

typedef struct alg {
    int num;
    char *name;
} alg_t;

typedef struct opt {
    int size;
    int seed;
    int alg;
} opt_t;

typedef struct sortperf {
    int cmp;
    int move;
    int calls;
} sortperf_t;

void resetcounter(sortperf_t *s);
void inccmp(sortperf_t *s, int num);
void incmove(sortperf_t *s, int num);
void inccalls(sortperf_t *s, int num);
char *printsortperf(sortperf_t *s, char *str, char *pref);
void initVector(int *vet, int size);
void printVector(int *vet, int size);
void swap(int *xp, int *yp, sortperf_t *s);
void parse_args(int argc, char **argv, opt_t *opt);
void uso();
void clkDiff(struct timespec t1, struct timespec t2, struct timespec *res);

// Funções de ordenação
void shellSort(int *A, int n, sortperf_t *s);
void selectionSort(int arr[], int l, int r, sortperf_t *s);
void insertionSort(int v[], int l, int r, sortperf_t *s);
void quickSort(int *A, int l, int r, sortperf_t *s);
void quickSort3(int *A, int l, int r, sortperf_t *s);
void quickSortIns(int *A, int l, int r, sortperf_t *s);
void quickSort3Ins(int *A, int l, int r, sortperf_t *s);
void recursiveSelectionSort(int arr[], int l, int r, sortperf_t *s);

// Funções auxiliares
int median(int a, int b, int c);
void partition(int *A, int l, int r, int *i, int *j, sortperf_t *s);
void partition3(int *A, int l, int r, int *i, int *j, sortperf_t *s);

#endif
