#include "src/fatorial.c"
#include "src/fibo.c"
#include "src/aux/aux.c"

int main(int argc, char **argv)
{
    //char pref[100];
    opt_t opt;
    struct timespec inittp, endtp, restp;
    int retp;

    parse_args(argc, argv, &opt);

    retp = clock_gettime(CLOCK_MONOTONIC, &inittp);
    
    switch(opt.alg)
    {
        case TASK1:
            printf("fatorial recursive(%d): %lld\n", opt.size, fatorial_recursivo(opt.size));
            printf("fatorial iterative(%d): %lld\n", opt.size,fatorial_iterativo(opt.size));
            break;
        case TASK2:
            printf("fibonacci recursive(%d): %lld\n", opt.size, fibo_recursivo(opt.size));
            printf("fibonacci iterative(%d): %lld\n", opt.size, fibo_iterativo(opt.size));
            break;
    }
    retp = clock_gettime(CLOCK_MONOTONIC, &endtp);
    clkDiff(inittp, endtp, &restp);

    printf("time %ld.%.9ld\n", restp.tv_sec, restp.tv_nsec);

    exit(0);
}