#ifndef AUX_H
#define AUX_H

#include "../fatorial.h"
#include "../fibo.h"

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define TASK1 1
#define TASK2 2

typedef struct alg
{
    int num;
    char * name;
} alg_t;

typedef struct opt
{
    int size;
    int alg;
} opt_t;

alg_t algvet[] =
{
    {TASK1, "tk1"},
    {TASK2, "tk2"},
    {0, 0}
};

int name2num (char * name);
void opcoes();
void parse_args(int argc, char ** argv, opt_t * opt);
int clkDiff(struct timespec t1, struct timespec t2, struct timespec * res);

#endif /* AUX_H */