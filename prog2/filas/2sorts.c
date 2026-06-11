#include <stdio.h>
#include <stdlib.h>

void insertionsort(int arr[], int n ) {
    for (int i = 0; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selectionsort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
        int aux = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = aux;
    }
}