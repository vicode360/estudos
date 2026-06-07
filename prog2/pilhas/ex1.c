#include "char_stack.c"
#include <stdio.h>

int main() {
    Stack* S2 = init_stack();
    push(S2, 'E');
    push(S2, 'F');
    push(S2, 'G');
    push(S2, 'H');
    prints(S2);

    Stack* aux = init_stack();
    Stack* aux2 = init_stack();

    for (int i = S2->n-1; i>=1; i--) {
        push(aux, top(S2));
        pop(S2);
    }
    push(aux2, top(S2));
    pop(S2);
    for (int i = aux->n-1; i>=0; i--) {
        push(S2, top(aux));
        pop(aux);
    }
    push(S2, top(aux2));
    printf("\n");
    prints(S2);

    free_stack(aux2);
    free_stack(S2);
    free_stack(aux);
}