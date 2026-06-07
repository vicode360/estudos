#include "char_stack.c"
#include <stdio.h>

int main() {
    Stack* S2 = init_Stack();
    push(S2, 'E');
    push(S2, 'F');
    push(S2, 'G');
    push(S2, 'H');

    Stack* S = init_Stack();
    push(S, 'A');
    push(S, 'B');
    push(S, 'C');

    char topo = top(*S2);
    
}