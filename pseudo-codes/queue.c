/***
 * Question 10.1-5 from Cormen's 3rd edition
 * 
 * Whereas a stack allows insertion and deletion of elements at 
 * only one end, and a queue allows insertion at one end and deletion
 * at the other end, a deque (double ended queue) allows insertion 
 * and deletion at both ends. Write four O(1)-time procedures to 
 * insert elements into and delete elements from both ends of a deque 
 * implemented by an array.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // max size of array

typedef struct
{
    int data[MAX_SIZE]; // elements of deque
    int front;          // start of deque index
    int rear;           // end of deque index
    int size;           // current size of deque
} Deque;

// initialize deque
void initializeDeque(Deque *dq)
{
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

// check if deque is full
int isFull(Deque *dq)
{
    return dq->size == MAX_SIZE;
}

// check if deque is empty
int isEmpty(Deque *dq)
{
    return dq->size == 0;
}

void insertFront(Deque *dq, int value)
{
    
}
