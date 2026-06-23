


#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.c"


struct Stack {
    Vector* v;
};

Stack* init_stack(int elem_size) {
    Stack* S = malloc(sizeof(Stack));
    S->v = new_vector(elem_size);
}

void free_stack(Stack* S) {
    free_vector(S->v);
    free(S);
}

bool is_empty(Stack* S) {
    if (S->v->size == 0) {
        return true;
    }
}

void* top(Stack* S) {
    assert(!is_empty);
    return element_at(S->v, S->v->size-1);
}

void push(Stack* S, void* x) {
    push_back(S->v, x);
}

void pop(Stack* S) {
    assert(!is_empty);
    pop_back(S->v);
}

