#include "goodtimes.h"

#include <time.h>


int main() {
    srand(time(NULL));
    Node* head = make_node(21, make_node(34, make_node(57, make_node(82, NULL))));
    printf("A lista possui %d elementos\n", count_nodes(head));
    print_even(head);
    printf("\n");
    print_list(head);
    printf("\n");
    Node* N2 = aleatorios(20);
    print_list(N2);
    free_list(head);
}
