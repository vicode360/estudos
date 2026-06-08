#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include "char_queue.h"

#define MAXSIZE 1024


struct Queue {
    char data[MAXSIZE]; // vetor para armazenar os elementos da fila
    int n;              // numero de elementos inseridos
    int begin;          // primeiro elemento da fila
    int end;            // final da fila (prox posicao disponuvekl)
};

Queue* init_queue() {
    Queue* Q = malloc(sizeof(Queue));
    Q->n = 0;
    Q->begin = 0;
    Q->end = 0;
    return Q;
}

void free_queue(Queue* Q) {
    free(Q);
}

bool is_empty(Queue* Q) {
    return Q->end == 0;
}

char front(Queue *Q) {
    assert(!is_empty(Q));
    return Q->data[Q->begin];
}

void dequeue(Queue* Q) {
    assert(!is_empty(Q));
    Q->n--;
    Q->begin = (Q->begin+1)%MAXSIZE;
}

void enqueue(Queue* Q, char x) {
    assert(Q->n < MAXSIZE);
    Q->data[Q->end] = x;
    Q->n++;
    Q->end = (Q->end+1)%MAXSIZE;

}

