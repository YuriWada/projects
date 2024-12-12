#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/grafo.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Uso: %s <operação>\n", argv[0]);
        return 1;
    }

    int n;
    scanf("%d", &n);

    Grafo *g = NovoGrafo();
    for (int i = 0; i < n; i++)
    {
        InsereVertice(g);
    }

    for (int i = 0; i < n; i++)
    {
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            int vizinho;
            scanf("%d", &vizinho);
            InsereAresta(g, i, vizinho);
        }
    }

    if (strcmp(argv[1], "-d") == 0)
    {
        printf("%d\n%d\n%d\n%d\n", QuantidadeVertices(g), QuantidadeArestas(g), GrauMinimo(g), GrauMaximo(g));
    }
    else if (strcmp(argv[1], "-n") == 0)
    {
        for (int i = 0; i < n; i++)
        {
            ImprimeVizinhos(g, i);
        }
    }
    else if (strcmp(argv[1], "-k") == 0)
    {
        int completo = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (!EhAresta(g, i, j))
                {
                    completo = 0;
                    break;
                }
            }
            if (!completo)
                break;
        }
        printf("%d\n", completo);
    }
    else
    {
        fprintf(stderr, "Operação inválida.\n");
    }

    DeletaGrafo(g);
    return 0;
}
