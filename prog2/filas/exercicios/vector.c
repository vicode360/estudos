#include "vector.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Vector{
    unsigned elem_size;
    unsigned size;
    unsigned capacity;
    void* data;
};

Vector* init_vector(unsigned elem_size){
    Vector* V = malloc(sizeof(Vector));
    V->elem_size = elem_size;
    V->size = 0;
    V->capacity = 1;
    V->data = malloc(elem_size);
    return V;
}

void free_vector(Vector* vec){
    free(vec->data);
    free(vec);
}

unsigned vector_size(Vector* vec){
    return vec->size;
}

void* vector_data(Vector* vec){
    return vec->data;
}

void pop_back(Vector* vec){
    assert(vec->size > 0);
    vec->size--;
}

void push_back(Vector* vec, void* x){
    if(vec->size == vec->capacity){
        // Opa! Preciso de mais memória
        vec->capacity *= 2;
        vec->data = realloc(vec->data, vec->capacity*vec->elem_size);
    }
    void* back = vector_element(vec, vec->size);
    memcpy(back, x, vec->elem_size);
    vec->size++;
}

void* vector_element(Vector* vec, unsigned i){
    return (char*)vec->data + i*vec->elem_size;
}

