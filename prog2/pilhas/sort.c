#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int esquerda, int meio, int direita) {
    int i = esquerda;
    int j = meio + 1;
    int k = esquerda;

    int temp[direita+1];

    while (i <= meio && j <= direita) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        }else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }


}


void mergeSort(int arr[], int esquerda, int direita) {
    if (esquerda<direita) {
        int meio = (esquerda + direita)/2;
        mergeSort(arr, esquerda, meio);
        mergeSort(arr, meio + 1, direita);
        merge(arr, esquerda, meio, direita);
    }
}



int main() {

}