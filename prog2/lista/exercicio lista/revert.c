#include "goodtimes.h"


int main(){
    srand(time(NULL));
    Node* head = aleatorios(10);
    printf("Antes: ");
    print_list(head);
    head = revert_list(head);
    printf("Depois: ");
    print_list(head);
    free_list(head);
}
