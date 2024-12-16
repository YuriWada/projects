#include "../matrix.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MATRIX_MULTIPLICATION 1
#define MATRIX_ADD 2
#define MATRIX_SUBTRACT 3
#define MATRIX_TRANSPOSE 4

typedef struct alg {
    int num;
    char *name;
} alg_t;

typedef struct opt {
    int size;
    int alg;
    char *file1;
    char *file2;
} opt_t;

// Funções auxiliares
int name2num(char *name);
void opcoes();
void parse_args(int argc, char **argv, opt_t *opt);
int count_columns(FILE *file);
int count_rows(FILE *file);
Mat *read_csv(const char *filename);