#include "include/matrix.h"
#include "include/aux/aux.h"

int main(int argc, char **argv) {
    opt_t opt;
    parse_args(argc, argv, &opt);

    switch (opt.alg) {
        case MATRIX_MULTIPLICATION:
            printf("Executando multiplicação de matrizes: %s e %s\n", opt.file1, opt.file2);
            printf("Matrix A:\n");
            Mat *a = read_csv(opt.file1);
            printMat(a);
            printf("Matrix B:\n");
            Mat *b = read_csv(opt.file2);
            printMat(b);
            printf("Mult Matrices:\n");
            Mat *c = multMat(a, b);
            printMat(c);
            deleteMatrix(a);
            deleteMatrix(b);
            deleteMatrix(c);
            break;

        case MATRIX_ADD:
            printf("Executando adição de matrizes: %s e %s\n", opt.file1, opt.file2);
            printf("Matrix A:\n");
            Mat *a1 = read_csv(opt.file1);
            printMat(a1);
            printf("Matrix B:\n");
            Mat *b1 = read_csv(opt.file2);
            printMat(b1);
            printf("Sum Matrices:\n");
            Mat *c1 = sumMat(a1, b1);
            printMat(c1);
            deleteMatrix(a1);
            deleteMatrix(b1);
            deleteMatrix(c1);
            break;

        case MATRIX_SUBTRACT:
            printf("Executando subtração de matrizes: %s e %s\n", opt.file1, opt.file2);
            printf("Matrix A:\n");
            Mat *a2 = read_csv(opt.file1);
            printMat(a2);
            printf("Matrix B:\n");
            Mat *b2 = read_csv(opt.file2);
            printMat(b2);
            printf("Subs Matrices:\n");
            Mat *c2 = subsMat(a2, b2);
            printMat(c2);
            deleteMatrix(a2);
            deleteMatrix(b2);
            deleteMatrix(c2);
            break;

        case MATRIX_TRANSPOSE:
            printf("Executando transposição de matriz: %s\n", opt.file1);
            printf("Matrix A:\n");
            Mat *a3 = read_csv(opt.file1);
            printMat(a3);
            printf("Matrix transposed:\n");
            Mat *b3 = transposed(a3);
            printMat(b3);
            deleteMatrix(a3);
            deleteMatrix(b3);
            break;

        default:
            fprintf(stderr, "Erro: Operação inválida.\n");
            exit(1);
    }

    return 0;
}
