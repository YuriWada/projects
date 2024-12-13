#include "../../include/aux/aux.h"

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
    fprintf(stderr, "-f <str> (file name)\n");
    fprintf(stderr, "-m <int> (mult matrix)\n");
    fprintf(stderr, "-a <int> (add matrix)\n");
    fprintf(stderr, "-s <int> (substract matrix)\n");  
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

    while((c = getopt(argc, argv, "f:m:a:s:h")) != -1)
    {
        switch(c)
        {
            case 'f':
                opt->size = atoi(optarg);
                break;
            case 'm':
                opt->alg = name2num(optarg);
                break;
            case 'a':
                opt->alg = name2num(optarg);
                break;
            case 's':
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