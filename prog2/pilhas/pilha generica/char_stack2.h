#ifndef ESTUDOS_CHAR_STACK2_H
#define ESTUDOS_CHAR_STACK2_H

typedef struct Stack Stack;

Stack* init_stack;

void free_stack(Stack* S);

bool is_empty(Stack* S);

char top(Stack* S);

void push(Stack* S, char x);

void pop(Stack* S);




#endif //ESTUDOS_CHAR_STACK2_H
