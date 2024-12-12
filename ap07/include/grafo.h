#include <stdio.h>
#include <stdlib.h>

typedef struct s_grafo Grafo;

Grafo* NovoGrafo();
void DeletaGrafo(Grafo* g);

void InsereVertice(Grafo* g);
void InsereAresta(Grafo* g, int v, int w);

int QuantidadeVertices(Grafo* g);
int QuantidadeArestas(Grafo* g);

int GrauMinimo(Grafo* g);
int GrauMaximo(Grafo* g);

void ImprimeVizinhos(Grafo* g, int v);