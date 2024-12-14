#include "include/matrix.h"

int main(int argc, char *argv[])
{

    Mat *m;
    m = createMatrix(3, 3);
    initMatrix(m);

    deleteMatrix(m);
    return 0;
}