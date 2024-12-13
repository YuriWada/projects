#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MATRIX_MULTIPLICATION 1
#define MATRIX_ADD 2
#define MATRIX_SUBSTRACT 3

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
    {MATRIX_MULTIPLICATION, "m"},
    {MATRIX_ADD, "a"},
    {MATRIX_SUBSTRACT, "s"},
    {0, 0}
};

int name2num (char * name);
void opcoes();
void parse_args(int argc, char ** argv, opt_t * opt);