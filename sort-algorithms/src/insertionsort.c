#include "../include/insertionsort.h"

#include <stdio.h>

void insertion_sort(int *arr, int n) {
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        // insert A[i] into the sorted subarray A[1:i-1]
        j = i - 1;
        
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        printf("Array em ordenacao: ");
        for (int x = 0; x < n; x++)
        {
            printf("%d ", arr[x]);
        }
    }
}