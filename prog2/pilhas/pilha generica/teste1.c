//
// Created by Victor Iorio on 15/06/26.
//


#include <stdio.h>
#include <stdlib.h>


typedef struct Stack {
    Vector* vec;
}Stack;

Stack* init_stack(int elem_size) {
    Stack* S = malloc(sizeof(Stack));
    S->vec = INIT_STACK(elem_size);
    return S;
}

void free_stack(Stack* S) {
    free_vector(S->vec);
    free(S);
}

bool is_empty(Stack* S) {
    return vector_size(S->vec) == 0;
}

void* top(Stack* S) {
    assert(!is_empty(S));
    int n = vector_size(S->vec);
    void* data = vector_data(S->vec);
    return &data[n-1];
}

void push(Stack* S, void* x) {
    push_back(S->vec, x);
}

void pop(Stack* S) {
    pop_back(S->vec);
}


typedef struct Frame {
    int x;
    int pos;
    struct Frame* next;
};






