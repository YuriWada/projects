#include "../../include/aux/aux.h"

// Mapeamento de operações
alg_t algvet[] = {
    {MATRIX_MULTIPLICATION, "m"},
    {MATRIX_ADD, "a"},
    {MATRIX_SUBTRACT, "s"},
    {MATRIX_TRANSPOSE, "t"},
    {0, 0}};

int name2num(char *name)
{
    int i = 0;
    while (algvet[i].num)
    {
        if (!strcmp(algvet[i].name, name))
            return algvet[i].num;
        i++;
    }
    return 0;
}

// Função que exibe as opções disponíveis
void opcoes()
{
    fprintf(stderr, "Uso:\n");
    fprintf(stderr, "-m <filename1> <filename2> (multiplicação de matrizes)\n");
    fprintf(stderr, "-a <filename1> <filename2> (adição de matrizes)\n");
    fprintf(stderr, "-s <filename1> <filename2> (subtração de matrizes)\n");
    fprintf(stderr, "-t <filename> (transposição de matriz)\n");
    fprintf(stderr, "-h (ajuda)\n");
}

// Função para processar os argumentos da linha de comando
void parse_args(int argc, char **argv, opt_t *opt)
{
    extern char *optarg;
    extern int optind;
    int c;

    opt->size = 10; // Tamanho padrão
    opt->alg = 0;   // Nenhuma operação selecionada inicialmente
    opt->file1 = NULL;
    opt->file2 = NULL;

    while ((c = getopt(argc, argv, "m:a:s:t:h")) != -1)
    {
        switch (c)
        {
        case 'm': // Multiplicação de matrizes
            if (optind>= argc)
            {
                fprintf(stderr, "Erro: Faltam argumentos para a opção '-%c'.\n", c);
                opcoes();
                exit(1);
            }
            opt->alg = MATRIX_MULTIPLICATION;
            opt->file1 = optarg;
            opt->file2 = argv[optind++];
            break;

        case 'a': // Adição de matrizes
            if (optind >= argc)
            {
                fprintf(stderr, "Erro: Faltam argumentos para a opção '-%c'.\n", c);
                opcoes();
                exit(1);
            }
            opt->alg = MATRIX_ADD;
            opt->file1 = optarg;
            opt->file2 = argv[optind++];
            break;

        case 's': // Subtração de matrizes
            if (optind >= argc)
            {
                fprintf(stderr, "Erro: Faltam argumentos para a opção '-%c'.\n", c);
                opcoes();
                exit(1);
            }
            opt->alg = MATRIX_SUBTRACT;
            opt->file1 = optarg;
            opt->file2 = argv[optind++];
            break;

        case 't': // Transposição de matriz
            opt->alg = MATRIX_TRANSPOSE;
            opt->file1 = optarg;
            break;

        case 'h': // Ajuda
        default:
            opcoes();
            exit(1);
        }
    }

    // Verifica se uma operação foi selecionada
    if (!opt->alg)
    {
        fprintf(stderr, "Erro: Nenhuma operação foi especificada.\n");
        opcoes();
        exit(1);
    }
}

int count_columns(FILE *file)
{
    char buffer[1024];
    int columns = 0;

    if (fgets(buffer, sizeof(buffer), file))
    {
        char *token = strtok(buffer, ",\n");
        while (token)
        {
            columns++;
            token = strtok(NULL, ",\n");
        }
    }
    rewind(file);
    return columns;
}

int count_rows(FILE *file)
{
    char buffer[1024];
    int rows = 0;

    while (fgets(buffer, sizeof(buffer), file))
    {
        rows++;
    }
    rewind(file);
    return rows;
}

Mat *read_csv(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        fprintf(stderr, "Erro ao abrir o arquivo: %s\n", filename);
        return NULL;
    }

    // Conta linhas e colunas
    int rows = count_rows(file);
    int cols = count_columns(file);

    Mat *matrix = createMatrix(rows, cols);
    initMatrix(matrix);

    char buffer[1024];
    int row = 0;
    while (fgets(buffer, sizeof(buffer), file))
    {
        int col = 0;
        char *token = strtok(buffer, ",\n");
        while (token)
        {
            matrix->e[row][col] = atoi(token);
            col++;
            token = strtok(NULL, ",\n");
        }
        row++;
    }

    fclose(file);
    return matrix;
}