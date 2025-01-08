#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
} DoublyLinkedList;

// Insere um elemento no inicio da lista
void BeginningInsert(DoublyLinkedList *List, Node x)
{
    x.next = List->head;

    // Checa se a lista está vazia primeiro
    if (List->head != NULL) List->head->prev = &x;
    List->head = &x;
    x.prev = NULL;
}

// Insere um elemento no final da lista
void EndInsert(DoublyLinkedList *List, Node x)
{
    x.prev = List->tail;

    // Checa se a lista está vazia primeiro
    if (List->tail != NULL) List->tail->next = &x;
    List->tail = &x;
    x.next = NULL;
}

Node *ListSearch(DoublyLinkedList *List, int k)
{
    Node *x = List->head;
    while (x != NULL && x->key != k) x = x->next;
    return x;
}

void DeleteFirst(DoublyLinkedList *List)
{
    if (List->head != NULL) 
    {
        List->head = List->head->next;
        List->head->prev = NULL;
    }
}

void DeleteLast(DoublyLinkedList *List)
{
    if (List->tail != NULL)
    {
        List->tail = List->tail->prev;
        List->tail->next = NULL;
    }
}

void PrintList(DoublyLinkedList *List)
{
    Node *x = List->head;
    while (x != NULL)
    {
        printf("%d\n", x->key);
        x = x->next;
    }
    free(x);
}

int main()
{
    // pass


    return 0;
}