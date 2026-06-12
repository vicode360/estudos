#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

int main() {
    Node A = {'A', NULL};
    Node B = {'B', &A};
    Node C = {'C', &B};
    Node* head = &C;

    Node* p = head;
    while (p != NULL) {
        printf(" %c", p->data);
        p = p->next;
    }

}