#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
} LinkedList;

// Método de força bruta para encontrar o k-ésimo elemento a partir do fim
Node *BruteForce(LinkedList *List, int k)
{
    Node *current = List->head;
    int length = 0;

    // Contar o número de nós na lista
    while (current != NULL)
    {
        length++;
        current = current->next;
    }

    // Verificar se k é válido
    if (k > length || k <= 0)
        return NULL;

    // Encontrar o (length - k)-ésimo nó
    current = List->head;
    for (int i = 0; i < length - k; i++)
    {
        current = current->next;
    }

    return current;
}
int main()
{
    // pass
    return 0;
}