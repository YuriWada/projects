#include "../include/heap.h"

Heap* NovoHeap(int maxsize)
{
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->tamanho = 0; // começa com tamanho 0
    h->dados = (int*)malloc(maxsize * sizeof(int));
    return h;
}

void DeletaHeap(Heap* h)
{
    free(h->dados); // primeiro libera ponteiro interno
    free(h);
}

void Inserir(Heap* h, int x)
{
    h->dados[h->tamanho] = x; // insere elemento no final
    h->tamanho++; // aumenta o tamanho do heap
    HeapifyPorCima(h, h->tamanho-1); // restaura heap
}

int Remover(Heap* h)
{
    int min = h->dados[0]; // armazena o menor valor
    h->dados[0] = h->dados[h->tamanho-1]; // substitui o menor pelo ultimo
    h->tamanho--;
    HeapifyPorBaixo(h, 0); // restaura heap
    return min;
}

int GetAncestral(Heap* h, int posicao)
{
    return (posicao - 1) / 2;
}

int GetSucessorEsq(Heap* h, int posicao)
{
    return (2 * posicao + 1);
}

int GetSucessorDir(Heap* h, int posicao)
{
    return (2 * posicao + 2);
}

int Vazio(Heap* h)
{
    return h->tamanho == 0;
}

void HeapifyPorBaixo(Heap* h, int posicao)
{
    int menor = posicao; // posicao inicial eh o menor
    int esq = GetSucessorEsq(h, posicao); 
    int dir = GetSucessorDir(h, posicao);

    if (esq < h->tamanho && h->dados[esq] < h->dados[menor]) menor = esq; // verifica se o esquerdo existe e eh menor que o atual
    if (dir < h->tamanho && h->dados[dir] < h->dados[menor]) menor = dir; // verifica se o direito existe e eh menor que o atual e o esq

    // se posicao atual nao eh menor, troca e continua verificando
    if (menor != posicao)
    {
        // troca pos atual e menor filho
        int temp = h->dados[posicao];
        h->dados[posicao] = h->dados[menor];
        h->dados[menor] = temp;

        // corrige heap na subarvore
        HeapifyPorBaixo(h, menor);
    }
}

void HeapifyPorCima(Heap* h, int posicao)
{
    // enquanto nao for a raiz
    while (posicao > 0)
    {
        // calcula indice do ancestral
        int pai = GetAncestral(h, posicao);

        // se elemento atual eh menor que ancestral, troca
        if (h->dados[posicao] < h->dados[pai])
        {
            int temp = h->dados[posicao];
            h->dados[posicao] = h->dados[pai];
            h->dados[pai] = temp;

            // atualiza posicao para a do pai
            posicao = pai;

            // heap esta garantido
        } else break;
    }
}
