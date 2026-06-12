
#define MAXSIZE 5
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int vector[MAXSIZE];  //tam da fila
    int end;
} Queue;


Queue* queue_init() {
    Queue* Q = malloc(sizeof(Queue));
    Q->end = 0;
    return Q;
}

void enqueue(Queue* Q, int x) {
    assert(Q->end < MAXSIZE);
    Q->vector[Q->end++] = x;
}

void dequeue (Queue* Q) {
    //assert(Q->end == 0);
    for (int i = 0; i < Q->end -1; i++) {
        Q->vector[i] = Q->vector[i+1];
    }
    Q->end--;
}

int isfull(Queue* Q) {
    return Q->end >= MAXSIZE;
}

int isempty(Queue* Q) {
    return Q->end == 0;
}

void printq(Queue* Q) {
    for (int i = Q->end -1; i >= 0; i--) {
        printf(" %d", Q->vector[i]);
    }
}

void printq1(Queue* Q) {
    for (int i = 0; i < Q->end; i++) {
        printf(" %d", Q->vector[i], i);
    }
}
void free_queue(Queue* Q) {
    free(Q);
}

int main() {
    Queue* Q = queue_init();
    enqueue(Q, 15);
    enqueue(Q, 12);
    enqueue(Q, 17);
    enqueue(Q, 20);
    enqueue(Q, 1);
    printq1(Q);
    printf("\n");
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    printq1(Q);
    printf("\n");
    printf("%d", isempty(Q));
    printf("\n");
    printf("%d", isfull(Q));

    free_queue(Q);
}


