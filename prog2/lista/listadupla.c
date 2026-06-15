#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
}Node;



// criar no dinamicamente

Node* new_item(char c) {
    Node* node = malloc(sizeof(Node));
    node->data = c;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// inserir item na frente da fila

Node* push_front(Node* head, int n) {
    Node* new_head = new_item(n);
    if (head == NULL) {
        return new_head;
    }
    new_head->next = head;
    head->prev = new_head;
    return new_head;
}

//remover do inicio fa lista

Node* pop_front(Node* head) {
    if (head==NULL) {
        return NULL;
    }
    Node* new_head = head->next;
    if (new_head != NULL)
        new_head->prev = NULL;

    free(head);
    return new_head;
}