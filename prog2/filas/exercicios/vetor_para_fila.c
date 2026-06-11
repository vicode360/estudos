#include "../queue.c"
#include <stdio.h>


Queue* vetor_para_fila(int v[], int n) {
    Queue* Q = INIT_QUEUE(int);
    for (int i = 0; i < n; i++) {
        enqueue(Q, &v[i]);
    }
    return Q;
}


int main() {
    int v[4] = {3, 5, 4, 8};
    Queue* Q = vetor_para_fila(v, 4);

    while(!is_empty_queue(Q)){
        int* p = front(Q);
        printf("%d ", *p);
        dequeue(Q);
    }

    free_queue(Q);
}

