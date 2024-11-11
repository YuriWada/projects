#include "src/fatorial.c"
#include "src/fibo.c"

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define FATORIALRECURSIVE 1
#define FATORIALITERATIVE 2
#define FIBONACCIRECURSIVE 3
#define FIBONACCIITERATIVE 4

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
    {FATORIALRECURSIVE, "ftr"},
    {FATORIALITERATIVE, "fti"},
    {FIBONACCIRECURSIVE, "fbr"},
    {FIBONACCIITERATIVE, "fbi"},
    {0, 0}
};

int name2num (char * name)
{
    int i = 0;
    while (algvet[i].num)
    {
        if (!strcmp(algvet[i].name,name)) return algvet[i].num;
        i++;
    }
    return 0;
}

void opcoes() 
{
    fprintf(stderr, "-f <int> (vector size)\n");
    fprintf(stderr, "\t-a <ftr|fti|fbr|fbi>\t(algorithm)\n");
    fprintf(stderr, "\t    ftr\tfatorial recursivo\n");
    fprintf(stderr, "\t    fti\tfatorial iterativo\n");    
    fprintf(stderr, "\t    fbr\tfibonacci recursivo\n");
    fprintf(stderr, "\t    fbi\tfibonacci iterativo\n");
}

void parse_args(int argc, char ** argv, opt_t * opt)
{
    // variaveis externas
    extern char * optarg;
    extern int optind;

    // variavel auxiliar
    int c;

    // inicializacao de variaveis
    opt->size = 10;
    opt->alg = 1;

    while((c = getopt(argc, argv, "f:a:h")) != -1)
    {
        switch(c)
        {
            case 'f':
                opt->size = atoi(optarg);
                break;
            case 'a':
                opt->alg = name2num(optarg);
                break;
            case 'h':
            default:
                opcoes();
                exit(1);
        }
    }

    if (!opt->alg)
    {
        opcoes();
        exit(1);
    }
}

int clkDiff(struct timespec t1, struct timespec t2,
        struct timespec * res)
{
  if (t2.tv_nsec < t1.tv_nsec)
  {
    res-> tv_nsec = 1000000000+t2.tv_nsec-t1.tv_nsec;
    res-> tv_sec = t2.tv_sec-t1.tv_sec-1;
  } 
  else 
  {
    res-> tv_nsec = t2.tv_nsec-t1.tv_nsec;
    res-> tv_sec = t2.tv_sec-t1.tv_sec;
  }
}

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
        case FATORIALRECURSIVE:
            printf("ftr(%d): %lld\n", opt.size, fatorial_recursivo(opt.size));
            break;
        case FATORIALITERATIVE:
            printf("fti(%d): %lld\n", opt.size,fatorial_iterativo(opt.size));
            break;
        case FIBONACCIRECURSIVE:
            printf("fbr(%d): %lld\n", opt.size, fibo_recursivo(opt.size));
            break;
        case FIBONACCIITERATIVE:
            printf("fbi(%d): %lld\n", opt.size, fibo_iterativo(opt.size));
            break;
    }
    retp = clock_gettime(CLOCK_MONOTONIC, &endtp);
    clkDiff(inittp, endtp, &restp);

    printf("time %ld.%.9ld\n", restp.tv_sec, restp.tv_nsec);

    exit(0);
}