//
// Created by Victor Iorio on 15/06/26.
//


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "char_stack.h"

#define SIZE = 1024

typedef struct Stack {
    char data[SIZE];
    int n;
};

Stack* init_stack() {
    Stack* S = malloc(sizeof(Stack));
    S->n = 0;
    return S;
}

void free_stack(Stack* S) {
    free(S);
}

bool is_empty(Stack* S) {
    return S->n == 0;
}

void push(Stack* S, char x) {
    assert(S->n < SIZE);
    S->data[S->n++] = x;
}

void pop(Stack* S) {
    assert(!is_empty(S));
    S->n--;
}

char top(Stack* S) {
    assert(!is_empty(S));
    return S->data[S->n-1];
}

void printS(Stack* S) {
    assert(!is_empty(S));
    for (int i = 0; i < S->n; i++) {
        printf("%c ", S->data[i]);
    }
}