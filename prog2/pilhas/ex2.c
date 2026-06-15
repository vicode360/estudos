//
// Created by Victor Iorio on 15/06/26.
//


#include <stdio.h>
#include <stdlib.h>

typedef struct Frame {
    int pos;
    int x;
    struct Frame* next;
}Frame;

Frame *push(int x, Frame *top) {
    Frame* new_top = malloc(sizeof(Frame));
    new_top->next = top;
    new_top->pos = 0;
    new_top->x = x;
}

Frame* pop(Frame* top) {
    Frame* new_top = top->next;
    free(top);
    return new_top;
}

void f(int x) {
    Frame* top = push(x, NULL);
    while(top) {
     if (top->x < 1) {
         top = pop(top);
     }else {
         if (top->pos == 0) {
             printf("A");
             top->pos++;
             top = push(x-2, top);
         }
         else if (top->pos == 1) {
             printf("B");
             top->pos++;
             top = push(x-2, top);
         }
         else {
             printf("C");
             top = pop(top);
         }
     }
    }
}