#include "src/insertionsort.c"

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);
    
    printf("O array ordenado eh:\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}