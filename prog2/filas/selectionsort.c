
#include <stdio.h>

void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;

}

void selectionsort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
     int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int v[10] = {10, 8, 3, 2, 5, 4, 1, 7, 6, 9};
    for (int i = 0; i < 10; i++) {
        printf(" %d", v[i]);
    }
        printf("\n");
    selectionsort(v, 10);

    for (int i = 0; i < 10; i++) {
        printf(" %d", v[i]);
    }

}