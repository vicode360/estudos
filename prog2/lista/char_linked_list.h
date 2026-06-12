#ifndef ESTUDOS_CHAR_LINKED_LIST_H
#define ESTUDOS_CHAR_LINKED_LIST_H

#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

static void printnodes(Node* head) {
    for (Node* p = head; p != NULL; p = p->next)
        printf("%c ", p->data);
}


// criar um no dinamicamente

static Node* new_node(char c) {
    Node* node = malloc(sizeof(Node));
    node->data = c;
    node->next = NULL;
    return node;
}

// inserir item na frente da lista

static Node* push_front(Node* head, char c) {
    Node* new_head = new_node(c);
    new_head->next = head;
    return new_head;
}

// remover item da frente da lista

static Node* pop_front(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* new_head = head->next;
    free(head);
    return new_head;

}







#endif //ESTUDOS_CHAR_LINKED_LIST_H
