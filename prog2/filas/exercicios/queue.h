
#ifndef ESTUDOS_QUEUE_H
#define ESTUDOS_QUEUE_H

#pragma once
#include <stdbool.h>

typedef struct Queue Queue;

Queue* init_queue(unsigned tam_elem);
#define INIT_QUEUE(T) init_queue(sizeof(T))

void free_queue(Queue* Q);

bool is_empty_queue(Queue* Q);

void* front(Queue* Q);

void enqueue(Queue* Q, void* x);

void dequeue(Queue* Q);



#endif //ESTUDOS_QUEUE_H
