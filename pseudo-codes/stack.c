#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Stack
{
    int * arr;
    int top;
    int length;
} Stack;

Stack *CreateStack(int l)
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if (s==NULL) exit(1);

    s->length = l;
    s->top = 0;

    s->arr = (int*)malloc(l * sizeof(int));

    return s;
}

bool EmptyStack(Stack *s)
{
    if (s->top == 0) return true;
    else return false;
}

void Push(Stack *s, int x)
{
    if (s->top==s->length) exit(1); // overflow

    s->top++;
    s->arr[s->top] = x;
}

int Pop(Stack *s)
{
    if (EmptyStack(s)) 
    {
        return -1; // underflow
    }
    
    else
    {
        s->top--;
        return s->arr[s->top+1];
    }
}


