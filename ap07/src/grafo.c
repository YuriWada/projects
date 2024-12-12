#include "../include/grafo.h"

// internal graph structure
struct s_grafo
{
    int n;     // number of vertices
    int m;     // number of edges
    int **adj; // adjacency matrix
};

// check if there is an edge between vertices v and w
int EhAresta(Grafo *g, int v, int w)
{
    if (v < 0 || v >= g->n || w < 0 || w >= g->n)
    {
        return 0; // index out of bounds
    }
    return g->adj[v][w];
}

// create a new graph and initializes its structure
Grafo *NovoGrafo()
{
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    if (!g)
    {
        fprintf(stderr, "Error allocating memory for the graph.\n");
        exit(EXIT_FAILURE);
    }
    g->n = 0;
    g->m = 0;
    g->adj = NULL;
    return g;
}

// delete the graph and frees all allocated memory
void DeletaGrafo(Grafo *g)
{
    if (g)
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
}

// add a new vertex to the graph
void InsereVertice(Grafo *g)
{
    if (!g)
        return;

    g->n++; // increment the vertex count
    g->adj = (int **)realloc(g->adj, g->n * sizeof(int *));
    if (!g->adj)
    {
        fprintf(stderr, "Error reallocating memory for the adjacency matrix.\n");
        exit(EXIT_FAILURE);
    }

    // allocate memory for the new row and initialize it with zeros
    g->adj[g->n - 1] = (int *)calloc(g->n, sizeof(int));
    if (!g->adj[g->n - 1])
    {
        fprintf(stderr, "Error allocating a new row for the adjacency matrix.\n");
        exit(EXIT_FAILURE);
    }

    // expand each existing row to include the new column
    for (int i = 0; i < g->n - 1; i++)
    {
        g->adj[i] = (int *)realloc(g->adj[i], g->n * sizeof(int));
        if (!g->adj[i])
        {
            fprintf(stderr, "Error reallocating a column in the adjacency matrix.\n");
            exit(EXIT_FAILURE);
        }
        g->adj[i][g->n - 1] = 0; // initialize the new column value to zero
    }
}

// add an edge between vertices v and w
void InsereAresta(Grafo *g, int v, int w)
{
    if (!g || v >= g->n || w >= g->n || v < 0 || w < 0)
    {
        fprintf(stderr, "Error: Invalid vertex.\n");
        return;
    }

    // Check if the edge does not already exist
    if (g->adj[v][w] == 0)
    {
        g->adj[v][w] = 1;
        g->adj[w][v] = 1;
        g->m++;
    }
}

// return the number of vertices in the graph
int QuantidadeVertices(Grafo *g)
{
    return g ? g->n : 0;
}

// return the number of edges in the graph
int QuantidadeArestas(Grafo *g)
{
    return g ? g->m : 0;
}

// Compute and returns the minimum degree of the graph
int GrauMinimo(Grafo *g)
{
    if (!g || g->n == 0)
        return 0;

    int min = g->n; // start with the maximum possible degree
    for (int i = 0; i < g->n; i++)
    {
        int grau = 0;
        for (int j = 0; j < g->n; j++)
        {
            grau += g->adj[i][j]; // count edges for vertex i
        }
        if (grau < min)
            min = grau; // update minimum degree
    }
    return min;
}

// compute and return the maximum degree of the graph
int GrauMaximo(Grafo *g)
{
    if (!g || g->n == 0)
        return 0;

    int max = 0; // start with the minimum possible degree
    for (int i = 0; i < g->n; i++)
    {
        int grau = 0;
        for (int j = 0; j < g->n; j++)
        {
            grau += g->adj[i][j];
        }
        if (grau > max)
            max = grau;
    }
    return max;
}

// print all neighbors of vertex v
void ImprimeVizinhos(Grafo *g, int v)
{
    if (!g || v >= g->n || v < 0)
    {
        fprintf(stderr, "Error: Invalid vertex.\n");
        return;
    }

    // iterate through the adjacency matrix row for vertex v
    for (int i = 0; i < g->n; i++)
    {
        if (g->adj[v][i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}
