#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define MAXSIZE 1024
#include "char_stack.h"
#include <stdlib.h>

struct Stack {
    char data[MAXSIZE];
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

char top(Stack* S) {
    assert(!is_empty(S));
    return S->data[S->n-1];
}

void push(Stack* S, char x) {
    assert(S->n < MAXSIZE);
    S->data[S->n++] = x;
}

void pop(Stack* S) {
    assert(!is_empty(S));
    S->n--;
}


