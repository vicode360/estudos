#include "queue.c"
#include <stdio.h>

#include "queue.h"


Queue* vetor_para_fila(int v[], int n) {
    Queue* Q = INIT_QUEUE(int);
    for (int i = 0; i < n; i++) {
        enqueue(Q, &v[i]);
    }
    return Q;
}

Queue* concatena(Queue* Q1, Queue* Q2) {
    Queue* Q3 = INIT_QUEUE(int);
    while (!is_empty_queue(Q1)) {
        void* element = front(Q1);
        enqueue(Q3, element);
        dequeue(Q1);
    }
    while (!is_empty_queue(Q2)) {
        void* element = front(Q2);
        enqueue(Q2, element);
        dequeue(Q2);
    }
}

int main() {
    int v1[4] = {3, 5, 4, 8};
    Queue* Q1 = vetor_para_fila(v1, 4);

    int v2[2] = {7, 2};
    Queue* Q2 = vetor_para_fila(v2, 2);

    Queue* Q3 = concatena(Q1, Q2);

    while(!is_empty_queue(Q3)){
        int* p = front(Q3);
        printf("%d ", *p);
        dequeue(Q3);
    }

    free_queue(Q1);
    free_queue(Q3);
    free_queue(Q2);
}
