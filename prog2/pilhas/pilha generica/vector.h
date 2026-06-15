#ifndef ESTUDOS_VECTOR_H
#define ESTUDOS_VECTOR_H

#pragma once

typedef struct Vector Vector;

Vector* init_vector(unsigned elem_size);
#define INIT_VECTOR(T) init_vector(sizeof(T))

void free_vector(Vector* vec);

unsigned vector_size(Vector* vec);

void* vector_data(Vector* vec);

void push_back(Vector* vec, void* x);

void pop_back(Vector* vec);

void* vector_element(Vector* vec, unsigned i);




#endif //ESTUDOS_VECTOR_H
