#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int n;
    int* next;
} Element;

int main() {
    Element* M[] = malloc(4*sizeof(Element));
    M[0].n = 3;
    M[0].next = malloc(3*sizeof(int));
    M[0].next[0] = 10;
    M[0].next[1] = 23;
    M[0].next[2] = 45;
    for (int i = 0; i < 4; i++) {
        printf("%d -> {", M[i].n);
        for (int j = 0; j < M[i].n; j++) {
            printf("%d, ", M[i].next[j]);
        }
        printf("}");
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < M[i].n; j++) {
            free(M[i].next[j]);
        }
        free(M[i]);
    }
}