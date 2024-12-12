#include "../include/grafo.h"

/**
 * n -> numero de vertices
 * m -> numero de arestas
 * adj -> matriz de adjacencia
 */
struct s_grafo 
{
    int n;        
    int m;        
    int** adj;    
};

Grafo* NovoGrafo() 
{
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    g->n = 0;
    g->m = 0;
    g->adj = NULL;
    return g;
}

void DeletaGrafo(Grafo* g) 
{
    if (g->adj) 
    {
        for (int i = 0; i < g->n; i++) 
        {
            free(g->adj[i]);
        }
        free(g->adj);
    }
    free(g);
}

void InsereVertice(Grafo* g) 
{
    g->n++;
    g->adj = (int**)realloc(g->adj, g->n * sizeof(int*));
    g->adj[g->n - 1] = (int*)calloc(g->n, sizeof(int));
    for (int i = 0; i < g->n - 1; i++) 
    {
        g->adj[i] = (int*)realloc(g->adj[i], g->n * sizeof(int));
        g->adj[i][g->n - 1] = 0;
    }
}

void InsereAresta(Grafo* g, int v, int w) 
{
    if (v >= g->n || w >= g->n) 
    {
        fprintf(stderr, "Erro: Vértice inválido.\n");
        return;
    }

    if (g->adj[v][w] == 0) 
    {
        g->adj[v][w] = 1;
        g->adj[w][v] = 1;
        g->m++;
    }
}

int QuantidadeVertices(Grafo* g) 
{
    return g->n;
}

int QuantidadeArestas(Grafo* g) 
{
    return g->m;
}

int GrauMinimo(Grafo* g) 
{
    int min = g->n;
    for (int i = 0; i < g->n; i++) 
    {
        int grau = 0;
        for (int j = 0; j < g->n; j++) 
        {
            grau += g->adj[i][j];
        }
        if (grau < min) min = grau;
    }
    return min;
}

int GrauMaximo(Grafo* g) 
{
    int max = 0;
    for (int i = 0; i < g->n; i++) 
    {
        int grau = 0;
        for (int j = 0; j < g->n; j++) 
        {
            grau += g->adj[i][j];
        }
        if (grau > max) max = grau;
    }
    return max;
}

void ImprimeVizinhos(Grafo* g, int v) 
{
    if (v >= g->n) 
    {
        fprintf(stderr, "Erro: Vértice inválido.\n");
        return;
    }
    
    for (int i = 0; i < g->n; i++) 
    {
        if (g->adj[v][i]) 
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}
