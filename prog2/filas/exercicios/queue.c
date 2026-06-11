#include "queue.h"
#include "vector.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Queue{
    Vector* V;
    int begin;
};

Queue* init_queue(unsigned tam_elem){
    Queue* Q = malloc( sizeof(Queue) );
    Q->V = init_vector(tam_elem);
    Q->begin = 0;
    return Q;
}

void free_queue(Queue* Q){
    free_vector(Q->V);
    free(Q);
}

bool is_empty_queue(Queue* Q){
    return Q->begin >= vector_size(Q->V);
}

void* front(Queue* Q){
    assert(!is_empty_queue(Q));
    return vector_element(Q->V, Q->begin);
}

void enqueue(Queue* Q, void* x){
    push_back(Q->V, x);
}

void adjust_elements(Queue* Q){
    int n = vector_size(Q->V);
    int queue_size = n - Q->begin;

    if(queue_size > 0 && Q->begin >= queue_size){
        void* v = vector_data(Q->V);
        unsigned elem_size = vector_element(Q->V, 1) - v;
        memcpy(v, vector_element(Q->V, Q->begin), queue_size*elem_size);
        for(int i = 0; i < n-queue_size; i++)
            pop_back(Q->V);

        Q->begin = 0;
    }
}

void dequeue(Queue* Q){
    // Certifica-se de que a fila não está vazia.
    assert(!is_empty_queue(Q));

    // Atualiza a posição de início da fila.
    Q->begin++;

    // Ajusta os elementos.
    adjust_elements(Q);
}