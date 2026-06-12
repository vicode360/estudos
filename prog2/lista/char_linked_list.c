#include <stdio.h>
#include "char_linked_list.h"


int main() {
    Node* head = NULL;
    head = push_front(head, 'A');
    head = push_front(head, 'B');
    head = push_front(head, 'C');

    printnodes(head);
}
