#include <assert.h>
#include <stdlib.h>
#include "char_stack2.h"

#include <stdbool.h>

#include "vector.h"

struct Stack {
    Vector* vec;

};

Stack* init_stack() {
    Stack* S = malloc(sizeof(Stack));
    S->vec = INIT_VECTOR(char);
    return S;
}

void free_stack(Stack* S) {
    free_vector(S->vec);
    free(S);
}

bool is_empty(Stack* S) {
    return vector_size(S->vec) == 0;
}

char top(Stack *S) {
    assert(!is_empty(S));
    int n = vector_size(S->vec);
    char* data = vector_data(S->vec);
    return data[n-1];
}

void push(Stack* S, char x) {
    push_back(S->vec, &x);
}

void pop (Stack* S) {
    pop_back(S->vec);
}




