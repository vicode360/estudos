#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000




void insertionSort(long int arr[], int n) {
    for (long int i = 1; i < n; i++) {
        long int key = arr[i];
        long int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    srand(time(NULL));

   long int arr[SIZE];
    for (long int j = 0; j < SIZE; j++) {
        arr[j] = rand() % SIZE;
    }
    insertionSort(arr, SIZE);
    printf("\n");
    for (long int i = 0; i < SIZE; i++) {
        printf(" %d: %d", arr[i]);
    }

    for (int i = 0; i < SIZE; i++) {
        int key = arr[i];

    }
}