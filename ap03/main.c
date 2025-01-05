#include "include/fatorial.h"
#include "include/fibo.h"
#include "include/aux/aux.h"

#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(int argc, char **argv)
{
    // char pref[100];
    opt_t opt;
    // struct timespec inittp, endtp, restp;
    // int retp;
    struct rusage usage;
    clock_t startr, starti, endr, endi;
    double cpu_time_used_r, cpu_time_used_i;

    parse_args(argc, argv, &opt);

    // retp = clock_gettime(CLOCK_MONOTONIC, &inittp);
    switch (opt.alg)
    {
    case TASK1:
        startr = clock();
        printf("fatorial recursive(%d): %lld\n", opt.size, fatorial_recursivo(opt.size));
        endr = clock();

        starti = clock();
        printf("fatorial iterative(%d): %lld\n", opt.size, fatorial_iterativo(opt.size));
        endi = clock();
        break;
    case TASK2:
        startr = clock();
        printf("fibonacci recursive(%d): %lld\n", opt.size, fibo_recursivo(opt.size));
        endr = clock();

        starti = clock();
        printf("fibonacci iterative(%d): %lld\n", opt.size, fibo_iterativo(opt.size));
        endi = clock();
        break;
    }
    cpu_time_used_r = ((double)(endr-startr)) / CLOCKS_PER_SEC;
    cpu_time_used_i = ((double)(endi-starti)) / CLOCKS_PER_SEC;
    // retp = clock_gettime(CLOCK_MONOTONIC, &endtp);
    // clkDiff(inittp, endtp, &restp);

    // printf("time %ld.%.9lds\n", restp.tv_sec, restp.tv_nsec);
    printf("time recursive: %.6f s\n", cpu_time_used_r);
    printf("time iterative: %.6f s\n", cpu_time_used_i);

    getrusage(RUSAGE_SELF, &usage);
    printf("CPU time (user): %.6f s\n",
           usage.ru_utime.tv_sec + usage.ru_utime.tv_usec / 1e6);
    printf("CPU time (system): %.6f s\n",
           usage.ru_stime.tv_sec + usage.ru_stime.tv_usec / 1e6);

    exit(0);
}