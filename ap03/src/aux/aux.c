#include "../../include/aux/aux.h"

alg_t algvet[] =
{
    {TASK1, "tk1"},
    {TASK2, "tk2"},
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
    fprintf(stderr, "\t-t <tk1|tk2>\t(task)\n");
    fprintf(stderr, "\t    tk1\ttask 1\n");
    fprintf(stderr, "\t    tk2\ttask 2\n");    
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

    while((c = getopt(argc, argv, "f:t:h")) != -1)
    {
        switch(c)
        {
            case 'f':
                opt->size = atoi(optarg);
                break;
            case 't':
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

void clkDiff(struct timespec t1, struct timespec t2,
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